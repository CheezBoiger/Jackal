// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Math/MatrixMath.hpp"
#include "Core/Math/VectorMath.hpp"

namespace jkl {


Matrix4 Transpose(const Matrix4 &original)
{
  return original.Transpose();
}


Matrix4 Inverse(const Matrix4 &original)
{
  return original.Inverse();
}


Matrix4 Translate(const Matrix4 &original, const Vector3 &v)
{
  Matrix4 t(
    1,      0,      0,      0,
    0,      1,      0,      0,
    0,      0,      1,      0,
    v.x,    v.y,    v.z,    1
  );
  return original * t;
}


// Rotation Matrix, which combines all rotation matrices (Rotation for x, y, and z
// separately, into one rotator matrix. 
// TODO(Garcia): Transpose this rotation matrix by hand instead of wasting
// clock cycles like this...
Matrix4 Rotate(const Matrix4 &original, 
  const real32 angle, const Vector3 &axis)
{
  real32 oneMinusCosine = 1.0f - Cosf(angle);
  real32 cosine = Cosf(angle);
  real32 sine = Sinf(angle);
  Matrix4 rotator(
    cosine + (axis.x * axis.x) * oneMinusCosine,
    axis.x * axis.y * oneMinusCosine - axis.z * sine,
    axis.x * axis.z * oneMinusCosine + axis.y * sine,
    0,
  
    axis.y * axis.x * oneMinusCosine + axis.z * sine,
    cosine + (axis.y * axis.y) * oneMinusCosine,
    axis.y * axis.z * oneMinusCosine - axis.x * sine,
    0,

    axis.z * axis.x * oneMinusCosine - axis.y * sine,
    axis.z * axis.y * oneMinusCosine + axis.x * sine,
    cosine + (axis.z * axis.z) * oneMinusCosine,
    0,

    0, 0, 0, 1
  );
  // I'll fix this soon.
  return rotator.Transpose() * original;
}


Matrix4 Scale(const Matrix4 &original, const Vector3 &scale)
{
  Matrix4 scaleMatrix(
    scale.x,  0,        0,        0,
    0,        scale.y,  0,        0,
    0,        0,        scale.z,  0,
    0,        0,        0,        1
  );
  return scaleMatrix * original;
}


Matrix4 LookAtRH(const Vector3 &eye, const Vector3 &center, const Vector3 &up)
{
  Vector3 front(Normalize(center - eye));
  Vector3 right(Normalize(Cross(front, up)));
  Vector3 u(Cross(right, front));
  Matrix4 lookAt(
    right.x,          u.x,          -front.x,         0.0f,
    right.y,          u.y,          -front.y,         0.0f,
    right.z,          u.z,          -front.z,         0.0f,
    -Dot(right, eye), -Dot(u, eye), Dot(front, eye),  1.0f
  );
  return lookAt;
}


Matrix4 LookAtLH(const Vector3 &eye, const Vector3 &center, const Vector3 &up)
{
  Vector3 front(Normalize(center - eye));
  Vector3 right(Normalize(Cross(up, front)));
  Vector3 u(Cross(front, right));
  Matrix4 lookAt(
    right.x,          u.x,          front.x,          0.0f,
    right.y,          u.y,          front.y,          0.0f,
    right.z,          u.z,          front.z,          0.0f,
    -Dot(right, eye), -Dot(u, eye), -Dot(front, eye), 1.0f
  );
  return lookAt;
}


Matrix4 LookAt(const Vector3 &eye, const Vector3 &center, const Vector3 &up, bool left)
{
  if (left) {
    return LookAtLH(eye, center, up);
  }
  return LookAtRH(eye, center, up);
}


Matrix4 PerspectiveRH(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar)
{
  real32 tanHalfFov = Tanf(fov / 2.0f);
  Matrix4 perspective = Matrix4::Identity();
  perspective[3][3] = 0.0f;
  perspective[0][0] = 1.0f / (aspect * tanHalfFov);
  perspective[1][1] = 1.0f / (tanHalfFov);
  perspective[2][3] = -1.0f;

  perspective[2][2] = -(zFar + zNear) / (zFar - zNear);
  perspective[3][2] = -(2.0f * zFar * zNear) / (zFar - zNear);
  return perspective;
}


Matrix4 PerspectiveLH(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar)
{
  real32 tanHalfFov = Tanf(fov / 2.0f);
  Matrix4 perspective = Matrix4::Identity();
  perspective[3][3] = 0.0f;
  perspective[0][0] = 1.0f / (aspect * tanHalfFov);
  perspective[1][1] = 1.0f / (tanHalfFov);
  perspective[2][3] = 1.0f;

  perspective[2][2] = (zFar + zNear) / (zFar - zNear);
  perspective[3][2] = -(2.0f * zFar * zNear) / (zFar - zNear);
  return perspective;
}
} // jkl