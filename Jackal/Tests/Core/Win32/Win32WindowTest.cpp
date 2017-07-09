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
  window->SetToCenter();
  window->Show();

  jackal::Win32OpenGL::SetOpenGLContext(window);
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
    jackal::Win32OpenGL::SwapWindowBuffers(window);

    // Render here...

    jackal::Win32Window::PollEvents();
  }

  jackal::Win32OpenGL::MakeContextCurrent(nullptr);
  window->CleanUp();
  delete window;
  jackal::Win32OpenGL::CleanUp();
  jackal::Win32CleanUpWindowLibs();
#endif
}



namespace win32test {


void WindowTest()
{
}
} // win32test