// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Window.hpp"





namespace jkl {


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
  static void SwapWindowBuffers(Win32Window *window);


  // Initialize WGL library.
  static void InitWGL();

  // Delete the OpenGL Context.
  static void DeleteOpenGLContext(Win32Window *window);

  // Make the Context generated to the current window that is being
  // rendered.
  static void MakeContextCurrent(Win32Window *window);
};
} // jkl