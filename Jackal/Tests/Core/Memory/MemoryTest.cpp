//
// Copyright (c) Jackal Engine. MIT License.
//
#include "MemoryTest.hpp"
#include "Memory/MemoryPool.hpp"
#include "Logging/Logger.hpp"
#include <stdlib.h>
#include <chrono>


namespace jkl {
namespace test {


// Testing optimality of memory allocation on pre-initialized memory on the heap.
void MemoryTest::Test()
{
  MemoryPool pool;
  
  auto start = std::chrono::high_resolution_clock::now();
  long long *ptr = (long long *)pool.AllocateMemory(0, sizeof(long long) * 2000);
  auto end = std::chrono::high_resolution_clock::now();

  long long *p = (long long *)pool.GetMemoryLocation(0);
  //*p = 10;
  std::printf("%llu\n", *p);

  auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  Log::MessageToConsole(LOG_NOTIFY, "MemPool alloc time " + std::to_string(t) + " ns");

  start = std::chrono::high_resolution_clock::now();
  long long *mptr = (long long *)std::malloc(sizeof(long long) * 2000);
  end = std::chrono::high_resolution_clock::now();

  t = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  Log::MessageToConsole(LOG_NOTIFY, "Malloc alloc time " + std::to_string(t) + " ns");
  Log::MessageToConsole(LOG_NOTIFY, "MemoryPool memory left: " 
    + std::to_string(pool.GetMemorySizeLeft() * sizeof(size_t)) 
    + " bytes");


  pool.ClearMemoryPool();
  free(mptr);

  Log::MessageToConsole(LOG_NOTIFY, "MemoryPool memory left after clearing: "
    + std::to_string(pool.GetMemorySizeLeft() * sizeof(size_t))
    + " bytes");
}
} // test
} // jkl