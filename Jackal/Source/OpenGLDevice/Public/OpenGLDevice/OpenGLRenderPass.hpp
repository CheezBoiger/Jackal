// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderPass.hpp"
#include "OpenGLConfigs.hpp"

namespace jackal {


class OpenGLFrameBuffer;

class OpenGLRenderPass : public RenderPass {
public:
  OpenGLRenderPass() 
    : mFrameBuffer(0) { }

  void Initialize(RenderPassCreateInfoT& info) override;
  void CleanUp() override;

  GLuint FrameBufferHandle() const { return mFrameBuffer; }

private:

  void BakeFrameBuffer(RenderPassCreateInfoT& info);

  GLuint mFrameBuffer;
}; 
} // jackal