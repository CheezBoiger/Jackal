//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "../../platform/public/platform.hpp"
#include "../../platform/public/jtypes.hpp"
#include "allocator.hpp"


namespace jkl {


// Memory Pool used by the engine to allocate, deallocate and monitor memory usage.
// This is will be able to detect memory leaks, as well as speed up performance by
// minimizing the number of new calls.
class MemoryPool {
public:
  MemoryPool();

  void ReserveMemoryPoolSize(uint64 size);

  void ResizeMemoryPoolSize(uint64 size);

  void CleanMemoryPool();

  uint64 GetMemoryPoolSize() { return totalSizeBytes; }
  uint64 GetBytesAllocated() { return bytesAllocated; }
  uint64 GetBytesDeallocated() { return bytesDeallocated; }

private:
  // Total number of bytes allocated on the memory pool.
  uint64 bytesAllocated;

  // Total size of the memory pool in bytes.
  uint64 totalSizeBytes;

  // Number of bytes deallocated prior to allocation.
  uint64 bytesDeallocated;

  // Bytes left over after totalSize - allocation.
  uint64 bytesLeft;

  // Observer that handles allocation of the MemoryPool.
  Allocator *allocator;
};
} // jkl