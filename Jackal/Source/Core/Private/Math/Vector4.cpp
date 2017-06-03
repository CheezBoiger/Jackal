// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Math/Vector4.hpp"


namespace jkl {


Vector4 Vector4::operator+(const Vector4 &v) const 
{
  return Vector4(
    x + v.x,
    y + v.y,
    z + v.z,
    w + v.w
  );
}


Vector4 Vector4::operator-(const Vector4 &v) const 
{
  return Vector4(
    x - v.x,
    y - v.y,
    z - v.z,
    w - v.w
  );
}


Vector4 Vector4::operator*(const Vector4 &v) const 
{
  return Vector4(
    x * v.x,
    y * v.y,
    z * v.z,
    w * v.w
  );
}


Vector4 Vector4::operator*(const real32 scale) const 
{
  return Vector4(
    x * scale,
    y * scale,
    z * scale,
    w * scale
  );
}


Vector4 Vector4::operator/(const Vector4 &v) const 
{
  return Vector4(
    x / v.x,
    y / v.y,
    z / v.z,
    w / v.w
  );
}


Vector4 Vector4::operator/(const real32 scaler) const
{
  return Vector4(
    x / scaler,
    y / scaler,
    z / scaler,
    w / scaler
  );
}


void Vector4::operator+=(const Vector4 &v)
{
  x += v.x;
  y += v.y;
  z += v.z;
  w += v.w;
}


void Vector4::operator-=(const Vector4 &v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  w -= v.w;
}


void Vector4::operator*=(const Vector4 &v)
{
  x *= v.x;
  y *= v.y;
  z *= v.z;
  w *= v.w;
}


void Vector4::operator*=(const real32 scale)
{
  x *= scale;
  y *= scale;
  z *= scale;
  w *= scale;
}


void Vector4::operator/=(const Vector4 &v)
{
  x /= v.x;
  y /= v.y;
  z /= v.z;
  w /= v.w;
}


void Vector4::operator/=(const real32 scaler)
{
  x /= scaler;
  y /= scaler;
  z /= scaler;
  w /= scaler;
}


Vector4 Vector4::operator-() const 
{
  return Vector4(
    -x,
    -y,
    -z,
    -w
  );
}
} // jkl