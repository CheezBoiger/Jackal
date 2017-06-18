// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/VectorMath.hpp"

namespace jackal {



Vector4 Normalize(const Vector4 &vec)
{
  real32 length = vec.Magnitude();
  return Vector4(
    vec.x / length,
    vec.y / length,
    vec.z / length,
    vec.w / length
  );
}


Vector3 Normalize(const Vector3 &vec)
{
  real32 length = vec.Magnitude();
  return Vector3(
    vec.x / length,
    vec.y / length,
    vec.z / length
  );
}


Vector2 Normalize(const Vector2 &vec)
{
  real32 length = vec.Magnitude();
  return Vector2(
    vec.x / length,
    vec.y / length
  );
}


Vector3 Cross(const Vector3 &u, const Vector3 &v)
{
  return Vector3(
    u.y * v.z - u.z * v.y,
    u.z * v.x - u.x * v.z,
    u.x * v.y - u.y * v.x
  );
}


real32 Dot(const Vector3 &u, const Vector3 &v)
{
  return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}


real32 Dot(const Vector4 &u, const Vector4 &v)
{
  return (u.x * v.x) + (u.y * v.y) + (u.z * v.z) + (u.w * v.w);
}


real32 Dot(const Vector2 &u, const Vector2 &v)
{
  return (u.x * v.x) + (u.y * v.y);
}


// Precise method to calculate linear interpolation.
// This may be hardware dependent.
Vector2 Lerp(const Vector2 &v0, const Vector2 &v1, real32 t)
{
  return v0 * (1.0f - t) + v1 * t;
}


Vector3 Lerp(const Vector3 &v0, const Vector3 &v1, real32 t)
{
  return v0 * (1.0f - t) + v1 * t;
}
} // jackal
