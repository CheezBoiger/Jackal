//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "../platform/public/jtypes.hpp"
#include "../platform/public/platform.hpp"
#include "common.hpp"


namespace jkl {


template<typename T> struct Vector3;
template<typename T> struct Vector2;


// 4-component vector type object.
// handles most of the work in terms of w compoenents or a components.
// This can be useful for colors, or matrices.
// use 3-component vectors when dealing with graphics programming!
// Do not use this vector4 object, as the w component matters!
template<typename T>
struct Vector4 {
  Vector4( 
    T x = static_cast<T>(0), 
    T y = static_cast<T>(0), 
    T z = static_cast<T>(0), 
    T w = static_cast<T>(1)
  ) : x(x), y(y), z(z), w(w) 
    { }

  Vector4(
    const Vector3<T> &v, 
    T w = static_cast<T>(1)
  ) : x(v.x), y(v.y), z(v.z), w(w)
    { }

  Vector4(
    const Vector2<T> &v, 
    T z = static_cast<T>(0), 
    T w = static_cast<T>(1)
  ) : x(v.x), y(v.y), z(z), w(w)
    { }

  Vector4 operator+(const Vector4 &v) {
    return Vector4(
      x + v.x,
      y + v.y,
      z + v.z,
      w + v.w
    );
  }

  Vector4 operator-(const Vector4 &v) {
    return Vector4(
      x - v.x,
      y - v.y,
      z - v.z,
      w - v.w
    );
  }
  
  Vector4 operator*(const Vector4 &v) {
    return Vector4(
      x * v.x,
      y * v.y,
      z * v.z,
      w * v.w
    );
  }

  Vector4 operator/(const Vector4 &v) {
    static_assert<>(v.x != 0 || v.y != 0 || v.z != 0 || v.w != 0, "Divide by zero!"); 
    return Vector4(
      x / v.x,
      y / v.y,
      z / v.z,
      w / v.w
    );
  }

  Vector4 operator-() {
    return Vector4(
      -x,
      -y,
      -z,
      -w
    );
  }

  Vector4 operator!() {
    return -(*this);
  }

  // Comparison by length.
  bool operator<(const Vector4 &v) {
    return Length() < v.Length();
  }

  bool operator>(const Vector4 &v) {
    return Length() > v.Length();
  }

  bool operator<=(const Vector4 &v) {
    return Length() <= v.Length();
  }

  bool operator>=(const Vector4 &v) {
    return Length() >= v.Length();
  }

  // Comparison by actual values in the vector.
  bool operator!=(const Vector4 &v) {
    return (x != v.x || y != v.y || z != v.z || w != v.w);  
  }

  bool operator==(const Vector4 &v) {
    return (x == v.x && y == v.y && z == v.z && w == v.w);
  }


  // Returns the length of this vector.
  T Length() {
    return Sqrt((x * x) + (y * y) + (z * z) + (w * w)); 
  }

  union {
    struct { T x, y, z, w; };
    struct { T r, g, b, a; };
    struct { T s, t, r, q; };
  };
};


// 3-Component vector object for use in mathematics inside jackal.
// This is verty handy for rotations, scaling, translating, and whatnot.
// Most of the transformation, scaling, shearing, and rotations will be using
// this vector object.
template<typename T>
struct Vector3 {

  Vector3(
    T x = static_cast<T>(0),
    T y = static_cast<T>(0),
    T z = static_cast<T>(0)
  ) : x(x), y(y), z(z)
  { }

  // Performs perspective divide.
  Vector3(const Vector4<T> &v)
    : x(v.x / v.w), y(v.y / v.w), z(v.z / v.w)
    { }

  Vector3(
    const Vector2<T> &v, 
    T z = static_cast<T>(0)
  ) : x(v.x), y(v.y), z(z)
    { }

  Vector3 operator+(const Vector3 &v) {
    return Vector3(
      x + v.x,
      y + v.y,
      z + v.z
    );
  }

  Vector3 operator-(const Vector3 &v) {
    return Vector3(
      x - v.x,
      y - v.y,
      z - v.z
    );
  }
  
  Vector3 operator*(const Vector3 &v) {
    return Vector3(
      x * v.x,
      y * v.y,
      z * v.z
    );
  }

  Vector3 operator*(const T scale) {
    return Vector3(
      x * scale,
      y * scale,
      z * scale
    );
  }

  Vector3 operator/(const Vector3 &v) {
    static_assert(v.x != 0 || v.y != 0 || v.z != 0, "Divide by zero!");
    return Vector3(
      x / v.x,
      y / v.y,
      z / v.z
    );
  }

  Vector3 operator-() {
    return Vector3(
      -x,
      -y,
      -z
    );
  }
  
  Vector3 operator!() {
    return -(*this);
  }

  // comparisons by length.
  bool operator<(const Vector3 &v) {
    return Length() < v.Length();
  }

  bool operator<=(const Vector3 &v) {
    return Length() <= v.Length();
  }

  bool operator>(const Vector3 &v) {
    return Length() > v.Length();
  }

  bool operator>=(const Vector3 &v) {
    return Length() >= v.Length();
  }

  // comparison by actual components.
  bool operator!=(const Vector3 &v) {
    return (x != v.x || y != v.y || z != v.z);
  }

  bool operator==(const Vector3 &v) {
    return (x == v.x && y == v.y && z == v.z);
  }

  T Length() {
    return Sqrt((x * x) + (y * y) + (z * z));
  }
  union {
    struct { T x, y, z; };
    struct { T r, g, b; };
    struct { T s, t, r; };
  };
};


template<typename T>
struct Vector2 {

  Vector2(
    T x = static_cast<T>(0),
    T y = static_cast<T>(0)
  ) : x(x), y(y)
    { }

  Vector2 operator+(const Vector2 &v) {
    return Vector2(
      x + v.x,
      y + v.y
    );
  }

  Vector2 operator-(const Vector2 &v) {
    return Vector2(
      x - v.x,
      y - v.y
    );
  }

  Vector2 operator*(const Vector2 &v) {
    return Vector2(
      x * v.x,  
      y * v.y
    );
  }

  Vector2 operator/(const Vector2 &v) {
    static_assert(v.x != 0 || v.y != 0, "Divide by zero!")
    return Vector2(
      x / v.x,
      y / v.y
    );  
  }

  Vector2 operator-() {
    return Vector2(
      -x,
      -y
    );
  }

  Vector2 operator!() {
    return -(*this);
  }

  // comparisons by length.
  bool operator<(const Vector2 &v) {
    return Length() < v.Length();
  }

  bool operator<=(const Vector2 &v) {
    return Length() <= v.Length();
  }

  bool operator>(const Vector2 &v) {
    return Length() > v.Length();
  }

  bool operator>=(const Vector2 &v) {
    return Length() >= v.Length();
  }

  // comparisons by actual component values.
  bool operator!=(const Vector2 &v) { 
    return (x != v.x || y != v.y);
  }

  bool operator==(const Vector2 &v) {
    return (x == v.x && y == v.y);
  }

  T Length() {
    return Sqrt((x * x) + (y * y));
  }

  union {
    struct { T x, y; };
    struct { T r, g; };
    struct { T s, t; };
  };
};


typedef Vector3<real32> Vec3;
typedef Vector2<real32> Vec2;
typedef Vector4<real32> Vec4;
} // jkl