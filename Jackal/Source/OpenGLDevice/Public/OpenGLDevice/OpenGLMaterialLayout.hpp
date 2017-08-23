// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Core/Platform/JTypes.hpp"

#include "RenderDevice/MaterialLayout.hpp"


namespace jackal {


class OpenGLMaterialLayout : public MaterialLayout {
public:
  // Add a texture to this material, as well as the sampler that will be
  // used to sample it. Must also provide the index of which to attach the
  // texture onto in rendering unit.
  void BindTexture(Sampler *sampler, Texture *texture, uint32 binding) override;
  void BindTexture2D(Sampler *sampler, Texture2D *texture, uint32 binding) override;
  void BindTexture3D(Sampler *sampler, Texture3D *texture, uint32 binding) override;
  void BindCubeMap(Sampler *sampler, CubeMap *cube, uint32 binding) override;
  void BindUniformBuffer(UniformBuffer* buffer, uint32 binding) override;

  // Inialize our binding points into the pipeline.
  void Initialize() override;
  void Update() override;
  void CleanUp() override;
};
} // jackal