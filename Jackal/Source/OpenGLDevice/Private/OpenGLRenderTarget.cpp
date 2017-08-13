// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLRenderTarget.hpp"

#include "OpenGLNative.hpp"

#include "Core/Logging/Debugging.hpp"
#include "Core/Logging/Assertions.hpp"
#include "Core/Logging/Logger.hpp"

namespace jackal {


void OpenGLRenderTarget::Bake(RenderTargetCreateInfoT& information)
{
  RenderTarget::Bake(information);
  if (mHandle) {
    glDeleteTextures(1, &mHandle);
    mHandle = 0;
  }

  OPENGL_CHECK_ERROR(GLint err);
  if (err) {
    JDEBUG("OpenGL Error before render target! err code = %d\n", err);
  }

  glGenTextures(1, &mHandle);
  glBindTexture(GL_TEXTURE_2D, mHandle);

  GLNativeTextureFormat native = OpenGLNative::GetNativeTextureFormat(information.Format);



  if (!information.HardwareMSAA) {
    glTexImage2D(GL_TEXTURE_2D, 0, native.internalFormat, information.Width,
      information.Height, 0, native.format, native.dataType, nullptr);
  } else {
    glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, information.MSAA, native.internalFormat,
      information.Width, information.Height, GL_FALSE);
  }

  OPENGL_CHECK_ERROR(err);
  if (err) {
    JDEBUG("Failed to initialize render target! err code = %d\n", err);
  }
}


void OpenGLRenderTarget::CleanUp()
{
  if (mHandle) {
    glDeleteTextures(1, &mHandle);
    mHandle = 0;
  }
}
} // jackal