// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Linux/LinuxWindow.hpp"


namespace jackal {


Display *LinuxWindow::display = NULL;
xcb_connection_t *LinuxWindow::connection = NULL;
xcb_screen_t *LinuxWindow::screen = NULL;


// Initialize the X Window server. We are connecting XCB into
// our window in order to easily transition OpenGL and Vulkan.
bool8 InitLinuxXWindows()
{
  LinuxWindow::display = XOpenDisplay(NULL);
  int32 defaultScreen = DefaultScreen(LinuxWindow::display);

  LinuxWindow::connection = XGetXCBConnection(LinuxWindow::display);
  XSetEventQueueOwner(LinuxWindow::display, XCBOwnsEventQueue);

  const xcb_setup_t *setup;
  xcb_screen_iterator_t iter;

  setup = xcb_get_setup(LinuxWindow::connection);
  iter = xcb_setup_roots_iterator(setup);
  
  int32 scr = defaultScreen;
  while (scr-- > 0) {
    xcb_screen_next(&iter);
  }
  
  LinuxWindow::screen = iter.data;
  return true;
}


void LinuxCleanUpXWindows()
{
  XCloseDisplay(LinuxWindow::display);
}

LinuxWindow *LinuxWindow::Create(int32 width, int32 height, 
  const char *lWindowName, Display *dis)
{
  LinuxWindow *window = new LinuxWindow();
  window->x = 0;
  window->y = 0;

  window->height = height;
  window->width = width;
  window->requestClose = false;
  window->requestMinimize = false;
  window->isFullScreen = false;

//  window->win = XCreate
  
  return window;
}
	 
} // jackal
