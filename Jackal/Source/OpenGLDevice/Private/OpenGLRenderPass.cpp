// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLRenderPass.hpp"
#include "OpenGLRenderTarget.hpp"
#include "RenderDevice/RenderDevice.hpp"

#include "Core/Logging/Assertions.hpp"
#include "Core/Logging/Debugging.hpp"


namespace jackal {


void OpenGLRenderPass::Initialize(RenderPassCreateInfoT& info)
{
  CleanUp();
  glGenFramebuffers(1, &mFrameBuffer);
  glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);

  BakeFrameBuffer(info);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    JDEBUG("OpenGL RenderPass is not complete!\n");
    mOwner->SubmitLastError(RENDER_ERROR_BAD_FRAMEBUFFER_ALLOC);
    return;
  }

  glBindFramebuffer(GL_FRAMEBUFFER, 0);
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

    for (uint32 j = 0; j < subpass.ColorAttachmentCount; ++j) {
      RenderPassAttachmentReference& reference = subpass.PColorAttachments[j];
      RenderPassAttachment& attachment = info.Attachments[reference.Attachment];
      OpenGLRenderTarget* target = static_cast<OpenGLRenderTarget*>(attachment.PRenderTarget);
      
      GLenum texture;
      if (attachment.Samples == SAMPLE_COUNT_1_BIT) {
        texture = GL_TEXTURE_2D;
      } else {
        texture = GL_TEXTURE_2D_MULTISAMPLE;
      }

      glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + reference.Attachment,
        texture, target->Handle(), 0);
    }

    if (subpass.PDepthStencilAttachment) {
      RenderPassAttachmentReference* reference = subpass.PDepthStencilAttachment;
      RenderPassAttachment& attachment = info.Attachments[reference->Attachment];
      OpenGLRenderTarget* target = static_cast<OpenGLRenderTarget*>(attachment.PRenderTarget);

      GLenum texture;
      if (attachment.Samples == SAMPLE_COUNT_1_BIT) {
        texture = GL_TEXTURE_2D;
      }
      else {
        texture = GL_TEXTURE_2D_MULTISAMPLE;
      }

      glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, texture,
        target->Handle(), 0);
    }

    OPENGL_CHECK_ERROR(GLenum error);
    if (error != GL_NO_ERROR) {
      JDEBUG("Error loading render targets to framebuffer!\n");
    }
  }
}
} // jackal 