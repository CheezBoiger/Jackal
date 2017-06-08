// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Window.hpp"





namespace jkl {



// Set the window Context to OpenGL.
void SetWin32WindowOpenGLContext(Win32Window *window);

void Win32SwapBuffers(Win32Window *window);

void InitWGL();
} // jkl