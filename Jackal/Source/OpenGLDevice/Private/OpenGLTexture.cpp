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
  glTexImage2D(GL_TEXTURE_2D, 0, dF.internalFormat, texture->width, 
    texture->height, texture->channels, dF.format, dF.dataType, texture->data);
}
} // jackal