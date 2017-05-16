// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

namespace jkl {


template<typename T> inline
Quaternion<T> Normalize(const Quaternion<T> &q)
{
  T norm = q.Length();
  return (q / norm);
}
} // jkl