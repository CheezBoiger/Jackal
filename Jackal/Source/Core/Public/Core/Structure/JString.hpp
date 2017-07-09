//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

#include <string>


namespace jackal {


#if JACKAL_PLATFORM == JACKAL_WINDOWS
typedef std::string JString;

 #define JCOUT() std::cout
 #define jcout std::cout
 #define TO_JSTRING(str) std::to_string(str)
#else
typedef std::string JString;

 #define JCOUT() std::cout
 #define jcout   std::cout
 #define TO_JSTRING(str) std::to_string(str)
#endif


void PrintToConsole(JString str);
} // jackal