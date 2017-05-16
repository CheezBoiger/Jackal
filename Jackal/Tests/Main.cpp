// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Math/QuatTest.hpp"
#include "Core/Memory/MemoryTest.hpp"
#include "gtest/gtest.h"

#include "Core/Math/MatrixTest.hpp"
#include <iostream>

int main(int c, char *argv[]) {
  ::testing::InitGoogleTest(&c, argv);

  jkl::test::QuatTest qtest;

  coretest::MatrixTesting();
  coretest::MemoryTesting();
  qtest.Test();

  int success = RUN_ALL_TESTS();

  std::cout << "Press Enter to continue...\n";
  std::cin.ignore();
  return success;
}