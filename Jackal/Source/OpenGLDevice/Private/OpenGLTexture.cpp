// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLTexture.hpp"
#include "OpenGLNative.hpp"

#include "Core/Logging/Debugging.hpp"
#include "Core/Logging/Assertions.hpp"


namespace jackal {


void OpenGLTexture::Load(TextureInfoT &info, TextureHandle *texture)
{
  if (handle) {
    glDeleteTextures(1, &handle);
  }

  glGenTextures(1, &handle);

  GLNativeTextureFormat dF = OpenGLNative::GetNativeTextureFormat(info.Format);
  glTexImage1D(GL_TEXTURE_1D, 0, dF.internalFormat, texture->width,
    0, dF.format, dF.dataType, texture->data);
}


void OpenGLTexture::CleanUp()
{
  if (handle) {
    glDeleteTextures(1, &handle);
    handle = 0;
  }
}
} // jackal