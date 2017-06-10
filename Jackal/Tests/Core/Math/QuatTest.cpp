// Copyright (c) 2017 Jackal Engine, MIT License.
#include "QuatTest.hpp"
#include "Core/Math/QuaternionMath.hpp"
#include "Core/Math/Quaternion.hpp"
#include "Core/Logging/Logger.hpp"

#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
#include "gtest/gtest.h"

#include <chrono>

namespace coretest {


#define TOLERANCE 0.00001f


TEST(QuaternionTesting, QuatTest)
{
  jkl::Quat a(5.0f, 12.0f, 3.0f, 3.0f);
  jkl::Quat b;

  glm::quat glma(5.0f, 12.0f, 3.0f, 3.0f);
  glm::quat glmb;

  glma = glm::angleAxis(glm::radians(82.0f), 
    glm::vec3(1.0f, 0.8f, 0.5f));//glm::inverse(glma);

  a = jkl::AngleAxis(jkl::ToRadians(82.0f), 
    jkl::Vec3(1.0f, 0.8f, 0.5f));//a.Inverse();

  jkl::Vec3f eulerA = a.ToEulerAngles();
  glm::vec3 eulerGLM = glm::eulerAngles(glma);

  jkl::Mat4 rotA = a.ToMatrix4();
  glm::mat4 rotB = glm::toMat4(glma);

  std::cout << "Quaternion AngleAxis testing\n";
  std::cout << a.x << " " << a.y << " " << a.z << " " << a.w << "\n";
  std::cout << glma.x << " " << glma.y << " " << glma.z << " " << glma.w << "\n";

  std::cout << "Quaternion Mat4 testing\n";
  std::cout << "\nJackal:\n";
  for (jkl::uint32 i = 0; i < 4; ++i) {
    for (jkl::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(15) << rotA[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\nGLM:\n";
  for (jkl::uint32 i = 0; i < 4; ++i) {
    for (jkl::uint32 j = 0; j < 4; ++j) {
      std::cout << std::setw(15) << rotB[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\nQuaternion Eulers\n";
  std::cout << eulerA.x << " " << eulerA.y << " " << eulerA.z << "\n";
  std::cout << eulerGLM.x << " " << eulerGLM.y << " " << eulerGLM.z << "\n";

  // Testing with the GLM Library.
  EXPECT_EQ(a.x, glma.x);
  EXPECT_EQ(a.y, glma.y);
  EXPECT_EQ(a.z, glma.z);
  EXPECT_EQ(a.w, glma.w);

  float f = 0.1f;
  float sum = 0.0f;
  for (int i = 0; i < 10; ++i) {
    sum += f;
  }
  float product = f * 10.0f;
  printf("sum = %1.15f, mul = %1.15f, mul2 = %1.15f\n", sum, product, f * 10);

  // Using tolerance to check.
  EXPECT_GE(sum + TOLERANCE, product);
  EXPECT_LE(sum - TOLERANCE, product);
  // Passing this test, means these float values are equal.
} 


void QuaternionTesting()
{
}
} // coretest