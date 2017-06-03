// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#if (JACKAL_PLATFORM == JACKAL_WINDOWS)
 #define WIN32_LEAN_AND_MEAN
 #include <Windows.h>

 #if defined(WIN32_NETWORKING)
  #include <WinSock2.h>
 #endif
#else
 #error "This Operating system does not use Window's compatible API functions. Can not compile."
#endif


namespace jkl {


} // jkl