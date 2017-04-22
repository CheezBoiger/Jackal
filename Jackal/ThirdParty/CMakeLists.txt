cmake_minimum_required(VERSION 2.8.11)
project("ThirdParty")

# Anything more?
add_subdirectory(googletest)

# TODO(): GLSLang is being a pain with gmock, forcing you to 
# run its tests. Not a problem, the problem is having to deal with
# redefinition errors on visual studio 2017.
set(ENABLE_GLSLANG_BINARIES OFF CACHE BOOL "glslang binaries")
#add_subdirectory(glslang)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
add_subdirectory(glfw)