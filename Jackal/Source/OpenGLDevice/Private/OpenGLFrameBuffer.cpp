// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLFrameBuffer.hpp"
#include "OpenGLRenderPass.hpp"
#include "OpenGLRenderTarget.hpp"
#include "OpenGLNative.hpp"

#include "Core/Logging/Assertions.hpp"

namespace jackal {


void OpenGLFrameBuffer::Create()
{
  CleanUp();
  glGenFramebuffers(1, &mHandle);
}


void OpenGLFrameBuffer::Bind()
{
  glBindFramebuffer(GL_FRAMEBUFFER, mHandle);
}


bool OpenGLFrameBuffer::Complete()
{
  GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
  if (status != GL_FRAMEBUFFER_COMPLETE) {
    // error
    return false;
  }
  return true;
}


void OpenGLFrameBuffer::CleanUp()
{
  if (mHandle) {
    glDeleteFramebuffers(1, &mHandle);
    mHandle = 0;
  }
}
} // jackal