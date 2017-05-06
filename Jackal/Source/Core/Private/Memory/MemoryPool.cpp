//
// Copyright (c) Jackal Engine. MIT License.
// 
#include "Memory/MemoryPool.hpp"
#include "MemLeakDetection.hpp"
#include "Logging/Logger.hpp"

#include <new>

namespace jkl {


MemoryPool::MemoryPool(uint64 startSize)
  : totalSize(startSize)
  , sizeLeft(startSize)
  , memory(new void *[static_cast<size_t>(startSize)])
{
  Log::MessageToConsole(LOG_NOTIFY, "Memory pool allocated to size of array: "
    + std::to_string(GetTotalMemoryPoolSize() * sizeof(size_t)) 
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
  for (uint64 i = 0; i < totalSize; ++i) {
    
  }
  sizeLeft = totalSize;
}


void *MemoryPool::AllocateMemory(uint64 start, uint64 sizeBytes)
{
  if ((start + (sizeBytes / sizeof(size_t))) >= totalSize) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds."
      " Allocated at location => " + std::to_string(start), false, "Memory Pool");
    return nullptr;
  }

  sizeLeft -= sizeBytes / sizeof(size_t);
  return ((size_t *)memory + start);
}


void MemoryPool::DeallocateMemory(uint64 start, uint64 sizeBytes)
{
  if ((start + (sizeBytes / sizeof(size_t))) >= totalSize) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds."
      " Allocated at location => " + std::to_string(start), false, "Memory Pool");
    return;
  }
  sizeLeft += sizeBytes / sizeof(size_t);
}


void *MemoryPool::GetMemoryLocation(uint64 location)
{
  if (location >= totalSize) {
    Log::MessageToConsole(LOG_ERROR, "Attempted to access memory location past"
      " total size. Attempted access at location => " + std::to_string(location),
      false, "Memory Pool");
    return nullptr;
  }

  return ((size_t *)memory + location);
}
} // jkl
