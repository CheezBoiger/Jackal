// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/Quaternion.hpp"


namespace jackal {


Quaternion Quaternion::operator+(const Quaternion &q) const 
{
  return Quaternion(
    w + q.w,
    x + q.x,
    y + q.y,
    z + q.z
  );
}


Quaternion Quaternion::operator-(const Quaternion &q) const
{
  return Quaternion(
    w - q.w,
    x - q.x,
    y - q.y,
    z - q.z
  );
}


Quaternion Quaternion::operator*(const Quaternion &q) const 
{
  return Quaternion(
    (w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
    (w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
    (w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
    (w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
  );
}


Quaternion Quaternion::operator/(const real32 scaler) const
{
  return Quaternion(
    w / scaler,
    x / scaler,
    y / scaler,
    z / scaler
  );
}


void Quaternion::operator*=(const Quaternion &q) 
{
  Quaternion ori = *this;
  w = (ori.w * q.w) - (ori.x * q.x) - (ori.y * q.y) - (ori.z * q.z);
  x = (ori.w * q.x) + (ori.x * q.w) + (ori.y * q.z) - (ori.z * q.y);
  y = (ori.w * q.y) - (ori.x * q.z) + (ori.y * q.w) + (ori.z * q.x);
  z = (ori.w * q.z) + (ori.x * q.y) - (ori.y * q.x) + (ori.z * q.w);
}


void Quaternion::operator+=(const Quaternion &q)
{
  w += q.w;
  x += q.x;
  y += q.y;
  z += q.z;
}


void Quaternion::operator-=(const Quaternion &q)
{
  w -= q.w;
  x -= q.x;
  y -= q.y;
  z -= q.z;
}


Quaternion Quaternion::operator*(const real32 scaler) const
{
  return Quaternion(
    w * scaler,
    x * scaler,
    y * scaler,
    z * scaler
  );
}


void Quaternion::operator*=(const real32 scaler)
{
  w *= scaler;
  x *= scaler;
  y *= scaler;
  z *= scaler;
}


Quaternion Quaternion::operator/(const Quaternion &q) const
{
  return Quaternion(
    w / q.w,
    x / q.x,
    y / q.y,
    z / q.z
  );
}


void Quaternion::operator/=(const Quaternion &q)
{
  w /= q.w;
  x /= q.x;
  y /= q.y;
  z /= q.z;
}


void Quaternion::operator/=(const real32 scaler)
{
  w /= scaler;
  x /= scaler;
  y /= scaler;
  z /= scaler;
}


Quaternion Quaternion::Conjugate() const
{
  return Quaternion(w, -x, -y, -z);
}


Quaternion Quaternion::Inverse() const
{
  Quaternion conjugate = Conjugate();
  real32 norm = Magnitude();
  norm = norm * norm;
  // Inverse is q* / norm^2
  conjugate /= norm;
  return conjugate;
}


Vector3f Quaternion::ToEulerAngles() const
{
  Vector3f eulerAngles;
  real32 ysqrt = y * y;
  
  real32 t0 = 2.0f * (w * x + y * z);
  real32 t1 = 1.0f - 2.0f * (x * x  + ysqrt);
  eulerAngles.x = atan2f(t0, t1);

  real32 t2 = 2.0f * (w * y  - z * x);
  t2 = t2 > 1.0f ? 1.0f : t2;
  t2 = t2 < -1.0f ? -1.0f : t2;
  eulerAngles.y = asinf(t2);

  real32 t3 = 2.0f * (w * z + x * y);
  real32 t4 = 1.0f - 2.0f * (ysqrt + z * z);
  eulerAngles.z = atan2f(t3, t4);

  return eulerAngles;
}


Matrix4f Quaternion::ToMatrix4() const
{
  return Matrix4f(
    1.0f - 2.0f*(y*y + z*z),  2.0f*(x*y + w*z),         2.0f*(x*z - w*y),         0.0f,
    2.0f*(x*y - w*z),         1.0f - 2.0f*(x*x + z*z),  2.0f*(y*z + w*x),         0.0f,
    2.0f*(x*z + w*y),         2.0f*(y*z - w*x),         1.0f - 2.0f*(x*x + y*y),  0.0f,
    0.0f,                     0.0f,                     0.0f,                     1.0f   
  );
}


void Quaternion::Normalize()
{
  real32 norm = Magnitude();
  w /= norm;
  x /= norm;
  y /= norm;
  z /= norm;
}
} // jackal