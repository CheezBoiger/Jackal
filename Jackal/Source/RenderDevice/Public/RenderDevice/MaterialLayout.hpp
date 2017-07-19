// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Math/Matrix4.hpp"
#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix2.hpp"

#include "Sampler.hpp"
#include "Texture.hpp"
#include "Texture2D.hpp"
#include "Texture3D.hpp"

#include "TextureCubeMap.hpp"
#include "UniformBuffer.hpp"


namespace jackal {


class Texture2D;
class Texture3D;
class CubeMap;

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
  virtual void BindTexture(Sampler *sampler, Texture *texture, uint32 binding) = 0;
  virtual void BindTexture2D(Sampler *sampler, Texture2D *texture, uint32 binding) = 0;
  virtual void BindTexture3D(Sampler *sampler, Texture3D *texture, uint32 binding) = 0;
  virtual void BindCubeMap(Sampler *sampler, CubeMap *cube, uint32 binding) = 0;
  virtual void BindUniformBuffer(UniformBuffer *buffer, uint32 binding) = 0;
};
} // jackal