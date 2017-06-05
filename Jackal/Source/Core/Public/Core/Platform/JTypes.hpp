//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once
#include <cstdint>
#include <cstddef>



namespace jkl {


typedef int8_t      bool8;
typedef int8_t      int8;
typedef uint8_t     ubyte;
typedef ubyte       uint8;
typedef uint16_t    uint16;
typedef int16_t     int16;
typedef int32_t     int32;
typedef uint32_t    uint32;
typedef int64_t     int64;
typedef uint64_t    uint64;
typedef float       real32;
typedef double      real64;

typedef int16       error16;
typedef char        byte;
typedef const char *jstring;


// Windows based systems love wide characters as unicode.
// Unfortunately, this is ridiculous of them to do so, now
// we need to compensate on win32 machines.
#if defined(_WIN32)
 typedef wchar_t    tchar;
#else
 typedef char        tchar;
#endif
} // jkl
