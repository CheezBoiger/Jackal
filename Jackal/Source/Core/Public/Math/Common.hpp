// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"
#include "Platform/Api.hpp"
#include <math.h>

#define J_PI 3.141592653589793238462643383279502884197169399375
#define J_PI_2 (J_PI / 2)


namespace jkl {



inline float Sqrtf(float value)
{
  return sqrtf(value);
}


inline double Sqrt(double value)
{
  return sqrt(value);
}


template<typename T>
inline bool IsNaN(T value)
{
  return isnan(value);
}

// Standard absolute value wrap.
template<typename T>
inline T Abs(T value)
{
  return abs(value);
}


inline double Cos(double value)
{
  return cos(value);
}


inline double Sin(double value)
{
  return sin(value);
}

inline double Tan(double value)
{
  return tan(value);
}

inline float Cosf(float value)
{
  return cosf(value);
}

inline float Sinf(float value)
{
  return sinf(value);
}

inline float Tanf(float value)
{
  return tanf(value);
}


inline float ToRadians(float degrees)
{
  return degrees * (static_cast<float>(J_PI) / 180.0f);
}
} // jkl
