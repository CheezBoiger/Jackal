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


TEST(QuaternionTesting, QuatTest)
{
  jkl::Quat a(5.0f, 12.0f, 3.0f, 3.0f);
  jkl::Quat b;

  glm::quat glma(5.0f, 12.0f, 3.0f, 3.0f);
  glm::quat glmb;

  glma = glm::inverse(glma);

  a = a.Inverse();

  std::cout << "Quaternion testing\n";
  std::cout << a.x << " " << a.y << " " << a.z << " " << a.w << "\n";
  std::cout << glma.x << " " << glma.y << " " << glma.z << " " << glma.w << "\n";

  // Testing with the GLM Library.
  EXPECT_EQ(a.x, glma.x);
  EXPECT_EQ(a.y, glma.y);
  EXPECT_EQ(a.z, glma.z);
  EXPECT_EQ(a.w, glma.w);
} 


void QuaternionTesting()
{
}
} // coretest