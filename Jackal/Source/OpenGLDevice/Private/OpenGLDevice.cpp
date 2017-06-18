// Copyright (c) 2017 Jackal Engine, MIT License.


#include "OpenGLDevice/OpenGLDevice.hpp"
#include "Core/Logging/Debugging.hpp"

namespace jackal {


const tchar *OpenGLDevice::renderAPI = JTEXT("OpenGL");

bool8 OpenGLDevice::InitOpenGL()
{
  bool8 success = gladLoadGL();
  JDEBUG("OpenGL init: %d\n", success);
  return success;
}
} // jackal