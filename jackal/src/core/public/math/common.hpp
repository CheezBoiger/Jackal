//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "platform/jtypes.hpp"
#include "platform/platform.hpp"
#include "platform/api.hpp"
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

// Standard absolute value wrap.
template<typename T>
inline T Abs(T value)
{
  return std::abs(value);
}


inline double Cos(double value)
{
  return std::cos(value);
}


inline double Sin(double value)
{
  return std::sin(value);
}

inline double Tan(double value)
{
  return std::tan(value);
}

inline float Cosf(float value)
{
  return std::cosf(value);
}

inline float Sinf(float value)
{
  return std::sinf(value);
}

inline float Tanf(float value)
{
  return std::tanf(value);
}
} // jkl