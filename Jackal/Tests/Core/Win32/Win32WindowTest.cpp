// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Win32WindowTest.hpp"
#include "Core/Win32/Win32Window.hpp"
#include "Core/Win32/Win32Filesystem.hpp"

// OpenGL Testing as well.
#include "OpenGLDevice/OpenGLDevice.hpp"
#include "OpenGLDevice/Win32/Win32OpenGL.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLShader.hpp"
#include "OpenGLDevice/OpenGLCommandBuffer.hpp"

#include <gtest/gtest.h>



TEST(Win32, Win32WindowTest)
{
#if JACKAL_PLATFORM == JACKAL_WINDOWS
  jackal::Win32OpenGL::Initialize();
  jackal::int32 width = 1440;
  jackal::int32 height = 800;
 
  jackal::PrintToConsole(JTEXT("Creating window.\n"));
  jackal::Win32Window *window = jackal::Win32Window::Create(width, height,
    JTEXT(L"これは簡単なテストです。"), NULL);
  jackal::Win32Window *window2 = jackal::Win32Window::Create(width, height,
    JTEXT(L"Nope"), NULL);
  window->SetToCenter();
  window->Show();
  window2->Show();

  jackal::Win32OpenGL::SetOpenGLContext(window);
  jackal::Win32OpenGL::SetOpenGLContext(window2);
  jackal::Win32OpenGL::MakeContextCurrent(window);
  jackal::OpenGLDevice::InitOpenGL();
  // This device is used to render. Will be used by the 
  // renderer.
  jackal::OpenGLDevice device;

  jackal::JString fSource = jackal::Win32Filesystem::ReadFile("D:/Users/Magarcia/Github/Jackal/Jackal/Shaders/Test/GLSL/blinn-phong.frag");
  jackal::JString vSource = jackal::Win32Filesystem::ReadFile("D:/Users/Magarcia/Github/Jackal/Jackal/Shaders/Test/GLSL/blinn-phong.vert");
  jackal::PrintToConsole(vSource);

  // Creat e shaders for our pipeline.
  jackal::OpenGLShader vShader;
  jackal::OpenGLShader pShader;

  // TODO(): Need to set the current directory look up with test shaders.
  vShader.Compile(jackal::Shader::Vertex, vSource);
  pShader.Compile(jackal::Shader::Pixel, fSource);

  jackal::OpenGLGraphicsPipelineState pipe;
  pipe.SetName(JTEXT("Blinn-Phong Pipe."));
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

  pipe.Bake(information);


  jackal::OpenGLUniformBuffer buffer;
  buffer.SetMat4("model",       jackal::Matrix4(5.0));
  buffer.SetMat4("view",        jackal::Matrix4());
  buffer.SetMat4("projection",  jackal::Matrix4());
  buffer.SetVec3("camPosition", jackal::Vec3());

  jackal::Matrix4 model = buffer.GetMat4("model");

  for (jackal::uint32 i = 0; i < 4; ++i) {
    for (jackal::uint32 j = 0; j < 4; ++j) {
      std::cout << model[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  // initialize ubo here. You need an active pipeline state in order to
  // initialize a uniform buffer.
  buffer.Initialize(&pipe, 0, "UBO");

  vShader.CleanUp();
  pShader.CleanUp();

  jackal::OpenGLCommandBuffer cmd(&device);
  // Record buffer.
  cmd.Record();
    cmd.BindGraphicsPipelineState(&pipe);

    cmd.Clear();
    cmd.ClearColor(jackal::Colorf(0.1f, 0.1f, 0.1f, 1.0f));
  cmd.EndRecord();
  ASSERT_EQ(window->width, width);
  ASSERT_EQ(window->height, height);

  jackal::PrintToConsole(JTEXT("Press close to continue through."));

  // Game loop.
  while (!window->ShouldClose()) {

    // VR Demands two texture quads for each eye. In doing so,
    // we can either create one window, and render onto two quads
    // with warped texture stereoscopic view, or two windows using
    // virtual cameras for both eyes and rendering in their perspective.
    jackal::Win32OpenGL::MakeContextCurrent(window);

    device.SubmitCommandBuffers(&cmd, 1);

    jackal::Win32OpenGL::SwapBuffers(window);

    jackal::Win32OpenGL::MakeContextCurrent(window2);
    
    device.SubmitCommandBuffers(&cmd, 1);

    jackal::Win32OpenGL::SwapBuffers(window2);

    jackal::Win32Window::PollEvents();
  }

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