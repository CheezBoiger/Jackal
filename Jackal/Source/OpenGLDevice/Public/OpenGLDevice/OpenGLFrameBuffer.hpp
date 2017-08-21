// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDevice/FrameBuffer.hpp"

#include "OpenGLConfigs.hpp"


namespace jackal {


class OpenGLFrameBuffer : public FrameBuffer {
public:
  OpenGLFrameBuffer()
    : mHandle(0) { }

  void Bake(const FrameBufferCreateInfoT& info) override;
  void CleanUp() override;

  GLint Handle() const { return mHandle; }

private:
  GLuint mHandle;
};
} // jackal