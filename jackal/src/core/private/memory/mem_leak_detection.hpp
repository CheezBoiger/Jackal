//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "platform/jtypes.hpp"
#include "platform/platform.hpp"
#include "memory/memory_pool.hpp"


namespace jkl {


// Memory Leak detector, used to check for any memory leaks within the memory pool.
class MemoryLeakDetector {
public:

  

private:
  
  // Observed memory pool, to check for memory leaks.
  MemoryPool *observedMemoryPool;
};
} // jkl