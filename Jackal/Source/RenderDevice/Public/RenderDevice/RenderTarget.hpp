// Copyright (c) Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "RenderDeviceTypes.hpp"

#include "RenderObject.hpp"

namespace jackal {


struct RenderTargetCreateInfoT {
  int32       Width;
  int32       Height;
  FormatT     Format;  
  bool8       HardwareMSAA;
  SampleCount MSAA;
};


// A Render Target is a surface of which rendering is destined 
// towards. It is the object of which we render onto, to which 
// acts as a buffer that will be used for displaying onto the screen.
class RenderTarget : public RenderObject {
public:
  virtual ~RenderTarget() { }

  virtual void Bake(RenderTargetCreateInfoT &info) { mInformation = info; }
  virtual void CleanUp() = 0;

  RenderTargetCreateInfoT Information() const { return mInformation; }

protected:
  RenderTargetCreateInfoT mInformation;
};
} // jackal