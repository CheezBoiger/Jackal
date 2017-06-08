// Copyright (c) 2017 Jackal Engine, MIT License.


#include "OpenGLConfigs.hpp"
#include "OpenGLDevice/OpenGLDevice.hpp"
#include "Core/Logging/Debugging.hpp"

namespace jkl {



bool8 OpenGLDevice::InitOpenGL()
{
  bool8 success = gladLoadGL();
  JDEBUG("OpenGL init: %d\n", success);
  return success;
}
} // jkl