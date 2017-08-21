// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLFrameBuffer.hpp"
#include "OpenGLRenderPass.hpp"
#include "OpenGLRenderTarget.hpp"
#include "OpenGLNative.hpp"

#include "Core/Logging/Assertions.hpp"

namespace jackal {


void OpenGLFrameBuffer::Bake(const FrameBufferCreateInfoT& info)
{
  CleanUp();

  glGenFramebuffers(1, &mHandle);
  glBindFramebuffer(GL_FRAMEBUFFER, mHandle);

  // Perform render targets loading into the framebuffer.
  RenderPassInfoT& renderPassInfo = mInformation.PRenderPass->Information();

  for (uint32 i = 0; i < renderPassInfo.SubPassCount; ++i) {
    SubPass& subpass = renderPassInfo.SubPasses[i];
    for (uint32 j = 0; j < subpass.ColorAttachmentCount; ++j) {
      RenderPassAttachmentReference& reference = subpass.PColorAttachments[j];
      RenderPassAttachment& attachment = renderPassInfo.Attachments[reference.Attachment];
      OpenGLRenderTarget& oglTarget = 
        static_cast<OpenGLRenderTarget&>(mInformation.RenderTargets[reference.Attachment]);      
      glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + reference.Attachment, 
        GL_TEXTURE_2D, oglTarget.Handle(), 0);
    }

    for (uint32 j = 0; j < subpass.DepthStencilAttachmentCount; ++j) {
      RenderPassAttachmentReference& reference = subpass.PColorAttachments[j];
      RenderPassAttachment& attachment = renderPassInfo.Attachments[reference.Attachment];
      OpenGLRenderTarget& oglTarget =
        static_cast<OpenGLRenderTarget&>(mInformation.RenderTargets[reference.Attachment]);
      glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
        GL_TEXTURE_2D, oglTarget.Handle(), 0);
    }

    OPENGL_CHECK_ERROR(GLenum err);
    if (err != GL_NO_ERROR) {
      return;
    }
  }

  GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
  if (status != GL_FRAMEBUFFER_COMPLETE) {
    // error
    return;
  }
}


void OpenGLFrameBuffer::CleanUp()
{
  if (mHandle) {
    glDeleteFramebuffers(1, &mHandle);
    mHandle = 0;
  }
}
} // jackal