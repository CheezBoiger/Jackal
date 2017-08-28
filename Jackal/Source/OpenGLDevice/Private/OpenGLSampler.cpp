// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLDevice/OpenGLSampler.hpp"

#include "Core/Logging/Debugging.hpp"


namespace jackal {


GLenum GetNativeWrapMode(WrapModeT mode)
{
  switch (mode) {
    case WRAP_MODE_REPEAT: return GL_REPEAT;
    case WRAP_MODE_MIRRORED_REPEAT: return GL_MIRRORED_REPEAT;
    case WRAP_MODE_CLAMP_TO_EDGE: return GL_CLAMP_TO_EDGE;
    case WRAP_MODE_CLAMP_TO_BORDER: return GL_CLAMP_TO_BORDER;
    default: return GL_CLAMP_TO_BORDER;
  }
}


GLenum GetNativeFilterMode(FilterModeT filter)
{
  switch (filter) { 
    case FILTER_MODE_LINEAR: return GL_LINEAR;
    case FILTER_MODE_NEAREST: return GL_NEAREST;
    default: return GL_LINEAR;
  }
}


GLenum GetNativeFilterModeMin(FilterModeT filter, SamplerMipMapMode mode)
{
  switch (mode) {
    case SAMPLER_MIPMAP_MODE_LINEAR:
    {
      if (filter == FILTER_MODE_LINEAR) return GL_LINEAR_MIPMAP_LINEAR;
      else return GL_NEAREST_MIPMAP_LINEAR;
    } break;
    case SAMPLER_MIPMAP_MODE_NEAREST:
    {
      if (filter == FILTER_MODE_LINEAR) return GL_LINEAR_MIPMAP_NEAREST;
      else return GL_NEAREST_MIPMAP_NEAREST;
    } break;
    default:
    {
      if (filter == FILTER_MODE_LINEAR) return GL_LINEAR;
      else return GL_NEAREST;
    }
  }
}


void OpenGLSampler::Bake(SamplerInfoT &info)
{

  if (mHandle) {
    glDeleteSamplers(1, &mHandle);
  }

  glGenSamplers(1, &mHandle);

  glSamplerParameteri(mHandle, GL_TEXTURE_MAG_FILTER, GetNativeFilterMode(info.MagFilter));
  glSamplerParameteri(mHandle, GL_TEXTURE_MIN_FILTER, GetNativeFilterModeMin(info.MinFilter, info.MipMapMode));
  glSamplerParameteri(mHandle, GL_TEXTURE_WRAP_S, GetNativeWrapMode(info.WrapS));
  glSamplerParameteri(mHandle, GL_TEXTURE_WRAP_T, GetNativeWrapMode(info.WrapT));
  glSamplerParameteri(mHandle, GL_TEXTURE_WRAP_R, GetNativeWrapMode(info.WrapR));

  glSamplerParameterf(mHandle, GL_TEXTURE_MIN_LOD, info.MinLod);
  glSamplerParameterf(mHandle, GL_TEXTURE_MAX_LOD, info.MaxLod);

  if (info.AnisotropyEnable) {
    glSamplerParameterf(mHandle, GL_TEXTURE_MAX_ANISOTROPY_EXT, info.MaxAnisotropy);
    OPENGL_CHECK_ERROR(GLenum error);
    if (error != GL_NO_ERROR) {
      return;  
    }
  }

  
  OPENGL_CHECK_ERROR(GLenum err);

  if (err != GL_NO_ERROR) {
    JDEBUG("Sampler Error!");
  }
}


void OpenGLSampler::CleanUp()
{
  if (mHandle) {
    glDeleteSamplers(1, &mHandle);
    mHandle = 0;
  }
}
} // jackal
