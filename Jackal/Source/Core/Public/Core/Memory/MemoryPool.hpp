// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"


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
  MemoryPool(size_t startSize = 2048);

  ~MemoryPool();

  // Reserve the total memory pool size.
  void ReserveTotalMemoryPoolSize(size_t sizeBytes);

  // Resize the memory pool. This will reallocate a new
  // memory space according to the new size.
  void ResizeTotalMemoryPoolSize(size_t sizeBytes);

  // Clean the memory pool properly. This is a bit slow, but it 
  // properly cleans out the memory pool for better coherence of 
  // main memory.
  void CleanMemoryPool();

  // Clean this memory pool as fast as possible, while trying to
  // keep efficiency.
  void LazyCleanMemoryPool();

  // Clear the memory pool completely. This will destroy all objects
  // and data that is already allocated in the pool. Be advised this 
  // can have detrimental effects to any objects being used currently.
  // Use with caution, or if you know for a fact that this memory pool
  // is not being used an must be cleared.
  // Keep in mind that this call will also lose references to any 
  // newly allocated objects on the heap! Be sure to handle these first
  // before calling this function!
  void ClearMemoryPool();

  // Get the actual array size of our memory pages.
  size_t GetTotalMemoryPoolSize() const { return totalSize; }

  // Gets the memory pool's remaining size.
  size_t GetMemorySizeLeft() const { return sizeLeft; }

  // Allocate memory within the memory pool. Specifies the starting
  // location, along with the overall size of the allocation in terms of
  // bytes.
  void *AllocateMemory(size_t start, size_t sizeBytes);

  // Deallocate memory within the memory pool. Specifies the starting
  // location, along with the overall size of the allocation in terms of 
  // bytes.
  void DeallocateMemory(size_t start, size_t sizeBytes);

  // Get hold of the memory location address within the memory pool.
  // Uses location address.
  void *GetMemoryLocation(size_t location);

private:
  // The raw memory on the heap. 
  void *memory;

  // Total size of the memory pool in bytes.
  size_t totalSize;

  // Indices left over after totalSize - allocation.
  size_t sizeLeft;
};
} // jkl