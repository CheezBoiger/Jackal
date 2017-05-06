//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Platform/Platform.hpp"
#include "Platform/JTypes.hpp"
#include "Structure/HTable.hpp"
#include "Allocator.hpp"


namespace jkl {


// Memory Pool used by the engine to allocate, deallocate and monitor memory usage.
// This is will be able to detect memory leaks, as well as speed up performance by
// minimizing the number of new calls.
// This is a handler for raw memory, how this memory is allocated, however, is 
// handled by the Allocator interfaces.
class MemoryPool {
public:
  MemoryPool();

  ~MemoryPool();

  void ReserveTotalMemoryPoolSize(uint64 uid, uint64 size);

  void ResizeTotalMemoryPoolSize(uint64 size);

  void CleanMemoryPool();

  // Delete a memory pool allocation from this Memory Pool.
  void ClearMemoryPool();

  uint64 GetMemoryPoolSize() { return totalSizeBytes; }
  uint64 GetBytesAllocated() { return bytesAllocated; }
  uint64 GetBytesDeallocated() { return bytesDeallocated; }

  void AdjustMemory(uint64 bytes);

  // Get memory pool size that is left, in bytes.
  uint64 GetBytesLeft() { return bytesLeft; }

  // Grab the raw memory.
  void *GetMemoryRaw() { return memory; }

private:
  // Total number of bytes allocated on the memory pool.
  uint64 bytesAllocated;

  // Total size of the memory pool in bytes.
  uint64 totalSizeBytes;

  // Number of bytes deallocated prior to allocation.
  uint64 bytesDeallocated;

  // Bytes left over after totalSize - allocation.
  uint64 bytesLeft;

  // The raw memory 
  void *memory;
};
} // jkl