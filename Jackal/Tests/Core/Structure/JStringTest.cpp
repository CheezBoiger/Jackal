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
 #include <Windows.h>
#endif

TEST(StructureTests, JStringTesting)
{
#if defined(_WIN32)
  SetConsoleOutputCP(CP_UTF8);
#endif
  jkl::Locale::SetLanguage(jkl::J_JAPANESE);

  jkl::JString str(JTEXT("Testing simple string."));

  jkl::Log::MessageToConsole(jkl::LogVerbosity::LOG_NORMAL, str, true, JTEXT("Chicken")); 
  jkl::Log::MessageToConsole(jkl::LogVerbosity::LOG_NORMAL, jkl::JStringUtils::ToString(str.empty())); 

  jkl::Message *message = jkl::Log::GetStoredMessage(jkl::LOG_NORMAL, 0);

  jkl::Log::MessageToConsole(message->verbose, message->msg, false, message->tag);

  jkl::JString jstr(JTEXT("これは簡単なテストです。"));

  ASSERT_STREQ(jstr.c_str(), JTEXT("これは簡単なテストです。"));

  JCOUT() << jstr << "\n";
#if defined(_WIN32)
  MessageBoxW(GetActiveWindow(), jstr.c_str(), JTEXT("Chickens"), (UINT )MB_OK);
#endif
}


namespace coretest {


void JStringTesting()
{
  // do nothing.
}
} // jstringtest
