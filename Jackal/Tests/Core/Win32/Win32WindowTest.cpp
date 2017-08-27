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
#include "OpenGLDevice/OpenGLRenderPass.hpp"
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
    JTEXT("これは簡単なテストです。"), false);
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
  device.Initialize();

  jackal::UniformBuffer *buffer = device.CreateUniformBuffer();
  jackal::Matrix4 model[5];
  model[4][0][0] = 4.0f;
  jackal::Matrix4 view;
  jackal::Matrix4 projection;
  jackal::Vector3 camPosition;

  // Needs to be initialized in the same order as our ubo layout in glsl.
  buffer->SetDataType(jackal::DATA_DYNAMIC);
  buffer->SetMat4("model", model, 5);
  buffer->SetMat4("view", &view);
  buffer->SetMat4("projection", &projection);
  buffer->SetVec3("camPosition", &camPosition);

  // initialize ubo here.
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
  attributes[1].Offset = sizeof(jackal::real32) * 3;

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
  sinfo.MaxAnisotropy = 1.0f;
  sinfo.AnisotropyEnable = true;
  sinfo.MipMapMode = jackal::SAMPLER_MIPMAP_MODE_LINEAR;
  sinfo.MinLod = 1.0f;
  sinfo.MaxLod = 2.0f;
  jackal::OpenGLSampler sampler;
  sampler.Bake(sinfo);

  jackal::CommandBuffer** swapBuffers = nullptr; 
  jackal::uint16 swapCount = 0;
  swapBuffers = device.SwapChainCommandBuffers(&swapCount);
  jackal::CommandBuffer *cmd = swapBuffers[0];
  // Record buffer.
  cmd->Record();
    //cmd->BeginRenderPass(nullptr);
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
    cmd->ClearColor(jackal::Color(50, 50, 50, 255));
  cmd->EndRecord();

  jackal::CommandBuffer* cmd2 = swapBuffers[1];
  cmd2->Record();
    //cmd2->BeginRenderPass(nullptr);
    cmd2->BindGraphicsPipelineState(BlinnPhongPipe);
    cmd2->Clear();
    cmd2->ClearColor(jackal::Color(255, 255, 255, 255));
  cmd2->EndRecord();


  // TODO(): The Design of rendertargets to renderpasses info is a bit
  // too much... need to make it a little more convenient...
  jackal::RenderTargetCreateInfoT ri;
  ri.Format = jackal::FORMAT_R32G32B32A32_SFLOAT;
  ri.HardwareMSAA = false;
  ri.MSAA = jackal::SAMPLE_COUNT_1_BIT;
  ri.Width = 1920;
  ri.Height = 1080;
  jackal::OpenGLRenderTarget renderTarget;
  renderTarget.Bake(ri);

  jackal::RenderPassAttachment attachment;
  attachment.PRenderTarget = &renderTarget;
  attachment.Samples = jackal::SAMPLE_COUNT_1_BIT;
  attachment.Format = jackal::FORMAT_R16G16B16A16_SFLOAT;
  attachment.LoadOp = jackal::ATTACHMENT_LOAD_OP_DONT_CARE;
  attachment.StoreOp = jackal::ATTACHMENT_STORE_OP_DONT_CARE;

  jackal::RenderPassAttachmentReference colorref;
  colorref.Attachment = 0;
  colorref.Layout = jackal::IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

  jackal::RenderPassAttachmentReference depthref;
  depthref.Attachment = 1;
  depthref.Layout = jackal::IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

  jackal::SubPass subpass;
  subpass.BindPoint = jackal::BIND_POINT_GRAPHICS;
  subpass.ColorAttachmentCount = 1;
  subpass.PColorAttachments = &colorref;
  subpass.PDepthStencilAttachment = nullptr;

  // TODO(): RenderPass is the more important component here. Figure out a way
  // to store rendertargets into a render pass, and use them to create a framebuffer
  // from within, inside opengl and vulkan. Instead of having to create an explicit 
  // framebuffer.
  jackal::RenderPassCreateInfoT passinfo;
  passinfo.AttachmentCount = 1;
  passinfo.Attachments = &attachment;
  passinfo.SubPassCount = 1;
  passinfo.SubPasses = &subpass;
  jackal::RenderPass* renderpass = device.CreateRenderPass();
  renderpass->Initialize(passinfo);

  ASSERT_EQ(window->width, width);
  //ASSERT_EQ(window->height, height);
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
    device.SubmitCommandBuffers(cmd2, 1);
    jackal::Win32OpenGL::SwapBuffers(window2);
    jackal::Win32Window::PollEvents();
    std::cout << "Time: " << jackal::Time::Current() << " ms\r";

    if (device.GetLastError() != jackal::RENDER_ERROR_NONE) std::cout << "Error!\n";
  }

  device.DestroyCommandBuffer(cmd);
  device.DestroyCommandBuffer(cmd2);
  device.DestroyGraphicsPipelineState(BlinnPhongPipe);
  device.DestroyUniformBuffer(buffer);

  jackal::Win32OpenGL::MakeContextCurrent(nullptr);
  window->CleanUp();
  window2->CleanUp();
  delete window;
  delete window2;
  jackal::Win32OpenGL::CleanUp();
  jackal::Win32CleanUpWindowLibs();

  jackal::PrintToConsole(JTEXT("Press close to continue through.\n"));

#endif
}



namespace win32test {


void WindowTest()
{
}
} // win32test