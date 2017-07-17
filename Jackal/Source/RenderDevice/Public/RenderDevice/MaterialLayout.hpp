// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Math/Matrix4.hpp"
#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix2.hpp"

#include "Texture.hpp"
#include "Texture2D.hpp"
#include "Texture3D.hpp"

#include "CubeMap.hpp"
#include "UniformBuffer.hpp"


namespace jackal {


class Texture2D;
class Texture3D;
class Sampler2D;
class Sampler3D;
class CubeMap;
class SamplerCube;

// Material Object, which specifies descriptor sets for 
// some given context on the rendering pipeline. We need
// to set our material inside this layout structure in order to
// to render textures, or update uniform layouts.
class MaterialLayout {
public:
  virtual ~MaterialLayout() { }

  // Add a texture to this material, as well as the sampler that will be
  // used to sample it. Must also provide the index of which to attach the
  // texture onto in rendering unit.
  virtual void SetTexture(Texture *texture, Sampler *sampler, uint32 binding) = 0;
  virtual void SetTexture2D(Texture2D *texture, Sampler2D *sampler, uint32 binding) = 0;
  virtual void SetTexture3D(Texture3D *texture, Sampler3D *sampler, uint32 binding) = 0;
  virtual void SetCubeMap(CubeMap *cubemap, SamplerCube *sampler, uint32 binding) = 0;
  virtual void SetUniformBuffer(UniformBuffer *buffer) = 0;
};
} // jackal