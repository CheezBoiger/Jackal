// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Memory/MemoryPool.hpp"
#include "MemLeakDetection.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Logging/Debugging.hpp"

#include <new>


namespace jkl {


MemoryPool::MemoryPool(size_t startSize)
  : totalSize(startSize)
  , sizeLeft(startSize)
  , memory(new void *[startSize])
{
  JACKAL_REMOVE_ON_RELEASE(
  Log::MessageToConsole(LOG_NOTIFY, "Memory pool allocated to size of array: "
    + std::to_string(GetTotalMemoryPoolSize() * sizeof(size_t)) 
    + " bytes")); 
}
   

MemoryPool::~MemoryPool()
{
  // Make sure to delete memory.
  if (memory) {
    delete[] memory;
  }
}


void MemoryPool::ReserveTotalMemoryPoolSize(size_t size)
{
  if (size > totalSize) {
    ResizeTotalMemoryPoolSize(size);
  }
}


void MemoryPool::ResizeTotalMemoryPoolSize(size_t size)
{
  void *memTemp = memory;
  memory = new void*[size];
  for (size_t i = 0; i < size; ++i) {
    *((size_t *)memory + i) = *((size_t *)memTemp + i);
  }

  // Delete original memory afterwards.
  delete[] memTemp;
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
    *((size_t *)memory + i) = ~0;
  }
  sizeLeft = totalSize;
}


void *MemoryPool::AllocateMemory(size_t start, size_t sizeBytes)
{
  JACKAL_REMOVE_ON_RELEASE(
  if ((start + (sizeBytes / sizeof(size_t))) >= totalSize) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds."
      " Allocated at location => " + std::to_string(start), false, "Memory Pool");
    return nullptr;
  });
  sizeLeft -= sizeBytes / sizeof(size_t);
  return ((size_t *)memory + start);
}


void MemoryPool::DeallocateMemory(size_t start, size_t sizeBytes)
{
  JACKAL_REMOVE_ON_RELEASE(
  if ((start + (sizeBytes / sizeof(size_t))) >= totalSize) {
    Log::MessageToConsole(LOG_ERROR, "Unable to allocate memory due to out of bounds."
      " Allocated at location => " + std::to_string(start), false, "Memory Pool");
    return;
  });
  sizeLeft += sizeBytes / sizeof(size_t);
}
  

void *MemoryPool::GetMemoryLocation(size_t location)
{
 JACKAL_REMOVE_ON_RELEASE(
  if (location >= totalSize) {
    Log::MessageToConsole(LOG_ERROR, "Attempted to access memory location past"
      " total size. Attempted access at location => " + std::to_string(location),
      false, "Memory Pool");
    return nullptr;
  });

  return ((size_t *)memory + location);
}
} // jkl
