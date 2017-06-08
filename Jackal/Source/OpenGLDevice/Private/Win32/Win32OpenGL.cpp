// Copyright (c) 2017 Jackal Engine, MIT License
#include "OpenGLDevice/Win32/Win32OpenGL.hpp"
#include "Core/Win32/Win32Config.hpp"

#include "Core/Platform/Api.hpp"
#include "Core/Logging/Debugging.hpp"
#include "Core/Logging/Logger.hpp"


namespace jkl {



void SetWin32WindowOpenGLContext(Win32Window *window)
{
  if (window) {
    PIXELFORMATDESCRIPTOR pfd;
    int pf;

    // sample.
    JDEBUG("DC\n");
    HDC hDC = GetDC(window->handle);
    memset(&pfd, 0, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    JDEBUG("PixelFormat choose\n");
    pf = ChoosePixelFormat(hDC, &pfd);
    if (pf == 0) {
      MessageBoxW(window->handle, 
        JTEXT("Failed to choose proper pixel format."), JTEXT("Failed"), MB_OK);
      return;
    }
    JDEBUG("Set Pixel Format\n");
    SetPixelFormat(hDC, pf, &pfd);
    
    HGLRC renderContext = wglCreateContext(hDC);
    wglMakeCurrent(hDC, renderContext);
  }
}


void Win32SwapBuffers(Win32Window *window)
{
  if (window) {
    HDC hDC = GetDC(window->handle);
    SwapBuffers(hDC);
  }
}
} // jkl