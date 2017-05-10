//
// Copyright (c) Jackal Engine. MIT License.
//
#include "Core/Math/MatrixTest.hpp"
#include "Core/Math/QuatTest.hpp"
#include "Core/Memory/MemoryTest.hpp"
#include "gtest/gtest.h"
#include <iostream>

int main(int c, char *argv[]) {
  ::testing::InitGoogleTest(&c, argv);

  jkl::test::MatrixTest test;
  jkl::test::QuatTest qtest;
  jkl::test::MemoryTest mtest;
  test.Test();
  qtest.Test();
  mtest.Test();

  int success = RUN_ALL_TESTS();

  if (success == 0) {
    std::cout << "\n\nTesting successful, Press Enter to continue...\n";
  } else {
    std::cout << "\n\nTesting failed...\n";

    std::cout << "Press Enter to continue...\n";
  }
  std::cin.ignore();
  return 0;
}