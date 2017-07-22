// Copyright (c) 2017 Jackal Engine, MIT License
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "RenderObject.hpp"

namespace jackal {


class FrameBuffer;

// Render Pass object. Specifies the color, depth, 
// and stencil buffers that will be bound when rendering. They also
// serve as how these buffers will be handled throughout the rendering
// operation. They are mainly descriptions that are used to determine 
// how to use the buffers that are set in FrameBuffers.
class RenderPass : public RenderObject {
protected:
  RenderPass() { }

public:

  virtual ~RenderPass() { }

  
  // Get the frame buffer reference.
  FrameBuffer *GetFrameBufferReference() { return mFrameBufferReference; }

protected:
  FrameBuffer *mFrameBufferReference;
};
} // jackal