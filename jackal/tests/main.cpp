//
// Copyright (c) Jackal Engine. MIT License.
//
#include "core/math/matrix_test.hpp"
#include "core/math/quat_test.hpp"
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