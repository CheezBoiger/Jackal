//
// Copyright (c) Jackal Engine. MIT License.
//
#include "quat_test.hpp"
#include "math/quaternion.hpp"
#include "logging/logger.hpp"

namespace jkl {
namespace test {


void QuatTest::Test()
{
  Quat a;
  Quat b;

  Log::MessageToConsole(LOG_WARNING, R"(
    This is a "test", and I mean a really good test "mate".
  )", false, TARGET_OS_NAME);
} 
} // test
} // jkl