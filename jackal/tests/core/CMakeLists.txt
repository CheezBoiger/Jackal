cmake_minimum_required(VERSION 2.8.11)
project("JackalCoreTests")

set(TEST_MATH_DIR math)

set(MATH_TESTS
  ${TEST_MATH_DIR}/matrix_test.cpp
  ${TEST_MATH_DIR}/matrix_test.hpp
  ${TEST_MATH_DIR}/quat_test.hpp
  ${TEST_MATH_DIR}/quat_test.cpp
)

# Include core directory.
include_directories(SYSTEM
  ../../src/core/public
  ../../thirdparty/g-truc/glm
)


add_library(${JACKAL_CORE_TESTS} STATIC
  ${MATH_TESTS}
)


target_link_libraries(${JACKAL_CORE_TESTS} Jackal-Core)