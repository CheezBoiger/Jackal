// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDevice/UniformBuffer.hpp"

#include "OpenGLConfigs.hpp"

#include <list>
#include <string>
#include <memory>


namespace jackal {


// OpenGL Native Uniform Buffer.
class OpenGLUniformBuffer : public UniformBuffer { 
public:
  OpenGLUniformBuffer()
    : ubo(0) { }

  void Initialize(UniformBufferCreateInfoT& info) override;
  void* Map() override;
  void UnMap() override;
  void CleanUp() override;

  GLuint Handle() const { return ubo; }

private:  
  // OpenGL native buffer object handle.
  GLuint ubo;
};
} // jackal