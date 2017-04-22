//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"
#include "Memory/MemoryPool.hpp"


namespace jkl {


// Memory Leak detector, used to check for any memory leaks within the memory pool.
class MemoryLeakDetector {
public:

  

private:
  
  // Observed memory pool, to check for memory leaks.
  MemoryPool *observedMemoryPool;
};
} // jkl