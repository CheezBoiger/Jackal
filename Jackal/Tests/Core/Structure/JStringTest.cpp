// Copyright (c) 2017 Jackal Engine, MIT License.
#include "JStringTest.hpp"
#include "Core/Internationalization/Locale.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Utility/JStringUtils.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Logging/TextBase.hpp"
#include <gtest/gtest.h>
#include <string>

#if JACKAL_PLATFORM == JACKAL_WINDOWS
#include "Core/Win32/Win32Window.hpp"
#include "OpenGLDevice/Win32/Win32OpenGL.hpp"
#include "OpenGLDevice/OpenGLDevice.hpp"
#endif

TEST(StructureTests, JStringTesting)
{
#if JACKAL_PLATFORM == JACKAL_WINDOWS
  jkl::InitWin32WindowLibs();
#endif
  jkl::Locale::SetLanguage(jkl::L_JAPANESE);

  jkl::JString str(JTEXT("Testing simple string."));

  jkl::Log::MessageToStdOutput(jkl::LogVerbosity::LOG_NORMAL, str, true, JTEXT("Chicken")); 
  jkl::Log::MessageToStdOutput(jkl::LogVerbosity::LOG_NORMAL, jkl::JStringUtils::ToString(str.empty())); 

  jkl::Message *message = jkl::Log::GetStoredMessage(jkl::LOG_NORMAL, 0);

  jkl::Log::MessageToStdOutput(message->verbose, message->msg, false, message->tag);


  jkl::JString jstr(JTEXT("これは簡単なテストです。\n"));
  jkl::PrintToStdConsole(jstr);

#if JACKAL_PLATFORM == JACKAL_WINDOWS
  jkl::int32 width = 1440;
  jkl::int32 height = 800;

  jkl::Win32Window *window = jkl::CreateWin32Window(0, 0, width, height, 
    JTEXT("これは簡単なテストです。"), NULL);

  jkl::SetWin32WindowOpenGLContext(window);
  jkl::Win32WindowMakeContextCurrent(window);

  jkl::OpenGLDevice::InitOpenGL();  

  ASSERT_EQ(window->width, width);
  ASSERT_EQ(window->height, height);

  jkl::PrintToStdConsole(JTEXT("Press close to continue through."));

  // Game loop.
  while (!jkl::Win32WindowShouldClose(window)) {
    jkl::Win32SwapBuffers(window);
    jkl::Win32WindowPollEvents();
  }

  jkl::Win32WindowMakeContextCurrent(nullptr);
  jkl::DestroyWin32Window(window);
  jkl::CleanUpWin32WindowLibs();
#endif
}


namespace coretest {


void JStringTesting()
{
  // do nothing.
}
} // jstringtest
