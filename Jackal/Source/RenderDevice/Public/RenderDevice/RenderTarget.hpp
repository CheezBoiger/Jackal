// Copyright (c) Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "RenderDeviceTypes.hpp"

namespace jackal {


struct RenderTargetCreateInfoT {
  int32 width;
  int32 height;
  FormatT format;  
};


// A Render Target is a surface of which rendering is destined 
// towards. It is the object of which we render onto, to which 
// acts as a buffer that will be used for displaying onto the screen.
class RenderTarget {
public:
  virtual ~RenderTarget() { }

  virtual void Bake(RenderTargetCreateInfoT &info) = 0;

  RenderTargetCreateInfoT Information() const { return mInformation; }

protected:
  RenderTargetCreateInfoT mInformation;
};
} // jackal