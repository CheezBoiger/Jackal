//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "../../platform/public/platform.hpp"
#include <cassert>

#define JKL_ASSERT(expr) assert(expr)


#if TARGET_PLATFORM == JACKAL_WINDOWS
 #include <Windows.h>
 #define JKL_BREAK() DebugBreak()
#elif TARGET_PLATFORM == JACKAL_LINUX
 #define JKL_BREAK()
#else
 #define JKL_BREAK()
#endif 