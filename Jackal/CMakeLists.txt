# Copyright (c) Jackal Engine. MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalEngine")

option(RELEASE OFF "Build engine in release mode.")

# Jackal Engine Definitions for the overall full version of this
# engine.
add_definitions(
  -DJACKAL_CURRENT_VERSION=0x00000100
  -DJACKAL_COMPATIBLE_VERSION=0x00000100
)


# Check for release, determine if we should enter the engine into 
# Debug mode, which will result in sligtly slower performance, but much
# more power in profiling and debugging the engine, or fast performance,
# but assuming we have a stable implementation.
if (RELEASE)
  add_definitions(
    -DJACKAL_DEBUG_MODE=0
  )
else()
  add_definitions(
    -DJACKAL_DEBUG_MODE=1
  )
endif (RELEASE)

# Third party software should not be affected by compiler configurations.
add_subdirectory(ThirdParty)

# Finally, start to set up the enviroment for our engine.
# Add the cmake module path, for module build paths for this cmake file.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake/")


if (MSVC)
  set(MSVC_BUILD_FLAGS "/MT")
  set(MSVC_BUILD_DEBUG_FLAGS "/MTd")

  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${MSVC_BUILD_DEBUG_FLAGS}")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${MSVC_BUILD_FLAGS}")
endif()
set(CLANG_BUILD_FLAGS "")
set(GCC_BUILD_FLAGS "")

set(JACKAL_THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)

add_subdirectory(Source)
add_subdirectory(Tests)
