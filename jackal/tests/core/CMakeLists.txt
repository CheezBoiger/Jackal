cmake_minimum_required(VERSION 2.8.11)
project("JackalCoreTests")

set(JACKAL_CORE_TESTS "JackalCoreTests")
set(TEST_MATH_DIR math)

set(MATH_TESTS
  ${TEST_MATH_DIR}/matrix_test.cpp
  ${TEST_MATH_DIR}/matrix_test.hpp
)

# Include core directory.
include_directories(SYSTEM
  ../../src/core
)


add_library(${JACKAL_CORE_TESTS} STATIC
  ${MATH_TESTS}
)


link_libraries(${JACKAL_CORE_TESTS} Jackal-Core)