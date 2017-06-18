// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Allocator.hpp"

namespace jackal {


// Simple smart pointer, not having to deal with the STL library standard.
// However, we can still rely heavily on the STL Library if needed. In this case,
// We need to provide our own custom allocator, which will use predefined memory in
// space, so as to speed up performance.
template<typename Type, 
         typename Allocator>
class SPtr {
public:
  SPtr(Type &type, Allocator &alloc = Allocator())
    : type(0), alloc(alloc) 
  { 
    
  }

  SPtr(Allocator &alloc = Allocator()) 
    : alloc(alloc) 
  { }

  // TODO(): Need to define the Allocator interface first!
private:
  Type *type;
  Allocator alloc;
};
} // jackal