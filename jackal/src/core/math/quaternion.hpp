//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "../platform/public/platform.hpp"
#include "../platform/public/jtypes.hpp"


namespace jkl {


template<typename T>
struct Quaternion {


  union {
    struct { T x, y, z, w; };
    struct { T r, g, b, a; };
    struct { T s, t, r, q; };
  };
};

typedef Quaternion<real32> Quat;
} // jkl