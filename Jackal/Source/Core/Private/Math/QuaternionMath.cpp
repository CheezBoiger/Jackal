// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Math/QuaternionMath.hpp"

namespace jkl {


Quaternion Normalize(const Quaternion &q)
{
  real32 norm = q.Length();
  return (q / norm);
}
} // jkl
