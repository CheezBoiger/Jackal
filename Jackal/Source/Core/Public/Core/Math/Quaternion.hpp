// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Common.hpp"
#include "Matrix4.hpp"
#include "Vector4.hpp"


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
struct Quaternion {
  // Returns the quaternion identity. By default,
  // the default constructor already returns it, but this
  // is for code clarification.
  static Quaternion Identity() {
    return Quaternion();
  }
  
  // Initial state of the quaternion.
  Quaternion(
    real32 w = 1.0f, 
    real32 x = 0.0f, 
    real32 y = 0.0f, 
    real32 z = 0.0f
  ) : w(w), x(x), y(y), z(z) 
  { } 

  // Copy constructor.
  Quaternion(const Quaternion &quat)
    : w(quat.w), x(quat.x), y(quat.y), z(quat.z)
  { }

  // Add this quaternion to another quaternion,
  // to make a new quaternion.
  Quaternion operator+(const Quaternion &q) const;

  // Subtact this quaternion from another quaternion,
  // to make a new quaternion.
  Quaternion operator-(const Quaternion &q) const;

  // Quaternion multiplication, using the Hamilton Product.
  // Note that quaternion multiplication is non-commutative
  // so order matters!
  Quaternion operator*(const Quaternion &q) const;

  // Scaler multiplication with quaternions. This will return
  // a fresh copy of a quaternion.
  Quaternion operator*(const real32 scaler) const;

  // Division between quaternions. this will return a fresh
  // copy of the resulting quaternion.
  Quaternion operator/(const Quaternion &q) const;

  // Division of a scaler value to this quaternion.
  // Will return a fresh copy of the resulting 
  // quaternion.
  Quaternion operator/(const real32 scaler) const;

  // Quaternion multiplication, using the Hamilton Product.
  // Note that quaternion multiplicatio is non-commutative,
  // so order matters!
  // Be aware that this operator will write to this quaternion object.
  void operator*=(const Quaternion &q);

  // Multiply this quaternion by a scaler value.
  void operator*=(const real32 scaler);

  // Addition of quaternion q onto this quaternion. Does not
  // create a new quaternion, instead will modify this one.
  void operator+=(const Quaternion &q);

  // Subtraction of quaternion q from this quaternion. Does not
  // create a new quaternion, instead will modify this one.
  void operator-=(const Quaternion &q);

  // Division between two quaternion values.
  // modifies this quaternion.
  void operator/=(const Quaternion &q);

  // Division between this quaternion, and the given scaler value.
  // Modifies this quaternion.
  void operator/=(const real32 scaler);

  // Get the conjugate of this quaternion object.
  // Represented as q*
  Quaternion Conjugate() const;

  // Get the inverse of this quaternion object.
  // Returns an inverse copy of the quaternion.
  // Represented as q^-1
  Quaternion Inverse() const;

  // Returns the vector representation of this quaternion object.
  Vector3f ToEulerAngles() const;

  // Returns the matrix representation of this quaternion object.
  Matrix4f ToMatrix4() const;

  // TODO(): More to be added soon.
  void Normalize();

  // Returns the magnitude/norm/length of the quaternion.
  real32 Magnitude() const {
    return Sqrtf((w * w) + (x * x) + (y * y) + (z * z));
  }

  // Quaternion parameters set up like in 
  // math: w + xi + yj + zk 
  union {
    struct { real32 w, x, y, z; };
    struct { real32 a, r, g, b; };
    struct { real32 q, s, t, p; };
  };
};

typedef Quaternion Quat;
} // jkl
