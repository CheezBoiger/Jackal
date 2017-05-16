// Copyright (c) 2017 Jackal Engine, MIT License.
#include "MemoryTest.hpp"
#include "Memory/MemoryPool.hpp"
#include "Logging/Logger.hpp"
#include <stdlib.h>
#include <chrono>


namespace coretest {


// Memory allocations with resulting testing for use with malloc, and 
// whatnot.
TEST(MemoryTesting, AllocateMemory) {
  jkl::MemoryPool pool;
  auto start = std::chrono::high_resolution_clock::now();
  long long *ptr = (long long *)pool.AllocateMemory(0, sizeof(long long) * 2000);
  auto end = std::chrono::high_resolution_clock::now();

  long long *p = (long long *)pool.GetMemoryLocation(0);
  //*p = 10;
//  std::printf("%llu\n", *p);

  auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  jkl::Log::MessageToConsole(jkl::LOG_NOTIFY, "MemPool alloc time " + std::to_string(t) + " ns");

  start = std::chrono::high_resolution_clock::now();
  long long *mptr = (long long *)std::malloc(sizeof(long long) * 2000);
  end = std::chrono::high_resolution_clock::now();

  t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  jkl::Log::MessageToConsole(jkl::LOG_NOTIFY, "Malloc alloc time " + std::to_string(t) + " ns");
  jkl::Log::MessageToConsole(jkl::LOG_NOTIFY, "MemoryPool memory left: "
    + std::to_string(pool.GetMemorySizeLeft() * sizeof(size_t))
    + " bytes");

  size_t allocSize = (pool.GetTotalMemoryPoolSize() * sizeof(size_t))
    - (pool.GetMemorySizeLeft() * sizeof(size_t));

  EXPECT_EQ(allocSize, sizeof(long long) * 2000);

  pool.ClearMemoryPool();
  free(mptr);

  EXPECT_EQ(pool.GetMemorySizeLeft(), pool.GetTotalMemoryPoolSize());

  jkl::Log::MessageToConsole(jkl::LOG_NOTIFY, "MemoryPool memory left after clearing: "
    + std::to_string(pool.GetMemorySizeLeft() * sizeof(size_t))
    + " bytes");
}


void MemoryTesting()
{
}
} // coretest
