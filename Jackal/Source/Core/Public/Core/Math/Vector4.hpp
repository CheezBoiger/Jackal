// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Vector3.hpp"
#include "Common.hpp"


namespace jkl {


// 4-component vector type object.
// handles most of the work in terms of w compoenents or a components.
// This can be useful for colors, or matrices.
// use 3-component vectors when dealing with graphics programming!
// Do not use this vector4 object, as the w component matters!
struct Vector4 {
  // Constructors.
  Vector4( 
    real32 x = 0.0f, 
    real32 y = 0.0f, 
    real32 z = 0.0f, 
    real32 w = 1.0f
  ) : x(x), y(y), z(z), w(w) 
    { }

  Vector4(
    const Vector3 &v, 
    real32 w = 1.0f
  ) : x(v.x), y(v.y), z(v.z), w(w)
    { }

  Vector4(
    const Vector2 &v, 
    real32 z = 0.0f, 
    real32 w = 1.0f
  ) : x(v.x), y(v.y), z(z), w(w)
    { }

  // Adds this vector to v, and returns a new
  // 4 component vector.
  Vector4 operator+(const Vector4 &v) const;

  // Subtracts this vector to v, and returns a new
  // 4 component vector.
  Vector4 operator-(const Vector4 &v) const;
  
  // Multiplies this vector to v, and returns a new
  // 4 component vector.
  Vector4 operator*(const Vector4 &v) const;

  // Multiplies this vector to a scaler value, and 
  // returns a new 4 component vector.
  Vector4 operator*(const real32 scale) const;

  // Performs division of this vector with vector v,
  // and returns a resulting 4 component vector.
  Vector4 operator/(const Vector4 &v) const;

  // Vector division. Divides this vector by the scaler
  // value, and returns a new, fresh copy of a 4-component 
  // vector.
  Vector4 operator/(const real32 scaler) const;

  // Add values of v into this vector. This will not
  // create a new vector object, it will instead modify
  // this vector.
  void operator+=(const Vector4 &v);

  // Subtract values of v into this vector. This will not
  // create a new vector object, it will instead modify
  // this vector.
  void operator-=(const Vector4 &v);

  // Multiply values of v into this vector. This will not
  // create a new vector object, it will instead modify
  // this vector.
  void operator*=(const Vector4 &v);

  // Multiply a scaler value into this vector. Thise will 
  // not create a new vector object, it will instead modify
  // this vector.
  void operator*=(const real32 scale);

  // Divide values of v into this vector. This will not 
  // create a new vector object, it will instead modify 
  // this vector.
  void operator/=(const Vector4 &v);

  // Divides this vector's 4 components with the provided
  // scaler value. Modifies this vector object.
  void operator/=(const real32 scaler);

  void Normalize();

  // Take the invert of this vector, and return it as
  // a new 4 component vector.
  Vector4 operator-() const;

  Vector4 operator!() const {
    return -(*this);
  }

  // Comparison by length.
  bool operator<(const Vector4 &v) const {
    return Magnitude() < v.Magnitude();
  }

  bool operator>(const Vector4 &v) const {
    return Magnitude() > v.Magnitude();
  }

  bool operator<=(const Vector4 &v) const {
    return Magnitude() <= v.Magnitude();
  }

  bool operator>=(const Vector4 &v) const {
    return Magnitude() >= v.Magnitude();
  }

  // Comparison by actual values in the vector.
  bool operator!=(const Vector4 &v) const {
    return (x != v.x || y != v.y || z != v.z || w != v.w);  
  }

  bool operator==(const Vector4 &v) const {
    return (x == v.x && y == v.y && z == v.z && w == v.w);
  }


  // Returns the length/magnitude of this vector.
  real32 Magnitude() const {
    return Sqrtf((x * x) + (y * y) + (z * z) + (w * w)); 
  }

  union {
    struct { real32 x, y, z, w; };
    struct { real32 r, g, b, a; };
    struct { real32 s, t, p, q; };
  };
};


typedef Vector4 Vec4;
typedef Vector4 Vec4f;
typedef Vector4 Vector4f;
typedef Vector4 Colorf;
} // jkl
