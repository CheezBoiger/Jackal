// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/Window.hpp"
#include "Core/Win32/Win32Config.hpp"
#include "Core/Structure/JString.hpp"

#define JWIN32_CLASSNAME L"JACKALWINDOW"

namespace jkl {


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
};


// Initialize the Window Library.
bool8 InitWin32WindowLibs();

Win32Window *CreateWin32Window(int32 x, int32 y, int32 width, 
  int32 height, LPCWSTR wWindowName, HWND parent);

Win32Window *GetParentWindow(Win32Window *child);

void RequestCloseWin32Window(Win32Window *window);

bool8 DestroyWin32Window(Win32Window *window);

bool8 Win32WindowShouldClose(Win32Window *window);

void PrintToWin32Console(HANDLE consoleHandle, JString str);

void RegisterWin32Class();

void Win32WindowPollEvents();

void CleanUpWin32WindowLibs();
} // jkl