cmake_minimum_required(VERSION 2.8.11)
project("JackalEngine")

set(JACKAL_NAME        "Jackal" CACHE STRING "")
set(JACKAL_DESCRIPTION "Jackal Open Source Game Engine" CACHE STRING "")

add_definitions(
  -DJACKAL_CURRENT_VERSION=0x00000100
  -DJACKAL_COMPATIBLE_VERSION=0x00000100
)

find_package(OpenAL)
find_package(Vulkan)


if (NOT vulkan_FOUND)
endif()

if (NOT OPENAL_FOUND)
  message(WARNING "OpenAL not found!")
endif()

include (cmake/setup.cmake)

