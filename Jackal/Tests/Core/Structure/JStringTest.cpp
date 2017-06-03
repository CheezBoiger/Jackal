// Copyright (c) 2017 Jackal Engine, MIT License.
#include "JStringTest.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Logging/Logger.hpp"

#include <gtest/gtest.h>


TEST(StructureTests, JStringTesting)
{
  jkl::JString str = "Testing simple string.";

  jkl::Log::MessageToConsole(jkl::LogType::LOG_NORMAL, std::string(str.CStr())); 
  jkl::Log::MessageToConsole(jkl::LogType::LOG_NORMAL, std::to_string(str.IsEmpty())); 
}


namespace coretest {


void JStringTesting()
{
  // do nothing.
}
} // jstringtest