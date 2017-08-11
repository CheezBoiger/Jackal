// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLRenderTarget.hpp"


namespace jackal {


void OpenGLRenderTarget::Bake(RenderTargetCreateInfoT& information)
{
  RenderTarget::Bake(information);
  if (mHandle) {
    glDeleteTextures(1, &mHandle);
    mHandle = 0;
  }

  glGenTextures(1, &mHandle);
  
  
}
} // jackal