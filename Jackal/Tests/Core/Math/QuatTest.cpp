//
// Copyright (c) Jackal Engine. MIT License.
//
#include "QuatTest.hpp"
#include "Math/Quaternion.hpp"
#include "Logging/Logger.hpp"
#include "Memory/MemoryPool.hpp"
#include <chrono>
#include <stdlib.h>

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
    + std::to_string(pool.GetTotalMemoryPoolSize() * sizeof(size_t)));
  auto start = std::chrono::high_resolution_clock::now();
  double *p = (double *)pool.AllocateMemory(0, sizeof(double) * 100);
  auto end = std::chrono::high_resolution_clock::now();

  float t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  Log::MessageToConsole(LOG_NOTIFY, std::to_string(t));

  start = std::chrono::high_resolution_clock::now();
  double *ss = (double *)std::malloc(sizeof(double) * 100);
  end = std::chrono::high_resolution_clock::now();
  t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  free(ss);
  
  Log::MessageToConsole(LOG_NOTIFY, std::to_string(t));
  *p = -11.32456243f;
  //pool.DeallocateMemory(0, sizeof(double));
  long long *p1 = (long long *)pool.AllocateMemory(1, sizeof(long long));

  *p1 = 49;
  Log::MessageToConsole(LOG_NORMAL, 
    std::to_string(*(double *)pool.GetMemoryLocation(0)) + " " 
    + std::to_string(*(long long *)pool.GetMemoryLocation(1)));

  Log::MessageToConsole(LOG_NOTIFY, "Bytes left after allocating: " 
    + std::to_string(pool.GetMemorySizeLeft() * sizeof(size_t)));
} 
} // test
} // jkl