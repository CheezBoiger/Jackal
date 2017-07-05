// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"


namespace jackal {


// View Port Object, used to send over to the RenderDevice.
struct ViewPort {
  real32 X;
  real32 Y;
  real32 Width;
  real32 Height;
  
  real32 MinDepth;
  real32 MaxDepth;
};


struct ScissorRect {
  struct { uint32 Width,  Height; } Extent;
  struct { uint32 x,      y;      } Offset;
};
} // jackal