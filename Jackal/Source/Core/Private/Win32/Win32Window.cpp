//
// Copyright (c) Jackal Engine. MIT License.
//
#include "Core/Win32/Win32Window.hpp"
#include "Core/Win32/Win32Thread.hpp"

#include "Core/Logging/Debugging.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Structure/JString.hpp"

// Standard template library temp.
#include <map>


namespace jkl {


std::map<JString, Win32Window *> windows;

void StartWindow(Win32Window *window)
{
  window->wInstance = GetModuleHandle(NULL);

  HWND handle = CreateWindowW(
    JWIN32_CLASSNAME,
    window->wWindowName,
    WS_OVERLAPPEDWINDOW,
    window->x,
    window->y,
    window->width,
    window->height,
    NULL,
    NULL,
    window->wInstance,
    NULL);

  window->handle = handle;
  DWORD style = SetPropW(window->handle, L"JWin32Window", window);

  // Readjust the client window size, because WS_OVERLLAPPED forces win32
  // to make room for the menu tabs above and the borders. This will ensure
  // the the screen size want is EXACTLY what we told the program to make.
  RECT windowRect = { window->x, window->y, window->width, window->height };
  AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, GetMenu(window->handle) != NULL);
  MoveWindow(window->handle, window->x, window->y, 
    windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, FALSE);

  ShowWindow(window->handle, SW_SHOW);
  UpdateWindow(window->handle);
}

void Win32MessagePump(Win32Window *window)
{
  RegisterWin32Class();
  StartWindow(window);

  MSG msg;
  while (!window->requestClose) {
    while ((PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) == TRUE)) { 
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  DestroyWindow(window->handle);
  window->isClosed = true;
  JDEBUG("\nStopped running.\n");
}

DWORD Win32WindowRunFunc(LPVOID d)
{
  Win32Window *window = reinterpret_cast<Win32Window *>(d);
  JDEBUG("window size of %d\n", window->height);
  Win32MessagePump(window);
  return 0;
}


void UpdateClientRect(Win32Window *window)
{
  if (window) {
    RECT rect;
    GetClientRect(window->handle, &rect);
    ClientToScreen(window->handle, (POINT *)&rect.left);
    ClientToScreen(window->handle, (POINT *)&rect.right);
    ClipCursor(&rect);
  } else {
    ClipCursor(NULL);
  }
}


static LRESULT CALLBACK WindowProc(HWND hWnd,
  UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  // Keeps the handle to the window.
  Win32Window *window = 
    reinterpret_cast<Win32Window *>(GetPropW(hWnd, L"JWin32Window"));
  switch (uMsg) {
    case WM_PAINT:
    {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hWnd, &ps);
      EndPaint(hWnd, &ps);
    } break;
    case WM_CLOSE: 
    {
      window->requestClose = true;
    } break;
    case WM_SIZE:
    {
      window->width = LOWORD(lParam);
      window->height = HIWORD(lParam); 
    } break;
  }
  return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}


Win32Window *CreateWin32Window(int32 x, int32 y, int32 width,
  int32 height, LPCWSTR wWindowName, HWND parent)
{
  if (x < 0 || y < 0) {
    Log::MessageToStdOutput(LOG_ERROR, JTEXT(R"(
      Unable to create window due to improper initialization x
      or y offsets.
    )"), true, TARGET_OS_NAME);
    return nullptr;
  }
  if (width <= 0 || height <= 0) {
    Log::MessageToStdOutput(LOG_ERROR, JTEXT(R"(
      Unable to create window due to improper initialization 
      of "width" or "height". 
    )"), true, TARGET_OS_NAME);
    return nullptr;
  }

  Win32Window *window = new Win32Window();

  WCHAR *wTitle = nullptr;

  window->handle = nullptr;
  window->wWindowName = wWindowName;
  window->requestClose = false;
  window->isFullScreen = false;
  window->x = x;
  window->y = y;
  window->width = width;
  window->height = height;
   

  windows[window->wWindowName] = window;
  //std::thread thr(Win32MessagePump, window);
  // Testing Win32 native thread handling through the STL library.
  DWORD id = 0;
  HANDLE thrHandle = CreateThread(NULL, 0, 
    (LPTHREAD_START_ROUTINE )Win32WindowRunFunc, 
    (LPVOID )window, 0,  &id);

  // If planning to join, simply wait for it to finish.  
  //WaitForSingleObject(thrHandle, INFINITE);
  do {
    WaitForSingleObject(GetModuleHandle(NULL), (DWORD )50);
  } while(!window->handle);
  // Release handle to thread.
  CloseHandle(thrHandle);
  return window;
}


bool8 DestroyWin32Window(Win32Window *window)
{
  if (!window) {
    return false;
  }
  if (!window->isClosed) {
    return false;
  }

  auto it = windows.find(window->wWindowName);
  if (it != windows.end()) {
    windows.erase(it);  
  }
  
  delete window;
  window = nullptr;
  return true;
}


void RegisterWin32Class()
{
  WNDCLASSEXW wc;
  ZeroMemory(&wc, sizeof(wc));
  HINSTANCE instance = GetModuleHandle(NULL);

  wc.cbSize = sizeof(wc);
  wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
  wc.hCursor = LoadCursorW(NULL, (LPCWSTR)IDC_ARROW);
  wc.lpszClassName = JWIN32_CLASSNAME;
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = instance;
  wc.hIcon = (HICON)LoadImageW(instance, L"JIcon",
    IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
  // Set to default if no user defined icon exists.
  if (!wc.hIcon) {
    wc.hIcon = (HICON)LoadImageW(NULL, (LPCWSTR)IDI_APPLICATION,
      IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
  }

  if (!RegisterClassExW(&wc)) {
    Log::MessageToStdOutput(LOG_ERROR, JTEXT(R"(
      Unable to register Win32 window class!
    )"), true, TARGET_OS_NAME);
  }
}


void PrintToWin32Console(HANDLE consoleHandle, JString str)
{
  SetConsoleOutputCP(CP_UTF8);

  LPDWORD written = nullptr;
  WriteConsoleW(consoleHandle, str.c_str(),
    (DWORD )str.size(), written, NULL);
}


bool8 InitWin32WindowLibs()
{
  return true;
}


void CleanUpWin32WindowLibs()
{
  for (auto &window : windows) {
    window.second->requestClose = true;
    do {
      WaitForSingleObject(GetModuleHandle(NULL), (DWORD )100);
      if (window.second->isClosed) {
          delete window.second;
          break;
      }
    } while (!window.second->isClosed);
  }

  // Final clear.
  windows.clear();

  JDEBUG("Cleared\n");
}


void RequestCloseWin32Window(Win32Window *window)
{
  window->requestClose = true;
}


bool8 Win32WindowShouldClose(Win32Window *window)
{
  return window->requestClose;
}
} // jkl