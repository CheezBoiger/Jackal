// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 

#include "RenderDevice/Texture.hpp"


namespace jackal {


class OpenGLSampler : public Sampler {
public:
  

private:
  
  // Handle to the OpenGL sampler.
  GLuint handle;
};


class OpenGLTexture : public Texture {
public:
  OpenGLTexture();
  void LoadTextureFile(const JString filepath, FormatT format) override;


private:

  // Native handle to the OpenGL texture.
  GLuint handle;
};
} // jackal