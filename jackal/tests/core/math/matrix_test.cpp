//
// Copyright(c) Jackal Engine. MIT License.
//
#include "matrix_test.hpp"
#include "math/matrix.hpp"
#include "math/vector.hpp"
#include "math/vector_math.hpp"
#include "math/matrix_math.hpp"
#include "math/quaternion.hpp"
#include "math/common.hpp"
#include "glm/common.hpp"
#include "glm/gtc/matrix_transform.hpp"
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
  Mat4 T = LookAtLH(Vec3(1.0f, 16.0f, -123.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
  //Translate(Mat4(), Vec3(12.0f, -12.4f, 1.0f)); 
  //T = Rotate(T, ToRadians(-74.0f), Vec3(1.0f, 0.0f, 0.0f));
  //T = Scale(T, Vec3(5.0f, 5.0f, 5.0f));
  glm::mat4 glmT = glm::lookAtLH(glm::vec3(1.0f, 16.0f, -123.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
/*  glm::translate(glm::mat4(), glm::vec3(12.0f, -12.4f, 1.0f));
  glmT = glm::rotate(glmT, glm::radians(-74.0f), glm::vec3(1.0f, 0.0f, 0.0f));
  glmT = glm::scale(glmT, glm::vec3(5.0f, 5.0f, 5.0f));
*/
  Mat4 C = B;
  C = C.Inverse();
  Quat q0(1.0f, 0.0f, 0.0f, 2.0f);
  Quat q1(3.0f, -1.0f, 4.0f, 3.0f);
  Quat ans = q0 * q1;
  ans = ans.Inverse();
  std::printf("quat ans: w=>%f x=>%f y=>%f z=>%f\n", 
    ans.w, ans.x, ans.y, ans.z);
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

  std::cout << "\nJackal Math library:\n";
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(15) << T[i][j] << " ";
    }
    std::cout << "\n";
  } glm::mat4 m;
  std::cout << "\nGLM library:\n";
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(15) << glmT[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\nDeterminant of B is: " << B.Determinant() << "\n";
  Vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
  Vec3 a(1.0f, 2.0f, 3.0f);
  Vec3 b(4.0f, 5.0f, 6.0f);
  //a *= b;
  std::printf("Vector values: x=%f y=%f z=%f w=%f\n", vec.r, vec.g, vec.b, vec.a);
  Vec3 c = Cross(a, b);
  bool yup = A == B;
  std::printf("Vector operation: x=%f y=%f z=%f\n", c.x, c.y, c.z);
  std::printf("a < c: %d\n", yup);
}
} // test
} // jkl

