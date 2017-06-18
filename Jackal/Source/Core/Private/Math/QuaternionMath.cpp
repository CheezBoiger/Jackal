// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/QuaternionMath.hpp"

namespace jkl {


Quaternion Normalize(const Quaternion &q)
{
  real32 norm = q.Magnitude();
  return (q / norm);
}


Quaternion AngleAxis(real32 angle, const Vector3f &axis)
{
  Quaternion localQuat (
    Cosf(angle / 2.0f),
    axis.x * Sinf(angle / 2.0f),
    axis.y * Sinf(angle / 2.0f),
    axis.z * Sinf(angle / 2.0f)
  );
  return localQuat; 
}


Quaternion ToQuaternion(const Vector3f &eulerAngle)
{
  Quaternion q;
  real32 t0 = Cosf(eulerAngle.x * 0.5f);
  real32 t1 = Sinf(eulerAngle.x * 0.5f);
  real32 t2 = Cosf(eulerAngle.y * 0.5f);
  real32 t3 = Sinf(eulerAngle.y * 0.5f);
  real32 t4 = Cosf(eulerAngle.z * 0.5f);
  real32 t5 = Sinf(eulerAngle.z * 0.5f);
  
  q.w = t0*t2*t4+t1*t3*t5;
  q.x = t0*t3*t4-t1*t2*t5;
  q.y = t0*t2*t5+t1*t3*t4;
  q.z = t1*t2*t4-t0*t3*t5;

  return q;
}


Quaternion Slerp(const Quaternion &q0, const Quaternion &q1, real32 t)
{
  return q0;
}
} // jkl
