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
// complete data type is specified, and it is rather stupid. Allocator is designed
// as a data structure to handle most of the proper memory allocations.
class MemoryPool {
public:
  // Default constructor
  MemoryPool(uint64 startSize = 1024);

  ~MemoryPool();

  // Reserve the total memory pool size.
  void ReserveTotalMemoryPoolSize(uint64 sizeBytes);

  // Resize the memory pool. This will reallocate a new
  // memory space according to the new size.
  void ResizeTotalMemoryPoolSize(uint64 sizeBytes);

  // Clean the memory pool properly. This is a bit slow, but it 
  // properly cleans out the memory pool for better coherence of 
  // main memory.
  void CleanMemoryPool();

  // Clean this memory pool as fast as possible, while trying to
  // keep efficiency.
  void LazyCleanMemoryPool();

  // Clear the memory pool completely. This will destroy all objects
  // and data that is already allocated in the pool.
  void ClearMemoryPool();

  // Get the actual array size of our memory pages.
  uint64 GetTotalMemoryPoolPagesSize() const { return totalPagesSize; }

  // Get the total memory pool size in terms of bytes. This is a better and
  // more accurate representation of the memory pool size, since we get the
  // actual size of the memory array in terms of size.
  uint64 GetTotalMemoryPoolSizeBytes() const { return totalPagesSize * sizeof(size_t); }

  // Get memory pool size that is left, in bytes.
  uint64 GetBytesLeft() const { return pagesLeft * sizeof(size_t); }

  // Gets the memory pool's remaining pages left.
  uint64 GetPagesLeft() const { return pagesLeft; }

  // Allocate memory within the memory pool. Specifies the starting
  // location page, along with the overall size of the allocation in terms of
  // bytes.
  void *AllocateMemory(uint64 startPage, uint64 sizeBytes);

  // Get hold of the memory location address within the memory pool.
  // Uses location address by page.
  void *GetMemoryLocation(uint64 locationPage);

private:

  // Total size of the memory pool in bytes.
  uint64 totalPagesSize;

  // Indices left over after totalSize - allocation.
  uint64 pagesLeft;

  // The raw memory on the heap. 
  void *memory;
};
} // jkl