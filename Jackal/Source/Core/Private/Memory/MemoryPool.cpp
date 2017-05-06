//
// Copyright (c) Jackal Engine. MIT License.
// 
#include "Memory/MemoryPool.hpp"
#include "MemLeakDetection.hpp"
#include "Logging/Logger.hpp"

#include <new>

namespace jkl {


MemoryPool::MemoryPool(uint64 startSizeBytes)
  : totalSizeBytes(startSizeBytes)
  , bytesLeft(startSizeBytes)
  , memory(new byte[static_cast<size_t>(startSizeBytes)])
{
  Log::MessageToConsole(LOG_NOTIFY, "Memory pool allocated to size of array: "
    + std::to_string(GetTotalMemoryPoolSizeBytes()) 
    + " bytes");
}


MemoryPool::~MemoryPool()
{
  // Make sure to delete memory.
  if (memory) {
    delete[] memory;
  }
}


void MemoryPool::ReserveTotalMemoryPoolSize(uint64 sizePages)
{
  
}


void MemoryPool::ResizeTotalMemoryPoolSize(uint64 sizePages)
{
  
}


void MemoryPool::CleanMemoryPool()
{

}


void MemoryPool::LazyCleanMemoryPool()
{

}


void MemoryPool::ClearMemoryPool()
{
  // Full clear of the memory cache.
  for (uint64 i = 0; i < totalSizeBytes; ++i) {
    
  }
  bytesLeft = totalSizeBytes;
}


void *MemoryPool::AllocateMemory(uint64 startBytes, uint64 sizeBytes)
{
  if ((startBytes + sizeBytes) >= totalSizeBytes) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds."
      " Allocated at byte => " + std::to_string(startBytes), false, "Memory Pool");
    return nullptr;
  }

  bytesLeft -= sizeBytes;
  return ((size_t *)memory + startBytes);
}


void *MemoryPool::GetMemoryLocation(uint64 locationBytes)
{
  if (locationBytes >= totalSizeBytes) {
    Log::MessageToConsole(LOG_ERROR, "Attempted to access memory location past"
      " total size. Attempted access at byte => " + std::to_string(locationBytes),
      false, "Memory Pool");
    return nullptr;
  }

  return ((size_t *)memory + locationBytes);
}
} // jkl
