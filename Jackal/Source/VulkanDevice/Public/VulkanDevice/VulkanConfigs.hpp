// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


// TODO(): Set Platform specific preprocessor defines 
// for each OS in the CMake build.
// These include 
// VK_USE_PLATFORM_WIN32_KHR
// VK_USE_PLATFORM_XLIB_KHR
// etc.
#include "Core/Platform/Platform.hpp"

#if JACKAL_PLATFORM == JACKAL_WINDOWS
 #define VK_USE_PLATFORM_WIN32_KHR
 #include "Core/Win32/Win32Config.hpp"
#elif JACKAL_PLATFORM == JACKAL_LINUX
  // We will probably want to use xlib surface instead of 
  // xcb. Maybe...
 #define VK_USE_PLATFORM_XLIB_KHR
#elif JACKAL_PLATFORM == JACKAL_OSX

#else
 
#endif
#include <vulkan/vulkan.h>
#include <glslang/Public/ShaderLang.h>


#if defined(VK_USE_PLATFORM_WIN32_KHR)
#elif defined(VK_USE_PLATFORM_XLIB_KHR)

#endif