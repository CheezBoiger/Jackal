//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "platform.hpp"
#include "jtypes.hpp"

namespace jkl {


// Monitor device, specifies the application's monitors in use for 
// the game engine.
class Monitor {
public:
  virtual ~Monitor() { }
private:
};


// Window abstract of the core library. All windows are used here,
// so the implementation is based on which Operating system the user
// is in.
struct IWindow {
  virtual ~IWindow() { }

  virtual void Resize(uint32 width, uint32 height) = 0;
  virtual bool8 IsMouseInWindow(int32 x, int32 y) = 0;

  virtual void Cleanup() = 0;

  void *ExtractOwner() const { return owner; };

  int32 xOffset;
  int32 yOffset;
  int32 width;
  int32 height;
  void *owner;
};


// Creates a window use with the renderer API. Must specify accurate width and height of the window,
// along with optional title, monitor , and sharing window.
IWindow *CreateWindow(uint32 width, uint32 height, const char *title, 
  Monitor *monitor = nullptr, IWindow *sharing = nullptr);

bool8 DestroyWindow(IWindow *window);

void MakeContextCurrent(IWindow *window);

IWindow *GetCurrentContext();

void SwapBuffers(IWindow *window);
} // jkl