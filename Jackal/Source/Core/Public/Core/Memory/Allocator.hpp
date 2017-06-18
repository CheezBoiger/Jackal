// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"


namespace jackal {


class MemoryPool;


// The Allocator interface for Jackal Engine. This is used to provide us
// abstraction from how we allocate memory. This comes handy for allocations
// that require speed. We can't always use new for runtime, the best approach
// is to use preallocated memory to speed up memory caching.  This is a smarter
// implementation of memory management with handling our memory pool.
class Allocator {
public:
  Allocator(MemoryPool *memory = nullptr)
    : start(0)
    , numberOfAllocations(0)
    , usedMemory(0)
    , memPool(memory)
  { }

  // Allocator used to handle memory leaks that may occur as a result of 
  // no call to deconstruct our objects.
  virtual ~Allocator() { }

  // TODO(): Need to define the interface!

  // Allocate memory within a memory pool structure. This Allocator will 
  // handle most of the work done for allocation.
  virtual void *Allocate(size_t size, size_t alignment = sizeof(void *)) = 0;

  // Deallocate memory from the memory pool structure. This Allocator will
  // handle most of the work done to deallocate from the memory pool.
  virtual void Deallocate(void *pointer) = 0;

  // Get the overall size of the memory pool structure. This is returned in
  // bytes.
  virtual size_t GetSizeBytes() = 0;

  // TODO(): Reconstruct? Do we need this?
  virtual void *ReConstruct() = 0;

  // Get the memory pool structure from this allocator.
  MemoryPool *GetMemoryPool() { return memPool; }

  // Attach a new memory pool structure to this allocator. This will ultimately
  // lose reference to the last memory pool structure, which can be detrimental 
  // if there is no handle to that memory pool other than this allocator.
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
} // jackal