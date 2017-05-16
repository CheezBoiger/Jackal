// Copyright (c) 2017 Jackal Engine, MIT License.

namespace jkl {



template<typename T> inline
Vector4<T> Normalize(const Vector4<T> &vec)
{
  T length = vec.Length();
  return Vector4<T>(
    vec.x / length,
    vec.y / length,
    vec.z / length,
    vec.w / length
  );
}


template<typename T> inline
Vector3<T> Normalize(const Vector3<T> &vec)
{
  T length = vec.Length();
  return Vector3<T>(
    vec.x / length,
    vec.y / length,
    vec.z / length
  );
}


template<typename T> inline
Vector2<T> Normalize(const Vector2<T> &vec)
{
  T length = vec.Length();
  return Vector2<T>(
    vec.x / length,
    vec.y / length
  );
}


template<typename T> inline
Vector3<T> Cross(const Vector3<T> &u, const Vector3<T> &v)
{
  return Vector3<T>(
    u.y * v.z - u.z * v.y,
    u.z * v.x - u.x * v.z,
    u.x * v.y - u.y * v.x
  );
}


template<typename T> inline
T Dot(const Vector3<T> &u, const Vector3<T> &v)
{
  return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}


template<typename T> inline
T Dot(const Vector4<T> &u, const Vector4<T> &v)
{
  return (u.x * v.x) + (u.y * v.y) + (u.z * v.z) + (u.w * v.w);
}


template<typename T> inline
T Dot(const Vector2<T> &u, const Vector2<T> &v)
{
  return (u.x * v.x) + (u.y * v.y);
}


// Precise method to calculate linear interpolation.
// This may be hardware dependent.
template<typename T> inline
Vector2<T> Lerp(const Vector2<T> &v0, const Vector2<T> &v1, T t)
{
  return v0 * (static_cast<T>(1) - t) + v1 * t;
}


template<typename T> inline
Vector3<T> Lerp(const Vector3<T> &v0, const Vector3<T> &v1, T t)
{
  return v0 * (static_cast<T>(1) - t) + v1 * t;
}
} // jkl
