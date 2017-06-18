// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Math/QuatTest.hpp"
#include "Core/Memory/MemoryTest.hpp"
#include "Core/Structure/JStringTest.hpp"

#if defined(_WIN32)
 #define TEST_WINDOWS
 #include "Core/Win32/Win32ThreadTest.hpp"
 #include "Core/Win32/Win32WindowTest.hpp"
#elif defined(__linux__)
 #define TEST_LINUX
 #include "Core/Linux/LinuxWindowTest.hpp"
#elif defined(__APPLE__) && defined(__MACH__)

#endif

#include "gtest/gtest.h"

#include "Core/Math/MatrixTest.hpp"
#include <iostream>

int main(int c, char *argv[]) {
  ::testing::InitGoogleTest(&c, argv);

  // Common Core testing.
  coretest::QuaternionTesting();
  coretest::MatrixTesting();
  coretest::MemoryTesting();
  coretest::JStringTesting();


#if defined(TEST_WINDOWS)
  win32test::Run();
  win32test::WindowTest();
#elif defined(TEST_LINUX)
  linuxtest::RunWindowsTest();
#elif defined(TEST_APPLE)


#else


#endif

  int success = RUN_ALL_TESTS();

  std::cout << "Press Enter to continue...\n";
  std::cin.ignore();
  return success;
}
