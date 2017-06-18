// Copyright (c) 2017 Jackal Engine, MIT License.
#include <gtest/gtest.h>
#include "LinuxWindowTest.hpp"
#include "Core/Linux/LinuxWindow.hpp"


TEST(LinuxWindowTesting, LinuxWindowCreation)
{
  jackal::InitLinuxXWindows();

  jackal::LinuxCleanUpXWindows();
}


namespace linuxtest {


void RunWindowsTest()
{
  // do nothing.
}
} // linuxtest
