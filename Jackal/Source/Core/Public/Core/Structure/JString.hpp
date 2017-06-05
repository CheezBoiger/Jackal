//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

#include <string>


#if TARGET_PLATFORM == JACKAL_WINDOWS
#define JTEXT(text) L##text
#else
#define JTEXT(text) text
#endif


namespace jkl {


#if JACKAL_PLATFORM == JACKAL_WINDOWS
typedef std::wstring JString;

 #define JCOUT() std::wcout
 #define jcout std::wcout
#else
typedef std::string JString;

 #define JCOUT() std::cout
 #define jcout   std::cout
#endif


void PrintToStdConsole(JString str);
} // jkl