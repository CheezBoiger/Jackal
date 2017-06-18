// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Window.hpp"
#include "Core/Platform/JTypes.hpp"

#include "Core/Linux/LinuxConfig.hpp"

// X Windows Library configuration.
#include <X11/Xlib.h>
#include <X11/X.h>

extern "C" {
#include <X11/Xlib-xcb.h>
}
#include <xcb/xcb.h>

namespace jackal {

// Linux window creation. Contains necessities that
// govern the X Window Server on your Linux machine.
struct LinuxWindow : public Window {
  // Current display to the X Window server.
  static Display *display;
  static xcb_connection_t *connection;
  static xcb_screen_t *screen;


  int32      x, y;
  int32      width, height;
  Window     win;
  GC         gc;

  bool8      requestClose    : 1;
  bool8      requestMinimize : 1;
  bool8      isFullScreen    : 1;


  static LinuxWindow *Create(int32 width, int32 height, const char *lWindowName, Display *dis);
  bool8 Destroy();

  static void PollEvents();
};

bool8 InitLinuxXWindows();
void LinuxCleanUpXWindows();
} // jackal

