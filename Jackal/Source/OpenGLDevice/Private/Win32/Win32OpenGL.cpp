// Copyright (c) 2017 Jackal Engine, MIT License
#include "OpenGLDevice/Win32/Win32OpenGL.hpp"
#include "Core/Win32/Win32Config.hpp"

#include "Core/Platform/Api.hpp"
#include "Core/Logging/Debugging.hpp"
#include "Core/Logging/Logger.hpp"



typedef BOOL (APIENTRY * PFNWGLCHOOSEPIXELFORMAT)(HDC, 
  const int *, const FLOAT *, UINT, int *, UINT *);
PFNWGLCHOOSEPIXELFORMAT wglChoosePixelFormatARB;

namespace jackal {



void Win32OpenGL::SetOpenGLContext(Win32Window *window)
{
  InitWGL();
  if (window) {
    PIXELFORMATDESCRIPTOR pfd;
    int pf;
    // TODO(): Need to set this on a seperate call, in order to avoid calling
    // ChoosePixelFormat, as it is slow.
    JDEBUG("DC\n");
    HDC hDC = GetDC(window->handle);
    memset(&pfd, 0, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 32;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;
    JDEBUG("PixelFormat choose\n");
    pf = ChoosePixelFormat(hDC, &pfd);
 
    if (pf == 0) {
      MessageBoxW(window->handle, 
        JTEXT(L"Failed to choose proper pixel format."), JTEXT(L"Failed"), MB_OK);
      return;
    }
    JDEBUG("Set Pixel Format\n");
    SetPixelFormat(hDC, pf, &pfd);
    
   
    HGLRC renderContext = wglCreateContext(hDC);
    wglMakeCurrent(hDC, renderContext);
  }
}


void Win32OpenGL::SwapWindowBuffers(Win32Window *window)
{
  if (window) {
    HDC hDC = GetDC(window->handle);
    SwapBuffers(hDC);
  }
}


void Win32OpenGL::InitWGL()
{
  wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMAT )
    wglGetProcAddress("wglChoosePixelFormatARB");
}


void Win32OpenGL::MakeContextCurrent(Win32Window *window)
{
  if (window) {
    wglMakeCurrent(GetDC(window->handle), wglGetCurrentContext());
  } else {
    wglMakeCurrent(NULL, NULL);
  }
}
} // jackal