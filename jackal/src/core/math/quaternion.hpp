//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "../platform/public/platform.hpp"
#include "../platform/public/jtypes.hpp"
#include "common.hpp"


namespace jkl {


// Quaternion object, used to represent 
// rotations in 3D space. 
// The Identity Formula is as follows:
//
// i^2 = j^2 = k^2 = ijk = -1
// or
// i = j = k = sqrt(-1)
// 
// where w, x, y, and z are real numbers and i, j, and k are
// imaginary.
// The benefit of having these mathematical objects is that they
// can be represented using euler angles, as vectors, matrices, 
// and, since rotation matrices use up too much memory, can 
// be space efficient. One of the notable features as well with
// quaternions is that they also avoid gimbal lock.
template<typename T>
struct Quaternion {
  // Initial state of the quaternion.
  Quaternion(
    T w = static_cast<T>(1), 
    T x = static_cast<T>(0), 
    T y = static_cast<T>(0), 
    T z = static_cast<T>(0)
  ) : w(w), x(x), y(y), z(z) 
  { } 

  Quaternion(const Quaternion &quat)
    : w(quat.w), x(quat.x), y(quat.y), z(quat.z)
  { }

  // Add this quaternion to another quaternion,
  // to make a new quaternion.
  Quaternion operator+(const Quaternion &q) const;

  // Subtact this quaternion from another quaternion,
  // to make a new quaternion.
  Quaternion operator-(const Quaternion &q) const;

  // Quaternion multiplation, using the Hamilton Product.
  // Note that quaternion multiplication is non-commutative
  // so order matters!
  Quaternion operator*(const Quaternion &q) const;

  // Quaternion multiplication, using the Hamilton Product.
  // Note that quaternion multiplicatio is non-commutative,
  // so order matters!
  // Be aware that this operator will write to this quaternion object.
  void operator*=(const Quaternion &q);

  // Addition of quaternion q onto this quaternion. Does not
  // create a new quaternion, instead will modify this one.
  void operator+=(const Quaternion &q);

  // Subtraction of quaternion q from this quaternion. Does not
  // create a new quaternion, instead will modify this one.
  void operator-=(const Quaternion &q);

  // TODO(): More to be added soon.

  // Returns the magnitude of the quaternion.
  T Length() {
    return Sqrt((w * w) + (x * x) + (y * y) + (z * z));
  }

  // Quaternion parameters set up like in 
  // math: w + xi + yj + zk 
  union {
    struct { T w, x, y, z; };
    struct { T a, r, g, b; };
    struct { T q, s, t, r; };
  };
};

typedef Quaternion<real32> Quat;
} // jkl

#include "internal/quaternion.inl"