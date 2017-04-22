//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once


namespace jkl {


template<typename T>
Vector4<T> Vector4<T>::operator+(const Vector4 &v) const 
{
  return Vector4(
    x + v.x,
    y + v.y,
    z + v.z,
    w + v.w
  );
}


template<typename T>
Vector4<T> Vector4<T>::operator-(const Vector4 &v) const 
{
  return Vector4(
    x - v.x,
    y - v.y,
    z - v.z,
    w - v.w
  );
}


template<typename T>
Vector4<T> Vector4<T>::operator*(const Vector4 &v) const 
{
  return Vector4(
    x * v.x,
    y * v.y,
    z * v.z,
    w * v.w
  );
}


template<typename T>
Vector4<T> Vector4<T>::operator*(const T scale) const 
{
  return Vector4(
    x * scale,
    y * scale,
    z * scale,
    w * scale
  );
}


template<typename T>
Vector4<T> Vector4<T>::operator/(const Vector4 &v) const 
{
  return Vector4(
    x / v.x,
    y / v.y,
    z / v.z,
    w / v.w
  );
}


template<typename T>
Vector4<T> Vector4<T>::operator/(const T scaler) const
{
  return Vector4(
    x / scaler,
    y / scaler,
    z / scaler,
    w / scaler
  );
}


template<typename T>
void Vector4<T>::operator+=(const Vector4 &v)
{
  x += v.x;
  y += v.y;
  z += v.z;
  w += v.w;
}


template<typename T>
void Vector4<T>::operator-=(const Vector4 &v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  w -= v.w;
}


template<typename T>
void Vector4<T>::operator*=(const Vector4 &v)
{
  x *= v.x;
  y *= v.y;
  z *= v.z;
  w *= v.w;
}


template<typename T>
void Vector4<T>::operator*=(const T scale)
{
  x *= scale;
  y *= scale;
  z *= scale;
  w *= scale;
}


template<typename T>
void Vector4<T>::operator/=(const Vector4 &v)
{
  x /= v.x;
  y /= v.y;
  z /= v.z;
  w /= v.w;
}


template<typename T>
void Vector4<T>::operator/=(const T scaler)
{
  x /= scaler;
  y /= scaler;
  z /= scaler;
  w /= scaler;
}


template<typename T>
Vector4<T> Vector4<T>::operator-() const 
{
  return Vector4(
    -x,
    -y,
    -z,
    -w
  );
}


template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3 &v) const 
{
  return Vector3(
    x + v.x,
    y + v.y,
    z + v.z
  );
}


template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3 &v) const 
{
  return Vector3(
    x - v.x,
    y - v.y,
    z - v.z
  );
}


template<typename T>
Vector3<T> Vector3<T>::operator*(const Vector3 &v) const 
{
  return Vector3(
    x * v.x,
    y * v.y,
    z * v.z
  );
}


template<typename T>
Vector3<T> Vector3<T>::operator*(const T scale) const 
{
  return Vector3(
    x * scale,
    y * scale,
    z * scale
  );
}


template<typename T>
Vector3<T> Vector3<T>::operator/(const Vector3 &v) const 
{
  return Vector3(
    x / v.x,
    y / v.y,
    z / v.z
  );
}


template<typename T>
Vector3<T> Vector3<T>::operator/(const T scaler) const
{
  return Vector3(
    x / scaler,
    y / scaler,
    z / scaler
  );
}


template<typename T>
void Vector3<T>::operator+=(const Vector3 &v)
{
  x += v.x;
  y += v.y;
  z += v.z;
}


template<typename T>
void Vector3<T>::operator-=(const Vector3 &v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
}


template<typename T>
void Vector3<T>::operator*=(const Vector3 &v)
{
  x *= v.x;
  y *= v.y;
  z *= v.z;
}


template<typename T>
void Vector3<T>::operator*=(const T scale)
{
  x *= scale;
  y *= scale;
  z *= scale;
}


template<typename T>
void Vector3<T>::operator/=(const Vector3 &v)
{
  x /= v.x;
  y /= v.y;
  z /= v.z;
}


template<typename T>
void Vector3<T>::operator/=(const T scaler)
{
  x /= scaler;
  y /= scaler;
  z /= scaler;
}


template<typename T>
Vector3<T> Vector3<T>::operator-() const 
{
  return Vector3(
    -x,
    -y,
    -z
  );
}


template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2 &v) const 
{
  return Vector2(
    x + v.x,
    y + v.y
  );
}


template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2 &v) const 
{
  return Vector2(
    x - v.x,
    y - v.y
  );
}


template<typename T>
Vector2<T> Vector2<T>::operator*(const Vector2 &v) const 
{
  return Vector2(
    x * v.x,
    y * v.y
  );
}


template<typename T>
Vector2<T> Vector2<T>::operator*(const T scale) const 
{
  return Vector2(
    x * scale,
    y * scale
  );
}


template<typename T>
Vector2<T> Vector2<T>::operator/(const Vector2 &v) const 
{
    return Vector2(
      x / v.x,
      y / v.y
    );
}


template<typename T>
Vector2<T> Vector2<T>::operator/(const T scaler) const
{
  return Vector2(
    x / scaler,
    y / scaler
  );
}


template<typename T>
void Vector2<T>::operator+=(const Vector2 &v)
{
  x += v.x;
  y += v.y;
}


template<typename T>
void Vector2<T>::operator-=(const Vector2 &v)
{
  x -= v.x;
  y -= v.y;
}


template<typename T>
void Vector2<T>::operator*=(const Vector2 &v)
{
  x *= v.x;
  y *= v.y;
}


template<typename T>
void Vector2<T>::operator*=(const T scale)
{
  x *= scale;
  y *= scale;
}


template<typename T>
void Vector2<T>::operator/=(const Vector2 &v)
{
  x /= v.x;
  y /= v.y;
}


template<typename T>
void Vector2<T>::operator/=(const T scaler)
{
  x /= scaler;
  y /= scaler;
}


template<typename T>
Vector2<T> Vector2<T>::operator-() const 
{
  return Vector2(
    -x,
    -y
  );
}
} // jkl