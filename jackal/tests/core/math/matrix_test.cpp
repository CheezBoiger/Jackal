//
// Copyright(c) Jackal Engine. MIT License.
//
#include "matrix_test.hpp"
#include "math/matrix.hpp"
#include <iostream>

namespace jkl {
namespace test {


void MatrixTest::Test()
{
  Matrix4x4<real32> A(
    8, 1, 1, 5,
    -1, 5, 6, 7,
    8, 9, 10, 11,
    12, 5, -12, 15
  );
  Matrix4x4<real32> B;

  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      std::cout << A[i][j] << " "; 
    }
    std::cout << "\n";
  }
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      std::cout << B[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "Determinant of A is: " << A.Determinant() << "\n";
  std::cin.ignore();
}
} // test
} // jkl

