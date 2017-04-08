# Copyright (c) Jackal Engine. MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalEngine")

option(RELEASE OFF "Build engine in release mode.")

find_package(OpenAL)
find_package(Vulkan)
find_package(OpenGL)

add_definitions(
  -DJACKAL_CURRENT_VERSION=0x00000100
  -DJACKAL_COMPATIBLE_VERSION=0x00000100
)

if (RELEASE)
  add_definitions(
    -DJACKAL_DEBUG_MODE=0
  )
else()
  add_definitions(
    -DJACKAL_DEBUG_MODE=1
  )
endif (RELEASE)

set(JACKAL_THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)


add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(thirdparty)