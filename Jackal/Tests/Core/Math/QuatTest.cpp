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
  int *p = (int *)pool.AllocateMemory(0, sizeof(int));
  *p = -11;
  long long *p1 = (long long *)pool.AllocateMemory(4, sizeof(long long));
  
  *p1 = 49;
  Log::MessageToConsole(LOG_NORMAL, 
    std::to_string(*(int *)pool.GetMemoryLocation(0)) + " " 
    + std::to_string(*(long long *)pool.GetMemoryLocation(4)));

  Log::MessageToConsole(LOG_NOTIFY, "Bytes left after allocating: " 
    + std::to_string(pool.GetMemorySizeLeftBytes()));
} 
} // test
} // jkl