# Copyright (c) Jackal Engine. MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalEngine")

find_package(OpenAL)
find_package(Vulkan)

add_definitions(
  -DJACKAL_CURRENT_VERSION=0x00000100
  -DJACKAL_COMPATIBLE_VERSION=0x00000100
)

set(JACKAL_THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)


add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(thirdparty)