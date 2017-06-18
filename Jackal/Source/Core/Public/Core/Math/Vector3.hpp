// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Vector2.hpp"
#include "Common.hpp"


namespace jkl {


// 3-Component vector object for use in mathematics inside jackal.
// This is verty handy for rotations, scaling, translating, and whatnot.
// Most of the transformation, scaling, shearing, and rotations will be using
// this vector object.
struct Vector3 {

  Vector3(
    real32 x = 0.0f,
    real32 y = 0.0f,
    real32 z = 0.0f
  ) : x(x), y(y), z(z)
  { }

  Vector3(
    const Vector2 &v, 
    real32 z = 0.0f
  ) : x(v.x), y(v.y), z(z)
    { }

  Vector3(
    const Vector3 &v
  ) : x(v.x), y(v.y), z(v.z)
  { }

  // Adds this vector to v, and returns a new
  // 3 component vector.
  Vector3 operator+(const Vector3 &v) const;

  // Subtracts this vector to v, and returns a new
  // 3 component vector.
  Vector3 operator-(const Vector3 &v) const;
  
  // Multiplies this vector to v, and returns a new
  // 3 component vector.
  Vector3 operator*(const Vector3 &v) const;

  // Multiplies this vector to a scaler value, and 
  // returns a new 3 component vector.
  Vector3 operator*(const real32 scale) const;

  // Performs division of this vector with vector v,
  // and returns a resulting 3 component vector.
  Vector3 operator/(const Vector3 &v) const;

  // Vector division. Divides this vector by the scaler
  // value, and returns a new, fresh copy of a 3-component 
  // vector.
  Vector3 operator/(const real32 scaler) const;

  // Add a 3-component vector v into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator+=(const Vector3 &v);

  // Subtract a 3-component vector v into this vector.
  // This will not create new vector, it will instead
  // modify this vector.
  void operator-=(const Vector3 &v);

  // Multiply a 3-component vector v into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator*=(const Vector3 &v);

  // Multiply a scaler value into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator*=(const real32 scale);

  // Divide a 3-component vector v into this vector.
  // This will not create a new vector, it will instead
  // modify this vector.
  void operator/=(const Vector3 &v);

  // Divides this vector's 3 components with the provided
  // scaler value. Modifies this vector object.
  void operator/=(const real32 scaler);

  // Take the invert of this vector, and return it as
  // a new 3 component vector.
  Vector3 operator-() const;
  
  Vector3 operator!() {
    return -(*this);
  }

  void Normalize();

  // comparisons by length.
  bool operator<(const Vector3 &v) const {
    return Magnitude() < v.Magnitude();
  }

  bool operator<=(const Vector3 &v) const {
    return Magnitude() <= v.Magnitude();
  }

  bool operator>(const Vector3 &v) const {
    return Magnitude() > v.Magnitude();
  }

  bool operator>=(const Vector3 &v) const {
    return Magnitude() >= v.Magnitude();
  }

  // comparison by actual components.
  bool operator!=(const Vector3 &v) const {
    return (x != v.x || y != v.y || z != v.z);
  }

  bool operator==(const Vector3 &v) const {
    return (x == v.x && y == v.y && z == v.z);
  }

  real32 Magnitude() const {
    return Sqrtf((x * x) + (y * y) + (z * z));
  }
  union {
    struct { real32 x, y, z; };
    struct { real32 r, g, b; };
    struct { real32 s, t, p; };
  };
};


typedef Vector3 Vec3;
typedef Vector3 Vec3f;
typedef Vector3 Vector3f;
}