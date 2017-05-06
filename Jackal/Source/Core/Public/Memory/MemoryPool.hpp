//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Platform/Platform.hpp"
#include "Platform/JTypes.hpp"


namespace jkl {


// Memory Pool used by the engine to allocate, deallocate and monitor memory usage.
// This is will be able to detect memory leaks, as well as speed up performance by
// minimizing the number of new calls.
// This is a handler for raw memory, how this memory is allocated, however, is 
// handled by the Allocator interfaces, since our memory pool is purely raw, no
// complete data type is specified.
class MemoryPool {
public:
  // Default constructor
  MemoryPool(uint64 startSize = 1024);

  ~MemoryPool();

  // Reserve the total memory pool size.
  void ReserveTotalMemoryPoolSize(uint64 size);

  void ResizeTotalMemoryPoolSize(uint64 size);

  void CleanMemoryPool();

  void LazyCleanMemoryPool();

  // Clear the memory pool completely. This will destroy all objects
  // and data that is already allocated in the pool.
  void ClearMemoryPool();

  uint64 GetTotalMemoryPoolSize() { return totalSize; }
  uint64 GetTotalMemoryPoolSizeBytes() { return totalSize * sizeof(void *); }

  // Get memory pool size that is left, in bytes.
  uint64 GetBytesLeft() { return bytesLeft; }

  // Allocate memory within the memory pool.
  void *AllocateMemory(uint64 start, uint64 end);

  // Get hold of the memory location address within the memory pool.
  void *GetMemory(uint64 location);

private:

  // Total size of the memory pool.
  uint64 totalSize;

  // size left over after totalSize - allocation.
  uint64 bytesLeft;

  // The raw memory on the heap.
  void *memory;
};
} // jkl