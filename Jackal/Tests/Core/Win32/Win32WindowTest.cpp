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
  jkl::int32 width = 1440;
  jkl::int32 height = 800;

  jkl::Win32Window *window = jkl::Win32Window::Create(width, height,
    JTEXT("これは簡単なテストです。"), NULL);

  jkl::Win32OpenGL::SetOpenGLContext(window);
  jkl::Win32OpenGL::MakeContextCurrent(window);

  jkl::OpenGLDevice::InitOpenGL();

  //jkl::OpenGLDevice device;

  ASSERT_EQ(window->width, width);
  ASSERT_EQ(window->height, height);

  jkl::PrintToStdConsole(JTEXT("Press close to continue through."));

  // Game loop.
  while (!window->ShouldClose()) {
    jkl::Win32OpenGL::SwapWindowBuffers(window);
    jkl::Win32Window::PollEvents();
  }

  jkl::Win32OpenGL::MakeContextCurrent(nullptr);
  window->Destroy();
  jkl::Win32CleanUpWindowLibs();
#endif
}



namespace win32test {


void WindowTest()
{
}
} // win32test