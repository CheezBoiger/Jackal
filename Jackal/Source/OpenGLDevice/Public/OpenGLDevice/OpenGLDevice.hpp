// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/RenderDevice.hpp"


namespace jkl {


// OpenGL Rendering Device. This Device handles all 
// Rendering calls, creation, and modification of OpenGL 
// Rendering functionality. It should act as a RHI, or 
// Rendering Hardware Interface implementation of OpenGL.
class OpenGLDevice : public RenderDevice {
public:
  // Initialize OpenGL library for first time.
  // This must be called if you plan on using OpenGL.
  static bool8 InitOpenGL();


private:
};
} // jkl