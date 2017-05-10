cmake_minimum_required(VERSION 2.8.11)
project("JackalCoreTests")

set(TEST_MATH_DIR Math)
set(TEST_MEMORY_DIR Memory)

set(MATH_TESTS
  ${TEST_MATH_DIR}/MatrixTest.cpp
  ${TEST_MATH_DIR}/MatrixTest.hpp
  ${TEST_MATH_DIR}/QuatTest.hpp
  ${TEST_MATH_DIR}/QuatTest.cpp
)


set(MEMORY_TESTS
  ${TEST_MEMORY_DIR}/MemoryTest.cpp
  ${TEST_MEMORY_DIR}/MemoryTest.hpp
)

# Include core directory.
include_directories(SYSTEM
  ../../Source/Core/Public
  ../../ThirdParty/g-truc/glm
)


add_library(${JACKAL_CORE_TESTS} STATIC
  ${MATH_TESTS}
  ${MEMORY_TESTS}
)


target_link_libraries(${JACKAL_CORE_TESTS} Jackal-Core)

if (WIN32)
  set_target_properties(${JACKAL_CORE_TESTS} PROPERTIES COMPILE_FLAGS ${MSVC_BUILD_FLAGS})
endif()