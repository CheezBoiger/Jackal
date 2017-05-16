//
// Copyright(c) Jackal Engine. MIT License.
//
#include "MatrixTest.hpp"

#include "Math/Matrix.hpp"
#include "Math/Vector.hpp"
#include "Math/VectorMath.hpp"
#include "Math/MatrixMath.hpp"
#include "Math/Quaternion.hpp"
#include "Math/Common.hpp"
#include "glm/common.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <iomanip>
#include <chrono>



namespace coretest {


TEST_F(MatrixTestFixture, MatrixAlgebraFixture) {
  
}


TEST(MathTesting, MatrixTesting) {
  jkl::Mat4 jmat;
  glm::mat4 glm_mat;

  EXPECT_EQ(jmat[0][0], glm_mat[0][0]);

  jkl::Mat4 A(
    8, 1, 1, 5,
    -1, 5, 6, 7,
    8, 9, 10, 11,
    12, 5, -12, 15
  );
  jkl::Mat4 B(
    5, 6, 12, 10,
    -1, 0, -12, 12,
    9, 1, 122, 4,
    8, 4, -9, 2
  );
  A *= B;
  jkl::Mat3 D;

  // TODO(): Tests are not super accurate, seems like which ever transformation
  // from either library is done first, it will be the slowest... Both libraries
  // perform about the same optimal time, average.

  auto start = std::chrono::high_resolution_clock::now();
  glm::mat4 glmT = //glm::perspectiveLH(45.0f, 1.0f, 0.1f, 1000.0f);
  //glm::lookAtLH(glm::vec3(1.0f, 16.0f, -123.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
  glm::translate(glm::mat4(), glm::vec3(12.0f, -12.4f, 1.0f));
  glmT = glm::rotate(glmT, glm::radians(-74.0f), glm::vec3(0.0f, 1.0f, 0.0f));
  glmT = glm::rotate(glmT, glm::radians(50.0f), glm::vec3(1.0f, 0.0f, 0.0f));
  glmT = glm::scale(glmT, glm::vec3(5.0f, 5.0f, 5.0f));
  auto end = std::chrono::high_resolution_clock::now();
  long long tG = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  start = std::chrono::high_resolution_clock::now();
  jkl::Mat4 T = //jkl::PerspectiveLH(45.0f, 1.0f, 0.1f, 1000.0f);
           //jkl::LookAtLH(jkl::Vec3(1.0f, 16.0f, -123.0f), jkl::Vec3(0.0f, 0.0f, 0.0f), jkl::Vec3(0.0f, 1.0f, 0.0f));
    jkl::Translate(jkl::Mat4(), jkl::Vec3(12.0f, -12.4f, 1.0f));
  T = jkl::Rotate(T, jkl::ToRadians(-74.0f), jkl::Vec3(0.0f, 1.0f, 0.0f));
  T = jkl::Rotate(T, jkl::ToRadians(50.0f), jkl::Vec3(1.0f, 0.0f, 0.0f));
  T = jkl::Scale(T, jkl::Vec3(5.0f, 5.0f, 5.0f));
  end = std::chrono::high_resolution_clock::now();
  long long tJ = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  std::printf("tJackal=%llu ms tGLM=%llu ms\n", tJ, tG);
  jkl::Mat4 C = B;
  C = C.Inverse();
  jkl::Quat q0(1.0f, 0.0f, 0.0f, 2.0f);
  jkl::Quat q1(3.0f, -1.0f, 4.0f, 3.0f);
  jkl::Quat ans = q0 * q1;
  ans = ans.Inverse();
  std::printf("quat ans: w=>%f x=>%f y=>%f z=>%f\n", 
    ans.w, ans.x, ans.y, ans.z);
  for (jkl::uint32 i = 0; i < 4; ++i) {
    for (jkl::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(5) << A[i][j] << " "; 
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for (jkl::uint32 i = 0; i < 4; ++i) {
    for (jkl::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(5) << B[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\nJackal Math library:\n";
  for (jkl::uint32 i = 0; i < 4; ++i) {
    for (jkl::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(15) << T[i][j] << " ";
    }
    std::cout << "\n";
  } glm::mat4 m;
  std::cout << "\nGLM library:\n";
  for (jkl::uint32 i = 0; i < 4; ++i) {
    for (jkl::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(15) << glmT[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\nDeterminant of B is: " << B.Determinant() << "\n";
  jkl::Vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
  jkl::Vec3 a(1.0f, 2.0f, 3.0f);
  jkl::Vec3 b(4.0f, 5.0f, 6.0f);
  //a *= b;
  std::printf("Vector values: x=%f y=%f z=%f w=%f\n", vec.r, vec.g, vec.b, vec.a);
  jkl::Vec3 c = Cross(a, b);
  bool yup = A == B;
  std::printf("Vector operation: x=%f y=%f z=%f\n", c.x, c.y, c.z);
  std::printf("a < c: %d\n", yup);

}


void MatrixTesting()
{
  // ehh
}
} // coretest
