// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"
#include "Common.hpp"


namespace jkl {


struct Vector2 {

  Vector2(
    real32 x = 0.0f,
    real32 y = 0.0f
  ) : x(x), y(y)
    { }

  // Adds this vector to v, and returns a new
  // 2 component vector.
  Vector2 operator+(const Vector2 &v) const;

  // Subtracts this vector to v, and returns a new
  // 2 component vector.
  Vector2 operator-(const Vector2 &v) const;

  // Multiplies this vector to v, and returns a new
  // 2 component vector.
  Vector2 operator*(const Vector2 &v) const;

  // Multiplies this vector to a scaler value, and 
  // returns a new 2 component vector.
  Vector2 operator*(const real32 scale) const;

  // Performs division of this vector with vector v,
  // and returns a resulting 2 component vector.
  Vector2 operator/(const Vector2 &v) const;

  // Vector division. Divides this vector by the scaler
  // value, and returns a new, fresh copy of a 2-component 
  // vector.
  Vector2 operator/(const real32 scaler) const;

  // Add a 2-component vector v into this vector.
  // It will not create a new vector, it will modify
  // this vector instead.
  void operator+=(const Vector2 &v);

  // Subtract a 2-component vector v into this vector.
  // It will not create a new vector, it will modify 
  // this vector instead.
  void operator-=(const Vector2 &v);

  // Multiply a 2-component vector v into this vector.
  // It will not create a new vector, it will modify
  // this vector instead.
  void operator*=(const Vector2 &v);

  // Multiply a scaler value into this vector.
  // It will not create a new vector, it will modify 
  // this vector instead.
  void operator*=(const real32 scale);
  
  // Divide a 2-component vector v into this vector.
  // It will not create a new vector, it will modify
  // this vector instead.
  void operator/=(const Vector2 &v);

  // Divides this vector's 2 components with the provided
  // scaler value. Modifies this vector object.
  void operator/=(const real32 scaler);

  // Take the invert of this vector, and return it as
  // a new 2 component vector.
  Vector2 operator-() const;

  Vector2 operator!() const {
    return -(*this);
  }

  // comparisons by length.
  bool operator<(const Vector2 &v) const {
    return Length() < v.Length();
  }

  bool operator<=(const Vector2 &v) const {
    return Length() <= v.Length();
  }

  bool operator>(const Vector2 &v) const {
    return Length() > v.Length();
  }

  bool operator>=(const Vector2 &v) const {
    return Length() >= v.Length();
  }

  // comparisons by actual component values.
  bool operator!=(const Vector2 &v) const { 
    return (x != v.x || y != v.y);
  }

  bool operator==(const Vector2 &v) const {
    return (x == v.x && y == v.y);
  }

  real32 Length() const {
    return Sqrtf((x * x) + (y * y));
  }

  union {
    struct { real32 x, y; };
    struct { real32 r, g; };
    struct { real32 s, t; };
  };
};


typedef Vector2 Vec2;
typedef Vector2 Vec2f;
typedef Vector2 Vector2f;
} // jkl