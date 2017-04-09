//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "../quaternion_math.hpp"

namespace jkl {


template<typename T> inline
Quaternion<T> Normalize(const Quaternion<T> &q)
{
  T norm = q.Length();
  return (q / norm);
}
} // jkl