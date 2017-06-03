// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/Vector3.hpp"


namespace jkl {


Vector3 Vector3::operator+(const Vector3 &v) const 
{
  return Vector3(
    x + v.x,
    y + v.y,
    z + v.z
  );
}


Vector3 Vector3::operator-(const Vector3 &v) const 
{
  return Vector3(
    x - v.x,
    y - v.y,
    z - v.z
  );
}


Vector3 Vector3::operator*(const Vector3 &v) const 
{
  return Vector3(
    x * v.x,
    y * v.y,
    z * v.z
  );
}


Vector3 Vector3::operator*(const real32 scale) const 
{
  return Vector3(
    x * scale,
    y * scale,
    z * scale
  );
}


Vector3 Vector3::operator/(const Vector3 &v) const 
{
  return Vector3(
    x / v.x,
    y / v.y,
    z / v.z
  );
}


Vector3 Vector3::operator/(const real32 scaler) const
{
  return Vector3(
    x / scaler,
    y / scaler,
    z / scaler
  );
}


void Vector3::operator+=(const Vector3 &v)
{
  x += v.x;
  y += v.y;
  z += v.z;
}


void Vector3::operator-=(const Vector3 &v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
}


void Vector3::operator*=(const Vector3 &v)
{
  x *= v.x;
  y *= v.y;
  z *= v.z;
}


void Vector3::operator*=(const real32 scale)
{
  x *= scale;
  y *= scale;
  z *= scale;
}


void Vector3::operator/=(const Vector3 &v)
{
  x /= v.x;
  y /= v.y;
  z /= v.z;
}


void Vector3::operator/=(const real32 scaler)
{
  x /= scaler;
  y /= scaler;
  z /= scaler;
}


Vector3 Vector3::operator-() const 
{
  return Vector3(
    -x,
    -y,
    -z
  );
}
} // jkl