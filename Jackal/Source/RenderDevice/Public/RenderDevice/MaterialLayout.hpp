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
#include "RenderObject.hpp"


namespace jackal {


class Texture2D;
class Texture3D;
class CubeMap;
class UniformBuffer;
class StorageBuffer;


struct TextureBind {
  Texture* pTexture;
  Sampler* pSampler;
  uint32    Binding;
};


struct Texture2DBind {
  Texture2D* pTexture;
  Sampler* pSampler;
  uint32    Binding;
};


struct Texture3DBind {
  Texture3D* pTexture;
  Sampler* pSampler;
  uint32    Binding;
};


struct TextureCubeMapBind {
  CubeMap* pCubMap;
  Sampler* pSampler;
  uint32    Binding;
};


struct UniformBufferBind {
  UniformBuffer* Ubo;
  uint32 Binding;
};


struct StorageBufferBind {
  StorageBuffer* pStorageBuffer;
  uint32 Binding;
};


struct MaterialLayoutCreateInfoT {
  uint32 TextureCount;
  TextureBind* TextureBinds;
  uint32 Texture2DCount;
  Texture2DBind* Texture2DBinds;
  uint32 Texture3DCount;
  Texture3DBind* Texture3DBinds;
  uint32 TextureCubeMapCount;
  TextureCubeMapBind* TextureCubeMapBinds;
  uint32 UniformBufferCount;
  UniformBufferBind* UniformBuffers;
  uint32 StorageBufferCount;
  StorageBufferBind* StorageBuffers;
};

// Material Object, which specifies descriptor sets for 
// some given context on the rendering pipeline. We need
// to set our material inside this layout structure in order to
// to render textures, or update uniform layouts.
class MaterialLayout : public RenderObject {
public:
  virtual ~MaterialLayout() { }

  // Inialize our binding points into the pipeline.
  virtual void Initialize(MaterialLayoutCreateInfoT& info) = 0;
  virtual void CleanUp() = 0;
};
} // jackal