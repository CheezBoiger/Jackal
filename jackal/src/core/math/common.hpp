//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "../platform/public/jtypes.hpp"
#include "../platform/public/platform.hpp"
#include <cmath>


namespace jkl {



inline double Sqrt(double value)
{
  return std::sqrt(value);
}


template<typename T>
inline bool IsNaN(T value)
{
  return std::isnan(value);
}
} // jkl