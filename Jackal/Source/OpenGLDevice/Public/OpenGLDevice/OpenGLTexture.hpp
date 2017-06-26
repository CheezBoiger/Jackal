// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 

#include "RenderDevice/Texture.hpp"


namespace jackal {


class OpenGLSampler : public Sampler {
public:
  
};


class OpenGLTexture : public Texture {
public:
  OpenGLTexture();
  void LoadTextureFile(const JString filepath, FormatT format) override;
};
} // jackal