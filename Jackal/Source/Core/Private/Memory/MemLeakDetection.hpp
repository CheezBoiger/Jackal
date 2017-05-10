//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"
#include "Memory/MemoryPool.hpp"
#include "Memory/Allocator.hpp"


namespace jkl {


// Memory Leak detector, used to check for any memory leaks within Allocator.
class MemoryLeakDetector {
public:

  bool8 CheckForLeaks(Allocator *allocator);

  void AutoCleanup(Allocator *allocator);

private:
  uint32 numLeaks;
};
} // jkl