// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLTexture2D.hpp"
#include "OpenGLNative.hpp"

#include "Core/Logging/Assertions.hpp"
#include "Core/Logging/Debugging.hpp"

namespace jackal {


void OpenGLTexture2D::Load(TextureInfoT& info, TextureHandle* texture)
{
  CleanUp();
  
  glGenTextures(1, &mHandle);
  glBindTexture(GL_TEXTURE_2D, mHandle);
  
  GLNativeTextureFormat format = OpenGLNative::GetNativeTextureFormat(info.Format);
  if (info.Multisampled) {
    glTexImage2DMultisample(GL_TEXTURE_2D, info.Samples,  format.internalFormat,
      texture->width, texture->height, GL_FALSE);
  } else {
    glTexImage2D(GL_TEXTURE_2D, 0, format.internalFormat, texture->width, texture->height,
      0, format.format, format.dataType, texture->data);

    if (info.Mipmapped) {
      glGenerateMipmap(GL_TEXTURE_2D);
      
    }
  }

  OPENGL_CHECK_ERROR(GLenum err);
  if (err != GL_NO_ERROR) {
    
  }
}


void OpenGLTexture2D::CleanUp()
{
  if (mHandle) {
    glDeleteTextures(1, &mHandle);
    mHandle = 0;
  }
}
} // jackal