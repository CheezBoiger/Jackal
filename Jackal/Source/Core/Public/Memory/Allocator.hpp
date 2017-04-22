//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "Platform/Platform.hpp"
#include "Platform/JTypes.hpp"


namespace jkl {


// The Allocator interface for Jackal Engine. This is used to provide us
// abstraction from how we allocate memory. This comes handy for allocations
// that require speed. We can't always use new for runtime, the best approach
// is to use preallocated memory to speed up memory caching.
class Allocator {
public:

  virtual ~Allocator() { }

  // TODO(): Need to define the interface!

  virtual void *Allocate(uint32 addBytes) = 0;

  virtual void Deallocate() = 0;

  virtual void Construct() = 0;

  virtual void Destruct() = 0;

  virtual uint32 GetSize() = 0;

  virtual void *ReConstruct() = 0;
};
} // jkl