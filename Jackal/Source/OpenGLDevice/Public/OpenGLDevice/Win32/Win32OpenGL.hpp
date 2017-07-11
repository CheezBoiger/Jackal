// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Config.hpp"
#include "Core/Win32/Win32Window.hpp"

// wgl extensions and support.
#include <gl/GL.h>
#include "wglext.hpp"



  

namespace jackal {


// Win32 OpenGL class singleton, is used to handle opengl specific features 
// For Win32 windows. 
class Win32OpenGL {
public:

  // Set the window Context to OpenGL. This will link OpenGL
  // To the win32 window application.
  static void SetOpenGLContext(Win32Window *window);

  // Call Swap Buffers to swap the back buffer with the front,
  // in order to avoid drawing on the screen directly and looking
  // visually unpleasing.
  static void SwapBuffers(Win32Window *window);


  // Initialize WGL library.
  static void InitWGLExtensions();

  // Delete the OpenGL Context.
  static void DeleteOpenGLContext(Win32Window *window);

  // Make the Context generated to the current window that is being
  // rendered.
  static void MakeContextCurrent(Win32Window *window);


  static void Initialize();
  static void CleanUp();

private:

  // Dummy window handle.
  static Win32Window *mDummy;
};
} // jackal