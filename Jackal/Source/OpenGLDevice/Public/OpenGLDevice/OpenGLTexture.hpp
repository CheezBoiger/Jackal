// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 

#include "RenderDevice/Texture.hpp"

#include "OpenGLConfigs.hpp"


namespace jackal {


class OpenGLTexture : public Texture {
public:
  OpenGLTexture()
    : handle(0) { }

  void Load(TextureInfoT &info, TextureHandle *texture) override;
  void CleanUp() override;

  GLuint Handle() { return handle; }

private:

  // Native handle to the OpenGL texture.
  GLuint handle;
};
} // jackal