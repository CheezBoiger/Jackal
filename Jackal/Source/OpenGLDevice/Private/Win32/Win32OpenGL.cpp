// Copyright (c) 2017 Jackal Engine, MIT License
#include "OpenGLDevice/Win32/Win32OpenGL.hpp"

#include "Core/Platform/Api.hpp"
#include "Core/Logging/Debugging.hpp"
#include "Core/Logging/Logger.hpp"



PFNWGLCREATECONTEXTATTRIBSARBPROC     wglCreateContextAttribs;
PFNWGLCHOOSEPIXELFORMATARBPROC        wglChoosePixelFormat;
PFNWGLGETEXTENSIONSSTRINGARBPROC      wglGetExtensionsString;

// Load our wiggle functions.
template<typename T>
void LoadWGLFunction(T &func, char *name)
{
  func = (T )wglGetProcAddress(name);
}

#define WGL_LOAD(name) LoadWGLFunction(name, #name "ARB") 

namespace jackal {


Win32Window *Win32OpenGL::mDummy = nullptr;


void Win32OpenGL::SetOpenGLContext(Win32Window *window)
{
  if (window) {
    const int attribs[] = {
      WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
      WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
      WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
      WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
      WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,
      WGL_COLOR_BITS_ARB,     32,
      WGL_ALPHA_BITS_ARB,     8,
      WGL_DEPTH_BITS_ARB,     24,
      WGL_STENCIL_BITS_ARB,   8,
      WGL_SAMPLES_ARB,        4,
      0 // To signal end of reading to wgl.
    };

    HDC hDC = GetDC(window->handle);
    int pFmt;
    UINT numFormats;
    if (FALSE == wglChoosePixelFormat(hDC, attribs, 0, 1, &pFmt, &numFormats)) {
      MessageBoxW(window->handle, L"Failed to choose pixel format.", L"", MB_OK);
      return;
    }
    PIXELFORMATDESCRIPTOR pfd;
    DescribePixelFormat(hDC, pFmt, sizeof(pfd), &pfd);
    SetPixelFormat(hDC, pFmt, &pfd);

    int contextAttribs[] = {
      WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
      WGL_CONTEXT_MINOR_VERSION_ARB, 5,
      WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
      0
    };

    HGLRC rctx = wglCreateContextAttribs(hDC, 0, contextAttribs);
    if (rctx == NULL) {
      return;
    }

    // TODO(): Need to handle our render context in a structure.
    // Currently relying on wgl to hold our current context, which
    // may cause leaks in the future.
    wglMakeCurrent(hDC, rctx);
  }
}


void Win32OpenGL::SwapBuffers(Win32Window *window)
{
  if (window) {
    HDC hDC = GetDC(window->handle);
    ::SwapBuffers(hDC);
  }
}


void Win32OpenGL::InitWGLExtensions()
{
  static bool extInit = false;
  if (!extInit) {
    WGL_LOAD(wglChoosePixelFormat);
    WGL_LOAD(wglCreateContextAttribs);
    WGL_LOAD(wglGetExtensionsString);
  }
  extInit = true;
}


void Win32OpenGL::MakeContextCurrent(Win32Window *window)
{
  if (window) {
    wglMakeCurrent(GetDC(window->handle), wglGetCurrentContext());
  } else {
    wglMakeCurrent(NULL, NULL);
  }
}


void Win32OpenGL::Initialize()
{
  mDummy = Win32Window::Create(1, 1, L"dummy", nullptr);
  PIXELFORMATDESCRIPTOR pfd;
  int pf;
  // NOTE(): Dummy window is set in order to query our native wgl
  // functions, for modern initialization of OpenGL windows.
  JDEBUG("DC\n");
  HDC mDummyHDC = GetDC(mDummy->handle);

  ZeroMemory(&pfd, sizeof(pfd));
  pfd.nSize = sizeof(pfd);
  pfd.nVersion = 1;
  pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
  pfd.iPixelType = PFD_TYPE_RGBA;
  pfd.cColorBits = 24;
  JDEBUG("PixelFormat choose\n");
  pf = 1; //ChoosePixelFormat(mDummyHDC, &pfd);

  if (pf == 0) {
    MessageBoxW(mDummy->handle,
      JTEXT("Failed to choose proper pixel format."), JTEXT("Failed"), MB_OK);
    return;
  }
  JDEBUG("Set Pixel Format\n");
  SetPixelFormat(mDummyHDC, pf, 0);
  JDEBUG("%d\n", GetLastError());
  HGLRC renderContext = wglCreateContext(mDummyHDC);

  // Create dummy context.
  wglMakeCurrent(mDummyHDC, renderContext);
  InitWGLExtensions();
  JDEBUG("Finished OpenGL init for Windows... Cleaning up dummy context.\n");

  wglMakeCurrent(mDummyHDC, NULL);
  wglDeleteContext(renderContext);
  ReleaseDC(mDummy->handle, mDummyHDC);
}


void Win32OpenGL::CleanUp()
{
  mDummy->CleanUp();
  delete mDummy;
}
} // jackal