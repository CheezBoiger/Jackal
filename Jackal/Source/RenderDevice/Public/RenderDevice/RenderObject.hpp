// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"


namespace jackal {


class RenderDevice;


// Render unique id.
typedef uint64 ruid;

// 
class RenderObject {
  static ruid numRenderObjects;
protected:
  RenderObject() 
    : uid (++numRenderObjects) 
    , mOwner(nullptr)
  { }

public:
  virtual ~RenderObject() { }

  ruid GetUid() { return uid; }
  RenderDevice* Owner() { return mOwner; }
  void SetOwner(RenderDevice* device) { mOwner = device; }

protected:
  const ruid    uid;
  RenderDevice* mOwner;
};
} // jackal