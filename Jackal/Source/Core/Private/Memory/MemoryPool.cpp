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
  , bytesLeft(startSize * sizeof(size_t))
  , memory(new void *[startSize])
{
  Log::MessageToConsole(LOG_NOTIFY, "Memory pool allocated to size of array: "
    + std::to_string(startSize) + " which is " + std::to_string(GetTotalMemoryPoolSizeBytes()) 
    + " bytes");
}


MemoryPool::~MemoryPool()
{
  // Make sure to delete memory.
  if (memory) {
    delete[] memory;
  }
}


void MemoryPool::ReserveTotalMemoryPoolSize(uint64 size)
{
  
}


void MemoryPool::ResizeTotalMemoryPoolSize(uint64 size)
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
}


void *MemoryPool::AllocateMemory(uint64 start, uint64 end)
{
  if (start >= totalSize || end >= totalSize) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds.");
    return nullptr;
  }
  if (start > end) {
    Log::MessageToConsole(LOG_ERROR, "Start location can not be larger than end location!");
    return nullptr; 
  }
  uint64 bytes = (end - start) * sizeof(void *);
  bytesLeft -= bytes;
  return ((size_t *)memory + start);
}


void *MemoryPool::GetMemory(uint64 location)
{
  if (location > totalSize) {
    Log::MessageToConsole(LOG_WARNING, "Attempted to access memory location past"
      " total size. Attempted location => " + std::to_string(location));
    return nullptr;
  }

  return ((size_t *)memory + location);
}
} // jkl
