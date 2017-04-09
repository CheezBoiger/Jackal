//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "platform/platform.hpp"
#include <cassert>

#define JKL_ASSERT(expr) assert(expr)


#if TARGET_PLATFORM == JACKAL_WINDOWS
 #include <Windows.h>
 #define JKL_BREAK() DebugBreak()
 #define JKL_ASSERT(expr) assert(expr)
#elif TARGET_PLATFORM == JACKAL_LINUX
 #define JKL_BREAK()
 #define JKL_ASSERT(expr) assert(expr)
#else
 #define JKL_BREAK()
 #define JKL_ASSERT(expr)
#endif 