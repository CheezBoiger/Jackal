// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Core/Platform/JTypes.hpp"

#include "RenderDevice/MaterialLayout.hpp"


namespace jackal {


class OpenGLMaterialLayout : public MaterialLayout {
public:
  OpenGLMaterialLayout()
  {
    mInfo.StorageBufferCount = 0;
    mInfo.Texture2DCount = 0;
    mInfo.Texture3DCount = 0;
    mInfo.TextureCount = 0;
    mInfo.TextureCubeMapCount = 0;
    mInfo.UniformBufferCount = 0;
  }

  // Inialize our binding points into the pipeline.
  void Initialize(MaterialLayoutCreateInfoT& info) override;
  void CleanUp() override;

  MaterialLayoutCreateInfoT& Information() { return mInfo; }

private:
  MaterialLayoutCreateInfoT mInfo;
};
} // jackal