// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/Window.hpp"
#include "Core/Win32/Win32Config.hpp"
#include "Core/Structure/JString.hpp"

#define JWIN32_CLASSNAME L"JACKALWINDOW"

namespace jackal {


// win32 specific window. Contains all necessities that govern 
// this window for the Windows 7, 8, and 10 platforms.
struct Win32Window : public Window {
  int32       x, y;
  int32       width, height;
  HWND        wParent;
  HWND        handle;
  HINSTANCE   wInstance;
  HMENU       wMenu;
  LPCWSTR     wWindowName;

  bool8       requestClose    : 1;
  bool8       requestMinimize : 1;
  bool8       isFullScreen    : 1;

  static Win32Window *Create(int32 width,
    int32 height, LPCWSTR wWindowName, HWND parent);
  
  Win32Window *GetParent();

  bool8 Destroy();

  void RequestClose();
  
  // Set the window to the center of the screen.
  void SetToCenter();

  bool8 ShouldClose() {
    return requestClose;
  }

  static void PrintToStdConsole(HANDLE consoleHandle, JString str);
  static void RegisterWin32Class();
  static void PollEvents();
};


bool8 InitWin32WindowLibs();
void Win32CleanUpWindowLibs();
} // jackal