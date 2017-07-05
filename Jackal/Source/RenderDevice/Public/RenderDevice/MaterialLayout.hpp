// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Math/Matrix4.hpp"
#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix2.hpp"

#include "Texture.hpp"
#include "CubeMap.hpp"


namespace jackal {


// Material Object, which specifies descriptor sets for 
// some given context on the rendering pipeline.
class MaterialLayout {
public:
  virtual ~MaterialLayout() { }

  // Add a texture to this material, as well as the sampler that will be
  // used to sample it. Must also provide the index of which to attach the
  // texture onto in rendering unit.
  virtual void SetTexture(Texture *texture, Sampler *sampler, int32 binding) = 0;

  virtual void SetCubeMap(CubeMap *cubemap, int32 binding) = 0;
};
} // jackal