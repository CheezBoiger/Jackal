// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/Vector2.hpp"


namespace jackal {


Vector2 Vector2::operator+(const Vector2 &v) const 
{
  return Vector2(
    x + v.x,
    y + v.y
  );
}


Vector2 Vector2::operator-(const Vector2 &v) const 
{
  return Vector2(
    x - v.x,
    y - v.y
  );
}


Vector2 Vector2::operator*(const real32 scale) const 
{
  return Vector2(
    x * scale,
    y * scale
  );
}


Vector2 Vector2::operator/(const real32 scaler) const
{
  return Vector2(
    x / scaler,
    y / scaler
  );
}


void Vector2::operator+=(const Vector2 &v)
{
  x += v.x;
  y += v.y;
}


void Vector2::operator-=(const Vector2 &v)
{
  x -= v.x;
  y -= v.y;
}


void Vector2::operator*=(const real32 scale)
{
  x *= scale;
  y *= scale;
}


void Vector2::operator/=(const real32 scaler)
{
  x /= scaler;
  y /= scaler;
}


Vector2 Vector2::operator-() const 
{
  return Vector2(
    -x,
    -y
  );
}


void Vector2::Normalize()
{
  real32 magnitude = Magnitude();
  x /= magnitude;
  y /= magnitude;
}
} // jackal