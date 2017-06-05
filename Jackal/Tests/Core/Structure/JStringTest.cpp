// Copyright (c) 2017 Jackal Engine, MIT License.
#include "JStringTest.hpp"
#include "Core/Internationalization/Locale.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Utility/JStringUtils.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Logging/TextBase.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(StructureTests, JStringTesting)
{
  jkl::Locale::SetLanguage(jkl::J_JAPANESE);

  jkl::JString str(JTEXT("Testing simple string."));

  jkl::Log::MessageToStdOutput(jkl::LogVerbosity::LOG_NORMAL, str, true, JTEXT("Chicken")); 
  jkl::Log::MessageToStdOutput(jkl::LogVerbosity::LOG_NORMAL, jkl::JStringUtils::ToString(str.empty())); 

  jkl::Message *message = jkl::Log::GetStoredMessage(jkl::LOG_NORMAL, 0);

  jkl::Log::MessageToStdOutput(message->verbose, message->msg, false, message->tag);


  jkl::JString jstr(JTEXT("これは簡単なテストです。\n"));
  jkl::PrintToStdConsole(jstr);
}


namespace coretest {


void JStringTesting()
{
  // do nothing.
}
} // jstringtest
