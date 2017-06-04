# Copyright (c) 2017 Jackal Engine, MIT License. 
cmake_minimum_required(VERSION 2.8.11)
project("ThirdParty")

# Anything more?
add_subdirectory(googletest)


# TODO(): GLSLang is being a pain with gmock, forcing you to 
# run its tests. Not a problem, the problem is having to deal with
# redefinition errors on visual studio 2017.
set(ENABLE_GLSLANG_BINARIES OFF CACHE BOOL "glslang binaries")
set(BUILD_TESTING OFF CACHE BOOL "CTest configurations, to force GLSlang tests to not be built")
# If vulkan was found, add in glslang compiler.
find_package(Vulkan)

if(Vulkan_FOUND)
  # Building GLSlang for Vulkan.
  add_subdirectory(glslang)
  if (MSVC)
    # Since we are building visual Studio, organization is easy and fast.
    set_property(TARGET
      glslang OGLCompiler OSDependent SPIRV SPVRemapper
      PROPERTY FOLDER "ThirdParty/Glslang")

    set_property(TARGET
      HLSL
      PROPERTY FOLDER "ThirdParty/Glslang/hlsl")
  endif()
endif()

# Override these fields for glfw testing.
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
add_subdirectory(glfw)

# Adding Compression and Interchange format libraries into ThirdParty
add_subdirectory(zlib)

set(protobuf_BUILD_TESTS OFF CACHE BOOL "")
set(protobuf_BUILD_EXAMPLES OFF CACHE BOOL "")
add_subdirectory(protobuf/cmake)


# For organization inside Visual Studio specifically.
if (MSVC)
  set_property(TARGET 
    gtest gmock gmock_main gtest_main uninstall
    PROPERTY FOLDER "ThirdParty/GoogleTest")
  set_property(TARGET
    glfw
    PROPERTY FOLDER "ThirdParty/GLFW3")
  set_property(TARGET
    zlib zlibstatic minigzip example
    PROPERTY FOLDER "ThirdParty/zlib")
  set_property(TARGET
    libprotobuf libprotobuf-lite js_embed libprotoc protoc
    PROPERTY FOLDER "ThirdParty/protobuf")
endif()