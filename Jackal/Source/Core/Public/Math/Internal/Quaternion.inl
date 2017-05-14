//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once


namespace jkl {


template<typename T>
Quaternion<T> Quaternion<T>::operator+(const Quaternion &q) const 
{
  return Quaternion(
    w + q.w,
    x + q.x,
    y + q.y,
    z + q.z
  );
}


template<typename T>
Quaternion<T> Quaternion<T>::operator-(const Quaternion &q) const
{
  return Quaternion(
    w - q.w,
    x - q.x,
    y - q.y,
    z - q.z
  );
}


template<typename T>
Quaternion<T> Quaternion<T>::operator*(const Quaternion &q) const 
{
  return Quaternion(
    (w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
    (w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
    (w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
    (w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
  );
}


template<typename T>
Quaternion<T> Quaternion<T>::operator/(const T scaler) const
{
  return Quaternion(
    w / scaler,
    x / scaler,
    y / scaler,
    z / scaler
  );
}


template<typename T>
void Quaternion<T>::operator*=(const Quaternion &q) 
{
  Quaternion ori = *this;
  w = (ori.w * q.w) - (ori.x * q.x) - (ori.y * q.y) - (ori.z * q.z);
  x = (ori.w * q.x) + (ori.x * q.w) + (ori.y * q.z) - (ori.z * q.y);
  y = (ori.w * q.y) - (ori.x * q.z) + (ori.y * q.w) + (ori.z * q.x);
  z = (ori.w * q.z) + (ori.x * q.y) - (ori.y * q.x) + (ori.z * q.w);
}


template<typename T>
void Quaternion<T>::operator+=(const Quaternion &q)
{
  w += q.w;
  x += q.x;
  y += q.y;
  z += q.z;
}


template<typename T>
void Quaternion<T>::operator-=(const Quaternion &q)
{
  w -= q.w;
  x -= q.x;
  y -= q.y;
  z -= q.z;
}


template<typename T>
Quaternion<T> Quaternion<T>::operator*(const T scaler) const
{
  return Quaternion(
    w * scaler,
    x * scaler,
    y * scaler,
    z * scaler
  );
}


template<typename T>
void Quaternion<T>::operator*=(const T scaler)
{
  w *= scaler;
  x *= scaler;
  y *= scaler;
  z *= scaler;
}


template<typename T>
Quaternion<T> Quaternion<T>::operator/(const Quaternion &q) const
{
  return Quaternion(
    w / q.w,
    x / q.x,
    y / q.y,
    z / q.z
  );
}


template<typename T>
void Quaternion<T>::operator/=(const Quaternion &q)
{
  w /= q.w;
  x /= q.x;
  y /= q.y;
  z /= q.z;
}


template<typename T>
void Quaternion<T>::operator/=(const T scaler)
{
  w /= scaler;
  x /= scaler;
  y /= scaler;
  z /= scaler;
}


template<typename T>
Quaternion<T> Quaternion<T>::Conjugate() const
{
  return Quaternion(w, -x, -y, -z);
}


template<typename T>
Quaternion<T> Quaternion<T>::Inverse() const
{
  Quaternion conjugate = Conjugate();
  T norm = Length();
  norm = norm * norm;
  // Inverse is q* / norm^2
  conjugate /= norm;
  return conjugate;
}
} // jkl