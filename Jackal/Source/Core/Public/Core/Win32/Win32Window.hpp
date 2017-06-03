// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/Window.hpp"
#include <Windows.h>


#define JWIN32_CLASSNAME L"JACKALWINDOW"

namespace jkl {


struct Win32WindowLibs {
} windowLibs;


// win32 specific window. Contains all necessities that govern 
// this window for the Windows 7, 8, and 10 platforms.
struct Win32Window : IWindow {
  HWND        wParent;
  HWND        handle;
  HINSTANCE   wInstance;
  HMENU       wMenu;
  LPCSTR      wWindowName;
  bool8       requestClose;
  bool8       requestMinimize;
};


Win32Window *CreateWin32Window(int32 x, int32 y, int32 width, 
  int32 height, LPCSTR wWindowName, HWND parent);

Win32Window *GetParentWindow(Win32Window *child);

Win32Window *RequestCloseWin32Window(Win32Window *window);

bool8 DestroyWin32Window(Win32Window *window);

void RegisterWin32Class();
} // jkl