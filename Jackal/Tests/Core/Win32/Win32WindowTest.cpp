// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Win32WindowTest.hpp"
#include "Core/Win32/Win32Window.hpp"
#include "Core/Win32/Win32Filesystem.hpp"
#include "Core/Utility/JStringUtils.hpp"
// OpenGL Testing as well.
#include "OpenGLDevice/OpenGLDevice.hpp"
#include "OpenGLDevice/Win32/Win32OpenGL.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLShader.hpp"
#include "OpenGLDevice/OpenGLCommandBuffer.hpp"
#include "OpenGLDevice/OpenGLSampler.hpp"
#include "OpenGLDevice/OpenGLRenderTarget.hpp"
#include <gtest/gtest.h>
#include "Core/Platform/Time.hpp"


TEST(Win32, Win32WindowTest)
{
#if JACKAL_PLATFORM == JACKAL_WINDOWS
  jackal::Win32OpenGL::Initialize();
  jackal::Time::StartTime();
  jackal::int32 width = 1440;
  jackal::int32 height = 800;
 
  jackal::PrintToConsole(JTEXT("Creating window.\n"));
  jackal::Win32Window *window = jackal::Win32Window::Create(width, height,
    JTEXT("これは簡単なテストです。"), NULL);
  jackal::Win32Window *window2 = jackal::Win32Window::Create(width, height,
    JTEXT("Nope"), NULL, true);
  window->SetToCenter();
  window->Show();
  //window2->Show();

  jackal::Win32OpenGL::SetOpenGLContext(window);
  jackal::Win32OpenGL::SetOpenGLContext(window2);
  jackal::Win32OpenGL::MakeContextCurrent(window);
  jackal::OpenGLDevice::InitOpenGL();
  // This device is used to render. Will be used by the 
  // renderer.
  jackal::OpenGLDevice device;

  jackal::UniformBuffer *buffer = device.CreateUniformBuffer();
  jackal::Matrix4 model[5];
  model[4][0][0] = 4.0f;
  jackal::Matrix4 view;
  jackal::Matrix4 projection;
  jackal::Vector3 camPosition;
  buffer->SetDataType(jackal::DATA_DYNAMIC);

  // Needs to be initialized in the same order as our ubo layout in glsl.
  buffer->SetMat4("model", model, 5);
  buffer->SetMat4("view", &view);
  buffer->SetMat4("projection", &projection);
  buffer->SetVec3("camPosition", &camPosition);

  // initialize ubo here. You need an active pipeline state in order to
  // initialize a uniform buffer.
  buffer->Initialize(0, "UBO");

  jackal::NativeString fSource = jackal::Shader::ParseFile("D:/Users/Magarcia/Github/Jackal/Jackal/Shaders/Test/GLSL/blinn-phong.frag");
  jackal::NativeString vSource = jackal::Shader::ParseFile("D:/Users/Magarcia/Github/Jackal/Jackal/Shaders/Test/GLSL/blinn-phong.vert");
  // Creat e shaders for our pipeline.
  jackal::OpenGLShader vShader;
  jackal::OpenGLShader pShader;

  // TODO(): Need to set the current directory look up with test shaders.
  vShader.Compile(jackal::Shader::Vertex, vSource);
  pShader.Compile(jackal::Shader::Pixel, fSource);

  jackal::GraphicsPipelineState *BlinnPhongPipe =
    device.CreateGraphicsPipelineState();

  jackal::VertexAttributeT attributes[2];
  attributes[0].Binding = 0;
  attributes[0].Location = 0;
  attributes[0].Format = jackal::FORMAT_R32G32B32_SFLOAT;
  attributes[0].Offset = 0;

  attributes[1].Binding = 0;
  attributes[1].Location = 1;
  attributes[1].Format = jackal::FORMAT_R32G32B32_SFLOAT;
  attributes[1].Offset = sizeof(jackal::real32);

  // Set up information about the pipeline.
  jackal::GraphicsPipelineInfoT information;
  information.Topology = jackal::TOPOLOGY_TRIANGLE_LIST;
  information.BlendEnable = false;
  information.BlendOp = jackal::BlendOperationT::BLEND_OPERATION_ADD;
  information.CullFaceEnable = true;
  information.CullMode = jackal::CULL_MODE_BACK;
  information.DepthTestCompare = jackal::CompareT::COMPARE_LESS;
  information.FrontFace = jackal::FrontFaceT::FRONT_FACE_COUNTER_CLOCKWISE;
  information.VertexShader = &vShader;
  information.PixelShader = &pShader;
  information.HullShader = nullptr;
  information.DomainShader = nullptr;
  information.GeometryShader = nullptr;
  information.Layout = nullptr;

  information.VertexBindingInfo.VertexAttribute = attributes;
  information.VertexBindingInfo.VertexAttributesCount = 2;
  information.VertexBindingInfo.Binding = 0;
  information.VertexBindingInfo.InputRate;
  information.VertexBindingInfo.Stride = sizeof(jackal::real32) * 6;

  BlinnPhongPipe->Bake(information);

  jackal::uint32 offset = sizeof(jackal::Matrix4) * 4;
  buffer->Update(&offset);

  vShader.CleanUp();
  pShader.CleanUp();

  jackal::SamplerInfoT sinfo;
  sinfo.MagFilter = jackal::FILTER_MODE_NEAREST;
  sinfo.MinFilter = jackal::FILTER_MODE_NEAREST;
  sinfo.WrapS = jackal::WRAP_MODE_CLAMP_TO_BORDER;
  sinfo.WrapT = jackal::WRAP_MODE_CLAMP_TO_BORDER;
  sinfo.WrapR = jackal::WRAP_MODE_CLAMP_TO_BORDER;
  sinfo.MinLod = 1.0f;
  sinfo.MaxLod = 2.0f;
  jackal::OpenGLSampler sampler;
  sampler.Bake(sinfo);

  jackal::CommandBuffer *cmd = device.CreateCommandBuffer();
  // Record buffer.
  cmd->Record();
    cmd->BeginRenderPass(nullptr);
    cmd->BindGraphicsPipelineState(BlinnPhongPipe);
#if 0
    // NOTE(): Once we get out material layout set up, we will enable this.
    cmd->BindMaterialLayout(nullptr, 1, nullptr);
    cmd->BindVertexBuffer(nullptr);
    cmd->DrawElements(0);

    cmd->BindMaterialLayout(nullptr, 1, nullptr);
    cmd->BindVertexBuffer(nullptr);
    cmd->DrawElements(0);
#endif
    cmd->Clear();
    cmd->ClearColor(jackal::Colorf(0.1f, 0.1f, 0.1f, 1.0f));
  cmd->EndRecord();

  jackal::RenderTargetCreateInfoT ri;
  ri.Format = jackal::FORMAT_R32G32B32A32_SFLOAT;
  ri.HardwareMSAA = false;
  ri.MSAA = jackal::SAMPLE_COUNT_1_BIT;
  ri.Width = 1920;
  ri.Height = 1080;
  jackal::OpenGLRenderTarget renderTarget;
  renderTarget.Bake(ri);
  ASSERT_EQ(window->width, width);
  //ASSERT_EQ(window->height, height);

  jackal::PrintToConsole(JTEXT("Press close to continue through.\n"));

  // Game loop.
  while (!window->ShouldClose()) {
    jackal::Time::UpdateDelta();
    // VR Demands two texture quads for each eye. In doing so,
    // we can either create one window, and render onto two quads
    // with warped texture stereoscopic view, or two windows using
    // virtual cameras for both eyes and rendering in their perspective.
    jackal::Win32OpenGL::MakeContextCurrent(window);
    device.SubmitCommandBuffers(cmd, 1);
    jackal::Win32OpenGL::SwapBuffers(window);

    jackal::Win32OpenGL::MakeContextCurrent(window2);    
    device.SubmitCommandBuffers(cmd, 1);
    jackal::Win32OpenGL::SwapBuffers(window2);
    jackal::Win32Window::PollEvents();
    std::cout << "Time: " << jackal::Time::Current() << " ms\r";
  }

  device.DestroyCommandBuffer(cmd);
  device.DestroyGraphicsPipelineState(BlinnPhongPipe);
  device.DestroyUniformBuffer(buffer);

  jackal::Win32OpenGL::MakeContextCurrent(nullptr);
  window->CleanUp();
  window2->CleanUp();
  delete window;
  delete window2;
  jackal::Win32OpenGL::CleanUp();
  jackal::Win32CleanUpWindowLibs();
#endif
}



namespace win32test {


void WindowTest()
{
}
} // win32test