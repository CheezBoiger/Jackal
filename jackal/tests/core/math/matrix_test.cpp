//
// Copyright(c) Jackal Engine. MIT License.
//
#include "matrix_test.hpp"
#include "math/matrix.hpp"
#include "math/vector.hpp"
#include "math/vector_math.hpp"
#include "math/quaternion.hpp"
#include "math/common.hpp"
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
  Mat4 B(
    5, 6, 12, 10,
    -1, 0, -12, 12,
    9, 1, 122, 4,
    8, 4, -9, 2
  );
  A *= B;
  Mat3 D;
  Mat4 T = D;
  Mat4 C = A - B;
  Quat q;
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
  std::cout << "\n";
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(5) << C[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\nDeterminant of A is: " << A.Determinant() << "\n";
  Vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
  Vec3 a(1.0f, 2.0f, 3.0f);
  Vec3 b(4.0f, 5.0f, 6.0f);
  std::printf("Vector values: x=%f y=%f z=%f w=%f\n", vec.r, vec.g, vec.b, vec.a);
  Vec3 c = Cross(a, b);
  bool yup = A == B;
  std::printf("Vector operation: x=%f y=%f z=%f\n", c.x, c.y, c.z);
  std::printf("a < c: %d", yup);
  std::cin.ignore();
}
} // test
} // jkl

