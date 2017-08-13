// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Config.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"


namespace jackal {


class Win32Time {
public:
  static SYSTEMTIME GetSystemTime();
};
} // jackal