//
// Copyright (c) Jackal Engine. MIT License.
//
#include "Core/Win32/Win32Window.hpp"
#include "Core/Logging/Logger.hpp"

namespace jkl {


static LRESULT CALLBACK WindowProc(HWND hWnd,
  UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  Win32Window *win32Window = (Win32Window *)GetPropW(hWnd, L"JWin32Window");
  if (!win32Window) {
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
  }
  // for now.
  return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}


Win32Window *CreateWin32Window(int32 x, int32 y, int32 width,
  int32 height, LPCSTR wWindowName, HWND parent)
{
  if (x < 0 || y < 0) {
    Log::MessageToConsole(LOG_ERROR, R"(
      Unable to create window due to improper initialization x
      or y offsets.
    )", true, TARGET_OS_NAME);
    return nullptr;
  }
  if (width <= 0 || height <= 0) {
    Log::MessageToConsole(LOG_ERROR, R"(
      Unable to create window due to improper initialization 
      of "width" or "height". 
    )", true, TARGET_OS_NAME);
    return nullptr;
  }
  Win32Window *window = new Win32Window();

  WCHAR *wTitle;
  DWORD style = SetPropW(window->handle, L"JWin32Window", window);
  return window;
}


bool8 DestroyWin32Window(Win32Window *window)
{
  if (!window) {
    return false;
  }
  return true;
}


void RegisterWin32Class()
{
  WNDCLASSEXW wc;
  ZeroMemory(&wc, sizeof(wc));
  HINSTANCE instance = GetModuleHandle(NULL);

  wc.cbSize = sizeof(wc);
  wc.hCursor = LoadCursorW(NULL, (LPCWSTR)IDC_ARROW);
  wc.lpszClassName = JWIN32_CLASSNAME;
  wc.lpfnWndProc = WindowProc;
  wc.hIcon = (HICON)LoadImageW(instance, L"JIcon",
    IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
  // Set to default if no user defined icon exists.
  if (!wc.hIcon) {
    wc.hIcon = (HICON)LoadImageW(NULL, (LPCWSTR)IDI_APPLICATION,
      IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
  }

  if (!RegisterClassExW(&wc)) {
    Log::MessageToConsole(LOG_ERROR, R"(
      Unable to register Win32 window class!
    )", true, TARGET_OS_NAME);
  }
}
} // jkl