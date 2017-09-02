// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLMaterialLayout.hpp"
#include "OpenGLUniformBuffer.hpp"

namespace jackal {


void OpenGLMaterialLayout::Initialize(MaterialLayoutCreateInfoT& info)
{
  mInfo.StorageBufferCount = info.StorageBufferCount;
  mInfo.Texture2DCount = info.Texture2DCount;
  mInfo.TextureCount = info.TextureCount;
  mInfo.Texture3DCount = info.Texture3DCount;
  mInfo.UniformBufferCount = info.UniformBufferCount;

  if (mInfo.UniformBufferCount) {
    mInfo.UniformBuffers = new UniformBufferBind[mInfo.UniformBufferCount];
    for (uint32 i = 0; i < mInfo.UniformBufferCount; ++i) {
      UniformBufferBind& bind = mInfo.UniformBuffers[i];
      UniformBufferBind& cpy = info.UniformBuffers[i];
      
      bind.Binding = cpy.Binding;
      bind.Ubo = cpy.Ubo;
    }
  }

  if (mInfo.Texture2DCount) {
    mInfo.Texture2DBinds = new Texture2DBind[mInfo.Texture2DCount];
    for (uint32 i = 0; i < mInfo.Texture2DCount; ++i) {
      Texture2DBind& bind = mInfo.Texture2DBinds[i];
      Texture2DBind& cpy = info.Texture2DBinds[i];
    
      bind.Binding = cpy.Binding;
      bind.pSampler = cpy.pSampler;
      bind.pTexture = cpy.pTexture;
    }
  }
}


void OpenGLMaterialLayout::CleanUp()
{
  if (mInfo.UniformBufferCount) {
    delete[] mInfo.UniformBuffers;
    mInfo.UniformBuffers = nullptr;
    mInfo.UniformBufferCount;  
  }

  if (mInfo.Texture2DCount) {
    delete[] mInfo.Texture2DBinds;
    mInfo.Texture2DBinds = nullptr;
    mInfo.Texture2DCount = 0;
  }
}
} // jackal