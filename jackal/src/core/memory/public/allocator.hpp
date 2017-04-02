//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "../../platform/public/platform.hpp"
#include "../../platform/public/jtypes.hpp"


namespace jkl {


// The Allocator interface for Jackal Engine. This is used to provide us
// abstraction from how we allocate memory. This comes handy for allocations
// that require speed. We can't always use new for runtime, the best approach
// is to use preallocated memory to speed up memory caching.
template<typename Type>
class Allocator {
public:
  virtual ~Allocator() { }

  // TODO(): Need to define the interface!
};
} // jkl