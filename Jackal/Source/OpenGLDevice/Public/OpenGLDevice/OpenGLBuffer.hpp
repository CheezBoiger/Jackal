// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "OpenGLConfigs.hpp"

#include "RenderDevice/Buffer.hpp"

#include "Core/Platform/JTypes.hpp"


namespace jackal {


class OpenGLBuffer : public Buffer {
public:
  OpenGLBuffer()
    : mHandle(0) { }
  
  void**    Map(uint32 size, uint32 offset) override;
  void      UnMap() override;

private:
  GLuint mHandle;
};
} // jackal