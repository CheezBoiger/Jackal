//
// Copyright (c) Jackal Engine. MIT License.
//
#include "QuatTest.hpp"
#include "Math/Quaternion.hpp"
#include "Logging/Logger.hpp"
#include "Memory/MemoryPool.hpp"

namespace jkl {
namespace test {


void QuatTest::Test()
{
  Quat a;
  Quat b;

  Log::MessageToConsole(LOG_WARNING, R"(
    This is a "test", and I mean a really good test "mate".
  )", false, TARGET_OS_NAME);
  MemoryPool pool;
  Log::MessageToConsole(LOG_NOTIFY, "Total memory pool size in bytes: " 
    + std::to_string(pool.GetTotalMemoryPoolSizeBytes()));
  long long *p = (long long *)pool.AllocateMemory(0, sizeof(long long));
  *p = -11;
  long long *p1 = (long long *)pool.AllocateMemory(1, sizeof(long long));
  
  *p1 = 49;
  Log::MessageToConsole(LOG_NORMAL, 
    std::to_string(*(long long *)pool.GetMemoryLocation(1)));

  Log::MessageToConsole(LOG_NOTIFY, "Bytes left after allocating: " 
    + std::to_string(pool.GetBytesLeft()));
} 
} // test
} // jkl