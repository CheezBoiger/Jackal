// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 


#include "RenderDevice/Texture2D.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"

#include "OpenGLConfigs.hpp"

namespace jackal {


class OpenGLTexture2D : public Texture2D {
public:
  OpenGLTexture2D()
    : mHandle(0) { }

  void Load(TextureInfoT& info, TextureHandle* texture) override;
  void CleanUp() override;

private:
  GLuint mHandle;
};
} // jackal