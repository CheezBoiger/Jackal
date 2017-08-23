// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLMaterialLayout.hpp"
#include "OpenGLUniformBuffer.hpp"

namespace jackal {


void OpenGLMaterialLayout::Initialize()
{
}


void OpenGLMaterialLayout::Update()
{
}


void OpenGLMaterialLayout::CleanUp()
{
}


void OpenGLMaterialLayout::BindTexture(Sampler* sampler, Texture* texture, uint32 binding)
{
}


void OpenGLMaterialLayout::BindTexture2D(Sampler* sampler, Texture2D* texture, uint32 binding)
{
}


void OpenGLMaterialLayout::BindTexture3D(Sampler* sampler, Texture3D* texture, uint32 binding)
{
}


void OpenGLMaterialLayout::BindCubeMap(Sampler* sampler, CubeMap* cube, uint32 binding)
{
}


void OpenGLMaterialLayout::BindUniformBuffer(UniformBuffer* buffer, uint32 binding)
{
}
} // jackal