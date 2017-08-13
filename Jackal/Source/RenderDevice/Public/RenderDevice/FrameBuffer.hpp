// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 

#include "Core/Platform/JTypes.hpp"

#include "RenderObject.hpp"
#include "RenderDeviceTypes.hpp"

namespace jackal {


class RenderPass;
class RenderTarget;


// FrameBuffer creation information.
struct FrameBufferCreateInfoT {
  RenderPass*         PRenderPass;
  uint32              RenderTargetCount;
  RenderTarget*       RenderTargets;
  uint32              Width;
  uint32              Height;  
};


// FrameBuffers are objects that contain surfaces to write/render onto.
// They hold color buffers, depth buffers, and stencil buffers for which 
// are used to display onto the screen.
class FrameBuffer : public RenderObject {
protected:
  FrameBuffer() { }

public:

  virtual ~FrameBuffer() { }

  // Get the render pass reference.
  RenderPass *GetRenderPassReference() { return mRenderPassReference; }

  virtual void Bake(FrameBufferCreateInfoT& info) = 0;

  virtual void CleanUp() = 0;

protected:
  RenderPass *mRenderPassReference;
};
} // jackal