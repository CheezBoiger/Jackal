// Copyright (c) 2017 Jackal Engine, MIT License.
#include "MemoryTest.hpp"
#include "Core/Memory/MemoryPool.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Utility/JStringUtils.hpp"
#include <stdlib.h>
#include <chrono>


namespace coretest {


// Memory allocations with resulting testing for use with malloc, and 
// whatnot.
TEST(MemoryTesting, AllocateMemory) {
  jackal::MemoryPool pool;
  auto start = std::chrono::high_resolution_clock::now();
  long long *ptr = (long long *)pool.AllocateMemory(0, sizeof(long long) * 2000);
  auto end = std::chrono::high_resolution_clock::now();

  long long *p = (long long *)pool.GetMemoryLocation(0);
  //*p = 10;
//  std::printf("%llu\n", *p);

  auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  jackal::Log::MessageToStdOutput(jackal::LOG_NOTIFY, JTEXT("MemPool alloc time ") 
    + jackal::ToString(t) + JTEXT(" ns"));

  start = std::chrono::high_resolution_clock::now();
  long long *mptr = (long long *)std::malloc(sizeof(long long) * 2000);
  end = std::chrono::high_resolution_clock::now();

  t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  jackal::Log::MessageToStdOutput(jackal::LOG_NOTIFY, JTEXT("Malloc alloc time ")
    + jackal::ToString(t) + JTEXT(" ns"));
  jackal::Log::MessageToStdOutput(jackal::LOG_NOTIFY, JTEXT("MemoryPool memory left: ")
    + jackal::ToString(pool.GetMemorySizeLeft() * sizeof(size_t))
    + JTEXT(" bytes"));

  size_t allocSize = (pool.GetTotalMemoryPoolSize() * sizeof(size_t))
    - (pool.GetMemorySizeLeft() * sizeof(size_t));

  EXPECT_EQ(allocSize, sizeof(long long) * 2000);

  pool.ClearMemoryPool();
  free(mptr);

  EXPECT_EQ(pool.GetMemorySizeLeft(), pool.GetTotalMemoryPoolSize());

  jackal::Log::MessageToStdOutput(jackal::LOG_NOTIFY, JTEXT("MemoryPool memory left after clearing: ")
    + jackal::ToString(pool.GetMemorySizeLeft() * sizeof(size_t))
    + JTEXT(" bytes"));
}


void MemoryTesting()
{
}
} // coretest
