// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLRenderPass.hpp"
#include "RenderDevice/RenderDevice.hpp"


namespace jackal {


void OpenGLRenderPass::Initialize(RenderPassCreateInfoT& info)
{
  CleanUp();
  glGenFramebuffers(1, &mFrameBuffer);
  glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);

  BakeFrameBuffer(info);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    mOwner->SubmitLastError(RENDER_ERROR_BAD_FRAMEBUFFER_ALLOC);
    return;
  }
}


void OpenGLRenderPass::CleanUp()
{
  if (mFrameBuffer) {
    glDeleteFramebuffers(1, &mFrameBuffer);
    mFrameBuffer = 0;
  }
}


void OpenGLRenderPass::BakeFrameBuffer(RenderPassCreateInfoT& info)
{
  for (uint32 i = 0; i < info.SubPassCount; ++i) {
    SubPass& subpass = info.SubPasses[i];
  }
}
} // jackal 