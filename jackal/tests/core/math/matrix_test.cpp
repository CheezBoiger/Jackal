//
// Copyright(c) Jackal Engine. MIT License.
//
#include "matrix_test.hpp"
#include "math/matrix.hpp"
#include "math/vector.hpp"
#include <iostream>
#include <iomanip>

namespace jkl {
namespace test {


void MatrixTest::Test()
{
  Mat4 A(
    8, 1, 1, 5,
    -1, 5, 6, 7,
    8, 9, 10, 11,
    12, 5, -12, 15
  );
  Mat4 B = A.Transpose();
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(5) << A[i][j] << " "; 
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(5) << B[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "Determinant of A is: " << A.Determinant() << "\n";
  Vec4 vec;
  std::printf("Vector values: x=%f y=%f z=%f w=%f\n", vec.r, vec.g, vec.b, vec.a);
  std::cin.ignore();
}
} // test
} // jkl

