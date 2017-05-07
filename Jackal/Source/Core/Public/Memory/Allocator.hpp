//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "Platform/Platform.hpp"
#include "Platform/JTypes.hpp"


namespace jkl {


class MemoryPool;


// The Allocator interface for Jackal Engine. This is used to provide us
// abstraction from how we allocate memory. This comes handy for allocations
// that require speed. We can't always use new for runtime, the best approach
// is to use preallocated memory to speed up memory caching.  This is a smarter
// implementation of memory management with handling our memory pool.
class Allocator {
public:
  Allocator()
    : start(0)
    , numberOfAllocations(0)
    , usedMemory(0)
    , memPool(nullptr)
  { }

  virtual ~Allocator() { }

  // TODO(): Need to define the interface!

  virtual void *Allocate(uint32 size, uint8 alignment = sizeof(void *)) = 0;

  virtual void Deallocate(void *pointer) = 0;

  virtual uint32 GetSize() = 0;

  virtual void *ReConstruct() = 0;

  MemoryPool *GetMemoryPool() { return memPool; }

  void AttachMemoryPool(MemoryPool *pool) { memPool = pool; }

protected:
  // Memory pool used to deal with allocations.
  MemoryPool *memPool;

  // Starting location in the memory pool.
  size_t start;

  // Number of allocations performed by this allocator.
  size_t numberOfAllocations;

  // Used memory that was allocated by this allocator.
  size_t usedMemory;
};
} // jkl