// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/TextureCubeMap.hpp"
#include "OpenGLConfigs.hpp"


namespace jackal {


class OpenGLCubeMap : public CubeMap {
public:
  virtual void Load(TextureInfoT &info, TextureHandle *textures) override;
  virtual void CleanUp() override;

  GLuint Handle() { return mHandle; }

private:
  GLuint mHandle;
};
} // jackal