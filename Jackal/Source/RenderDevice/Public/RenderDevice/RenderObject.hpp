// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"


namespace jackal {


// Render unique id.
typedef uint64 ruid;

// 
class RenderObject {
  static ruid numRenderObjects;
protected:
  RenderObject() 
    : uid (++numRenderObjects) 
  { }

public:
  virtual ~RenderObject() { }

  ruid GetUid() { return uid; }

protected:
  const ruid    uid;
};
} // jackal