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


namespace jackal {


std::map<LPCWSTR, Win32Window *> windows;

void StartWindow(Win32Window *window)
{
  Win32Window::RegisterWin32Class();

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
  UpdateWindow(window->handle);
}

void Win32MessagePump(Win32Window *window)
{
}

DWORD Win32WindowRunFunc(LPVOID d)
{
  Win32Window *window = reinterpret_cast<Win32Window *>(d);
  JDEBUG("window size of %d\n", window->height);
  Win32MessagePump(window);
  return 0;
}


void Win32Window::PollEvents()
{
  MSG msg;
  while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
    if (msg.message == WM_QUIT) {
      for (auto &window : windows) {
        window.second->requestClose = true;
      }
    } else {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }
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
  if (window && window->requestClose) {
    DestroyWindow(window->handle);
    return 0;
  }

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
    // TODO(): Need to get input from keyboard and mouse.
    case WM_MOUSEMOVE:
    {

      // Get Input from the mouse. Store into This client window's 
      // data. This will then be converted to coordinates relative to the 
      // client window.
      POINT cursorPoint;
      if (GetCursorPos(&cursorPoint)) {
        ScreenToClient(window->handle, &cursorPoint);
        window->mouseX = cursorPoint.x;
        window->mouseY = cursorPoint.y;
      } 
    } break;
    case WM_MOVE:
    {
      // Update the window position.
      window->x = (int) (short) LOWORD(lParam);
      window->y = (int) (short) HIWORD(lParam);
    } break;
  }
  return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}


Win32Window *Win32Window::Create(int32 width,
  int32 height, LPCWSTR wWindowName, HWND parent)
{
  if (width <= 0 || height <= 0) {
    Log::MessageToStdOutput(LOG_ERROR, JTEXT(R"(
      Unable to create window due to improper initialization 
      of "width" or "height". 
    )"), true, TARGET_OS_NAME);
    return nullptr;
  }

  // Need to use smart pointer?
  Win32Window *window = new Win32Window();

  WCHAR *wTitle = nullptr;

  window->handle = nullptr;
  window->wWindowName = wWindowName;
  window->requestClose = false;
  window->isFullScreen = false;
  window->x = 0;
  window->y = 0;
  window->width = width;
  window->height = height;
   

  windows[window->wWindowName] = window;

  StartWindow(window);

  return window;
}


bool8 Win32Window::CleanUp()
{

  auto it = windows.find(wWindowName);
  if (it != windows.end()) {
    windows.erase(it);  
  }

  RemovePropW(handle, L"JWin32Window");
  DestroyWindow(handle);
  return true;
}


void Win32Window::RegisterWin32Class()
{
  static bool registered = false;

  if (!registered) {
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
      JDEBUG("%d\n", GetLastError());
    }
    registered = true;
  }
}


void Win32Window::PrintToStdConsole(HANDLE consoleHandle, JString str)
{
  SetConsoleOutputCP(CP_UTF8);

  LPDWORD written = nullptr;

  int32 size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
  wchar_t *wstr = new wchar_t[size];
  MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr, size);
  WriteConsoleW(consoleHandle, wstr,
    (DWORD )str.size(), written, NULL);

  delete[] wstr;
}


bool8 InitWin32WindowLibs()
{
  return true;
}


void Win32CleanUpWindowLibs()
{
  for (auto &window : windows) {
    delete window.second;
  }

  // Final clear.
  windows.clear();

  JDEBUG("Cleared\n");
}


void Win32Window::RequestClose()
{
  requestClose = true;
}


void Win32Window::SetToCenter()
{
  RECT rect;
  GetWindowRect(handle, &rect);

  int32 xPos = (GetSystemMetrics(SM_CXSCREEN) - rect.right) / 2;
  int32 yPos = (GetSystemMetrics(SM_CYSCREEN) - rect.bottom) / 2;
  x = xPos;
  y = yPos;

  SetWindowPos(handle, 0, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
}

void Win32Window::Hide()
{
  ShowWindow(handle, SW_HIDE);
  UpdateWindow(handle);
}


void Win32Window::Show()
{
  ShowWindow(handle, SW_SHOW);
  UpdateWindow(handle);
}
} // jackal