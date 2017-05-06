//
// Copyright (c) Jackal Engine. MIT License.
// 
#include "Memory/MemoryPool.hpp"
#include "MemLeakDetection.hpp"
#include "Logging/Logger.hpp"

#include <new>

namespace jkl {


MemoryPool::MemoryPool(uint64 startSize)
  : totalPagesSize(startSize)
  , pagesLeft(startSize)
  , memory(new void *[startSize])
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


void MemoryPool::ReserveTotalMemoryPoolSize(uint64 sizeBytes)
{
  
}


void MemoryPool::ResizeTotalMemoryPoolSize(uint64 sizeBytes)
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
  for (uint64 i = 0; i < totalPagesSize; ++i) {
    
  }
  pagesLeft = totalPagesSize;
}


void *MemoryPool::AllocateMemory(uint64 startPage, uint64 sizeBytes)
{
  if ((startPage + sizeBytes) >= totalPagesSize) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds."
      " Allocated at page => " + std::to_string(startPage), false, "Memory Pool");
    return nullptr;
  }

  uint64 padBytes = (sizeBytes % sizeof(size_t));
  pagesLeft -= ((sizeBytes + padBytes) / sizeof(size_t));
  return ((size_t *)memory + startPage);
}


void *MemoryPool::GetMemoryLocation(uint64 locationPage)
{
  if (locationPage >= totalPagesSize) {
    Log::MessageToConsole(LOG_ERROR, "Attempted to access memory location past"
      " total size. Attempted access at page => " + std::to_string(locationPage),
      false, "Memory Pool");
    return nullptr;
  }

  return ((size_t *)memory + locationPage);
}
} // jkl
