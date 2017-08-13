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
  

  void Bake(FrameBufferCreateInfoT& info) override;

  GLint Handle() const { return mHandle; }

private:
  GLint mHandle;
};
} // jackal