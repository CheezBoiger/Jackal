# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalCoreTests")

set(TEST_MATH_DIR       Math)
set(TEST_MEMORY_DIR     Memory)
set(TEST_WIN32_DIR      Win32)
set(TEST_STRUCTURE_DIR  Structure)


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

# Structure testing functionality.
set(STRUCTURE_TESTS
  ${TEST_STRUCTURE_DIR}/JStringTest.hpp
  ${TEST_STRUCTURE_DIR}/JStringTest.cpp
)


# Win32 testing files. Should find a better way to check.
if (WIN32)
  set(WIN32_TESTS
    ${TEST_WIN32_DIR}/Win32ThreadTest.hpp
    ${TEST_WIN32_DIR}/Win32ThreadTest.cpp
    ${TEST_WIN32_DIR}/Win32WindowTest.cpp
    ${TEST_WIN32_DIR}/Win32WindowTest.hpp
)
else()
  set(WIN32_TESTS)
endif()

# Include core directory.
include_directories(SYSTEM
  ../../Source/Core/Public
  ../../Source/OpenGLDevice/Public
  ../../Source/RenderDevice/Public
  ../../ThirdParty/g-truc/glm
)


# Actual Testing of our core library. We will need to compile into 
# a library instead of a main lib.
add_library(${JACKAL_CORE_TESTS} STATIC
  ${MATH_TESTS}
  ${MEMORY_TESTS}
  ${WIN32_TESTS}
  ${STRUCTURE_TESTS}
)

# We are targeting our main core engine library to this testing framework.
target_link_libraries(${JACKAL_CORE_TESTS} Jackal-Core OpenGLDevice)

# Windows implementation, we will need to figure out out and take control of the 
# operating system checking soon enough.
if (WIN32)
  set_property(TARGET ${JACKAL_CORE_TESTS} PROPERTY FOLDER ${JACKAL_TESTING_DIRECTORY})
endif()

include(Macros)

set_cxx_standard(${JACKAL_CORE_TESTS} 14)
