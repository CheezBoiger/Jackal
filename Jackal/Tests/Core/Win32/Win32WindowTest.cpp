// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Win32WindowTest.hpp"
#include "Core/Win32/Win32Window.hpp"

// OpenGL Testing as well.
#include "OpenGLDevice/OpenGLDevice.hpp"
#include "OpenGLDevice/Win32/Win32OpenGL.hpp"

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
  //jackal::OpenGLDevice device;

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

    // Render here...
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    jackal::Win32OpenGL::SwapWindowBuffers(window);

    jackal::Win32OpenGL::MakeContextCurrent(window2);
    // Render here...
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    jackal::Win32OpenGL::SwapWindowBuffers(window2);

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