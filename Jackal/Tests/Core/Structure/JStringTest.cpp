﻿// Copyright (c) 2017 Jackal Engine, MIT License.
#include "JStringTest.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Logging/TextBase.hpp"
#include <gtest/gtest.h>
#include <string>


TEST(StructureTests, JStringTesting)
{
  std::string str("Testing simple string.");

  jkl::Log::MessageToConsole(jkl::LogVerbosity::LOG_NORMAL, str, true, "Chicken"); 
  jkl::Log::MessageToConsole(jkl::LogVerbosity::LOG_NORMAL, std::to_string(str.empty())); 

  jkl::Message *message = jkl::Log::GetStoredMessage(jkl::LOG_NORMAL, 0);

  jkl::Log::MessageToConsole(message->verbose, message->msg, false, message->tag);

  setlocale(LC_ALL, "ja-JP");
  jkl::JString jstr("これは簡単なテストです。");

  std::wcout.imbue(std::locale("ja_JP.UTF-8"));
  std::cout << "これは簡単なテストです。" << "\n";
  std::cout << jstr.CStr() << "\n";
}


namespace coretest {


void JStringTesting()
{
  // do nothing.
}
} // jstringtest
