//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "Platform.hpp"


#if JACKAL_PLATFORM == JACKAL_WINDOWS
 #if !defined(_MSC_FULL_VER)
  #error "This engine is not compatible with any other compiler on windows, except Visual C++"
 #endif
 #if defined(_DEBUG) && _DEBUG && JACKAL_DEBUG_MODE
  #define JACKAL_DEBUG _DEBUG
 #else 
  #define JACKAL_DEBUG JACKAL_DEBUG_MODE
 #endif
 #define JACKAL_FORCEINLINE __forceinline
 #if _MSC_VER > 1900 // works for visual studio 2015 and up.
  #define JACKAL_ALIGN(x) alignas(x)
 #else
  #define JACKAL_ALIGN(x) __declspec(align(x))
 #endif
 #define JACKAL_EXPORT __declspec(dllexport)
#elif JACKAL_PLATFORM == JACKAL_LINUX
 #define JACKAL_DEBUG JACKAL_DEBUG_MODE
 #define JACKAL_ALIGN(x) __attribute__(aligned(x))
 #define JACKAL_FORCEINLINE __attribute__((always_inline))
 #define JACKAL_EXPORT __attribute__((visibility("default"))
#elif JACKAL_PLATFORM == JACKAL_OSX
  // osx stuff
  // we will need to support Clang for Apple.
  #define JACKAL_DEBUG JACKAL_DEBUG_MODE
  #define JACKAL_ALIGN(x)
  #define JACKAL_FORCEINLINE
  #define JACKAL_EXPORT
#else
 #error "An unknown operating system being used. Cannot use any of these API macros."
#endif // JACKAL_PLATFORM == JACKAL_WINDOWS 