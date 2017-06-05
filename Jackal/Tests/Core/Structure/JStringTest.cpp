// Copyright (c) 2017 Jackal Engine, MIT License.
#include "JStringTest.hpp"
#include "Core/Internationalization/Locale.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Utility/JStringUtils.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Logging/TextBase.hpp"
#include <gtest/gtest.h>
#include <string>

#if defined(_WIN32)
#include "Core/Win32/Win32Window.hpp"
#endif

TEST(StructureTests, JStringTesting)
{
#if defined(_WIN32)
  jkl::InitWin32WindowLibs();
#endif
  jkl::Locale::SetLanguage(jkl::J_JAPANESE);

  jkl::JString str(JTEXT("Testing simple string."));

  jkl::Log::MessageToStdOutput(jkl::LogVerbosity::LOG_NORMAL, str, true, JTEXT("Chicken")); 
  jkl::Log::MessageToStdOutput(jkl::LogVerbosity::LOG_NORMAL, jkl::JStringUtils::ToString(str.empty())); 

  jkl::Message *message = jkl::Log::GetStoredMessage(jkl::LOG_NORMAL, 0);

  jkl::Log::MessageToStdOutput(message->verbose, message->msg, false, message->tag);


  jkl::JString jstr(JTEXT("これは簡単なテストです。\n"));
  jkl::PrintToStdConsole(jstr);
#if defined(_WIN32)
  jkl::Win32Window *window = jkl::CreateWin32Window(0, 0, 640, 640, 
    JTEXT("これは簡単なテストです。"), NULL);

  jkl::PrintToStdConsole(JTEXT("Press Enter to continue through."));
  std::cin.ignore();
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
