//
// Copyright (c) Jackal Engine. MIT License.
//
#include "Core/Math/MatrixTest.hpp"
#include "Core/Math/QuatTest.hpp"
#include <iostream>

int main(int c, char *argv[]) {
  jkl::test::MatrixTest test;
  jkl::test::QuatTest qtest;
  test.Test();
  qtest.Test();

  std::cout << "\n\nTesting successful, Press Enter to continue...\n";
  std::cin.ignore();
  return 0;
}