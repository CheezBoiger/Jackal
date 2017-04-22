cmake_minimum_required(VERSION 2.8.11)
project("JackalCoreTests")

set(TEST_MATH_DIR Math)

set(MATH_TESTS
  ${TEST_MATH_DIR}/MatrixTest.cpp
  ${TEST_MATH_DIR}/MatrixTest.hpp
  ${TEST_MATH_DIR}/QuatTest.hpp
  ${TEST_MATH_DIR}/QuatTest.cpp
)

# Include core directory.
include_directories(SYSTEM
  ../../Source/Core/Public
  ../../ThirdParty/g-truc/glm
)


add_library(${JACKAL_CORE_TESTS} STATIC
  ${MATH_TESTS}
)


target_link_libraries(${JACKAL_CORE_TESTS} Jackal-Core)