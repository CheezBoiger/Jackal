// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Win32ThreadTest.hpp"
#include "Core/Win32/Win32Thread.hpp"
#include <gtest/gtest.h>



TEST(Win32ThreadTesting, Win32ThreadCreation)
{
  jackal::Win32Thread thr;
}


namespace win32test {


void Run()
{
  // do nothing.
}
} // win32test

