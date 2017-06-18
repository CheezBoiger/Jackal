// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Memory/MemoryPool.hpp"
#include "MemLeakDetection.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Logging/Debugging.hpp"
#include "Core/Utility/JStringUtils.hpp"

#include <new>


namespace jackal {


MemoryPool::MemoryPool(size_t startSizeBytes)
  : totalSize(startSizeBytes / sizeof(size_t))
  , sizeLeft(startSizeBytes / sizeof(size_t))
  , memory(new void *[startSizeBytes / sizeof(size_t)])
{
  JACKAL_REMOVE_ON_RELEASE(
  Log::MessageToStdOutput(LOG_NOTIFY, JTEXT("Memory pool allocated to size of array: ")
    + JStringUtils::ToString(GetTotalMemoryPoolSize() * sizeof(size_t)) 
    + JTEXT(" bytes"))); 
}
   

MemoryPool::~MemoryPool()
{
  // Make sure to delete memory.
  if (memory) {
    delete[] reinterpret_cast<char *>(memory);
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
  memory = new void *[size / sizeof(size_t)];
  totalSize = size / sizeof(size_t);
  sizeLeft = totalSize;

  for (size_t i = 0; i < size; ++i) {
    *((size_t *)memory + i) = *((size_t *)memTemp + i);
  }

  // Delete original memory afterwards.
  delete[] reinterpret_cast<char *>(memTemp);
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
    Log::MessageToStdOutput(LOG_ERROR, JTEXT("Unable to allocate memory due to out of bounds."
      " Allocated at location => ") + JStringUtils::ToString(start), false, JTEXT("Memory Pool"));
    return nullptr;
  });
  sizeLeft -= sizeBytes / sizeof(size_t);
  return ((size_t *)memory + start);
}


void MemoryPool::DeallocateMemory(size_t start, size_t sizeBytes)
{
  JACKAL_REMOVE_ON_RELEASE(
  if ((start + (sizeBytes / sizeof(size_t))) >= totalSize) {
    Log::MessageToStdOutput(LOG_ERROR, JTEXT("Unable to allocate memory due to out of bounds."
      " Allocated at location => ") + JStringUtils::ToString(start), false, JTEXT("Memory Pool"));
    return;
  });
  sizeLeft += sizeBytes / sizeof(size_t);
}
  

void *MemoryPool::GetMemoryLocation(size_t location)
{
 JACKAL_REMOVE_ON_RELEASE(
  if (location >= totalSize) {
    Log::MessageToStdOutput(LOG_ERROR, JTEXT("Attempted to access memory location past"
      " total size. Attempted access at location => ") + JStringUtils::ToString(location),
      false, JTEXT("Memory Pool"));
    return nullptr;
  });

  return ((size_t *)memory + location);
}
} // jackal
