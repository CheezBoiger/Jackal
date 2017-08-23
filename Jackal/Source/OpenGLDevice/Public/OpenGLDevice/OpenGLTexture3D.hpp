// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "OpenGLConfigs.hpp"

#include "RenderDevice/Texture3D.hpp"


namespace jackal {


class OpenGLTexture3D : public Texture3D {
public:
  OpenGLTexture3D()
    : mHandle(0) { }

  void Load(TextureInfoT& info, TextureHandle* texture) override;
  void CleanUp() override;

  GLuint Handle() const { return mHandle; }

private:
  GLuint mHandle;
}; 
} // jackal