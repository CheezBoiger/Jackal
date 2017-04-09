//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#define JACKAL_WINDOWS 0xffffab12
#define JACKAL_LINUX   0xffffcdda
#define JACKAL_OSX     0xffff99ae


#if defined(_WIN32)
 #define JACKAL_PLATFORM JACKAL_WINDOWS
#elif defined(__linux__) || defined(__unix__)
 #define JACKAL_PLATFORM JACKAL_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
 #define JACKAL_PLATFORM JACKAL_OSX
#else
 #error "Unsupported Operating System detected. Cannot build this Game Engine."
#endif // defined(_WIN32)

#define TARGET_PLATFORM JACKAL_PLATFORM


#if TARGET_PLATFORM == JACKAL_WINDOWS
 #define TARGET_OS_NAME "win32"
#elif TARGET_PLATFORM == JACKAL_LINUX
 #define TARGET_OS_NAME "linux"
#elif TARGET_PLATFORM == JACKAL_OSX
 #define TARGET_OS_NAME "os x"
#else
 #define TARGET_OS_NAME "unknown"
#endif