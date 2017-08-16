// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 

#include "RenderDevice/Texture.hpp"

#include "OpenGLConfigs.hpp"


namespace jackal {


class OpenGLTexture : public Texture {
public:
  OpenGLTexture();
  void Load(TextureInfoT &info, TextureHandle *texture) override;
  void CleanUp() override;


private:

  // Native handle to the OpenGL texture.
  GLuint handle;
};
} // jackal