//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once
#include "Core/Platform/Platform.hpp"

#include <cstdint>
#include <cstddef>



namespace jackal {


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

typedef real64 high_precision_t;
typedef real32 medium_preision_t;

#if JACKAL_PLATFORM == JACKAL_WINDOWS
 typedef wchar_t       tchar;
 #define JTEXT(text)   L ## text
#else
 typedef char          tchar;
 #define JTEXT(text)   text
#endif 
} // jackal
