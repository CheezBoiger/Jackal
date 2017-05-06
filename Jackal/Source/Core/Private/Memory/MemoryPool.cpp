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
  , reserved(new byte[static_cast<size_t>(startSizeBytes / 8)])
{
  Log::MessageToConsole(LOG_NOTIFY, "Memory pool allocated to size of array: "
    + std::to_string(GetTotalMemoryPoolSizeBytes()) 
    + " bytes");
  for (uint64 i = 0; i < static_cast<size_t>(startSizeBytes / 8); ++i) {
    *(reserved + i) = 0x0;
  }
}
   

MemoryPool::~MemoryPool()
{
  // Make sure to delete memory.
  if (memory) {
    delete[] memory;
    delete[] reserved;
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
  
  for (uint64 i = startBytes; i < (startBytes + sizeBytes); ++i) {
    size_t location = i / 8;
    size_t fill = (7 - (i % 8));
    if (((*(reserved + location) & (1 << fill)) == (1 << fill))) {
      
      Log::MessageToConsole(LOG_ERROR, "Memory overlap, will cause corruption! => " +
        std::to_string(*(reserved + location)), 
        false, "Memory Pool");
      return nullptr;
    }
    *(reserved + location) |= (1 << fill);
  }

  bytesLeft -= sizeBytes;
  return ((size_t *)memory + startBytes);
}


void MemoryPool::DeallocateMemory(uint64 startBytes, uint64 sizeBytes)
{
  if ((startBytes + sizeBytes) >= totalSizeBytes) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds."
      " Allocated at byte => " + std::to_string(startBytes), false, "Memory Pool");
    return;
  }

  for (uint64 i = startBytes; i < (startBytes + sizeBytes); ++i) {
    size_t location = i / 8;
    size_t fill = (7 - (i % 8));
    if (((*(reserved + location) & (1 << fill)) == (1 << fill))) {
      *(reserved + location) ^= (1 << fill);
    }
  }
  bytesLeft += sizeBytes;
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
