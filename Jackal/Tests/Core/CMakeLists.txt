# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalCoreTests")

set(TEST_MATH_DIR Math)
set(TEST_MEMORY_DIR Memory)


# Set our math test directory, we will need to add in google test 
# unit framework and death tests to these.
set(MATH_TESTS
  ${TEST_MATH_DIR}/MatrixTest.cpp
  ${TEST_MATH_DIR}/MatrixTest.hpp
  ${TEST_MATH_DIR}/QuatTest.hpp
  ${TEST_MATH_DIR}/QuatTest.cpp
)


# Memory testing directory, this project handles testing.
set(MEMORY_TESTS
  ${TEST_MEMORY_DIR}/MemoryTest.cpp
  ${TEST_MEMORY_DIR}/MemoryTest.hpp
)

# Include core directory.
include_directories(SYSTEM
  ../../Source/Core/Public
  ../../ThirdParty/g-truc/glm
)


# Actual Testing of our core library. We will need to compile into 
# a library instead of a main lib.
add_library(${JACKAL_CORE_TESTS} STATIC
  ${MATH_TESTS}
  ${MEMORY_TESTS}
)

# We are targeting our main core engine library to this testing framework.
target_link_libraries(${JACKAL_CORE_TESTS} Jackal-Core)

# Windows implementation, we will need to figure out out and take control of the 
# operating system checking soon enough.
if (WIN32)
  set_property(TARGET ${JACKAL_CORE_TESTS} PROPERTY FOLDER ${JACKAL_TESTING_DIRECTORY})
endif()