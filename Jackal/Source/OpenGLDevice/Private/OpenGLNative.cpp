// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLDevice/OpenGLNative.hpp"

#include "Core/Logging/Assertions.hpp"
#include "Core/Logging/Debugging.hpp"

namespace jackal {


GLNativeTextureFormat OpenGLNative::GetNativeTextureFormat(FormatT format)
{
  switch (format) {

    // TODO(): Add in cases for each format type.

  default: return { GL_RGBA, GL_UNSIGNED_INT, GL_RGBA };
  }
}
} // jackal