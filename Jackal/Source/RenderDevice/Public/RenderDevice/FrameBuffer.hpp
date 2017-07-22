// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 

#include "Core/Platform/JTypes.hpp"


namespace jackal {


class RenderPass;
class RenderTarget;


// FrameBuffers are objects that contain surfaces to write/render onto.
// They hold color buffers, depth buffers, and stencil buffers for which 
// are used to display onto the screen.
class FrameBuffer {
protected:
  FrameBuffer() { }

public:

  virtual ~FrameBuffer() { }

  // Get the render pass reference.
  RenderPass *GetRenderPassReference() { return mRenderPassReference; }

  virtual void StoreRenderTarget(RenderTarget *target, uint32 index) = 0;
  virtual RenderTarget *GetRenderTarget(uint32 index) = 0;
  virtual bool8 RemoveRenderTarget(uint32 index) = 0;

  virtual void Bake(RenderPass *renderpass) = 0;

protected:
  RenderPass *mRenderPassReference;
};
} // jackal