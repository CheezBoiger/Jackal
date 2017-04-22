//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Platform/Platform.hpp"
#include "Platform/JTypes.hpp"
#include "Allocator.hpp"


namespace jkl {


// Memory Pool used by the engine to allocate, deallocate and monitor memory usage.
// This is will be able to detect memory leaks, as well as speed up performance by
// minimizing the number of new calls.
class MemoryPool {
public:

  // The memory pool used for storing memory of whatever kind you
  // need it for. 
  struct Pool {
    uint64  uid;
    uint64  sizeBytes;
    void    *memory;
  };

  static void ReserveTotalMemoryPoolSize(uint64 uid, uint64 size);

  static void ResizeTotalMemoryPoolSize(uint64 size);

  static void CleanMemoryPool(uint64 uid);

  static void DeleteMemoryPool(uint64 uid);

  static uint64 GetMemoryPoolSize() { return totalSizeBytes; }
  static uint64 GetBytesAllocated() { return bytesAllocated; }
  static uint64 GetBytesDeallocated() { return bytesDeallocated; }

  static void AdjustMemory(uint64 uid, uint64 bytes);

  static uint64 GetBytesLeft() { return bytesLeft; }

  static Pool *GetPool(uint64 uid);

private:
  // Total number of bytes allocated on the memory pool.
  static uint64 bytesAllocated;

  // Total size of the memory pool in bytes.
  static uint64 totalSizeBytes;

  // Number of bytes deallocated prior to allocation.
  static uint64 bytesDeallocated;

  // Bytes left over after totalSize - allocation.
  static uint64 bytesLeft;

};
} // jkl