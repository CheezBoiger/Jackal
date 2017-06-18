// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Memory/MemoryPool.hpp"
#include "Core/Memory/Allocator.hpp"


namespace jackal {


// Memory Leak detector, used to check for any memory leaks within Allocator.
class MemoryLeakDetector {
public:

  bool8 CheckForLeaks(Allocator *allocator);

  void AutoCleanup(Allocator *allocator);

private:
  uint32 numLeaks;
};
} // jackal