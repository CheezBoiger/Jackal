// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "OpenGLConfigs.hpp"


namespace jackal {


class OpenGLFrameBuffer {
public:
  OpenGLFrameBuffer()
    : mHandle(0) { }

  void Create();
  void Bind();
  void CleanUp();
  bool Complete();

  GLint Handle() const { return mHandle; }

private:
  GLuint mHandle;
};
} // jackal