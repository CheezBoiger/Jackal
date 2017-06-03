// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Config.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"


namespace jkl {


class Win32Clock {
public:
  static SYSTEMTIME GetSystemTime();
};
} // jkl