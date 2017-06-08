// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Window.hpp"





namespace jkl {


// Set the window Context to OpenGL. This will link OpenGL
// To the win32 window application.
void SetWin32WindowOpenGLContext(Win32Window *window);

// Call Swap Buffers to swap the back buffer with the front,
// in order to avoid drawing on the screen directly and looking
// visually unpleasing.
void Win32SwapBuffers(Win32Window *window);


// Initialize WGL library.
void InitWGL();

// Delete the OpenGL Context.
void DeleteWin32OpenGLContext(Win32Window *window);

// Make the Context generated to the current window that is being
// rendered.
void Win32WindowMakeContextCurrent(Win32Window *window);
} // jkl