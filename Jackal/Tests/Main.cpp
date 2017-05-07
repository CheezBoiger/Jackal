//
// Copyright (c) Jackal Engine. MIT License.
//
#include "Core/Math/MatrixTest.hpp"
#include "Core/Math/QuatTest.hpp"
#include "Core/Memory/MemoryTest.hpp"
#include <iostream>

int main(int c, char *argv[]) {
  jkl::test::MatrixTest test;
  jkl::test::QuatTest qtest;
  jkl::test::MemoryTest mtest;
  test.Test();
  qtest.Test();
  mtest.Test();

  std::cout << "\n\nTesting successful, Press Enter to continue...\n";
  std::cin.ignore();
  return 0;
}