// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderPass.hpp"
#include "OpenGLConfigs.hpp"

namespace jackal {


class OpenGLFrameBuffer;



class OpenGLRenderPass : public RenderPass {
public:
  OpenGLRenderPass()
    : mFrameBuffer(nullptr) { }

  void Initialize(RenderPassCreateInfoT& info) override;
  void CleanUp() override;

  OpenGLFrameBuffer* FrameBufferReference() const { return mFrameBuffer; }

private:
  OpenGLFrameBuffer* mFrameBuffer;
}; 
} // jackal