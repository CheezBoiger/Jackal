//
// Copyright (c) Jackal Engine. MIT License.
//

//#include "../matrix_math.hpp"
#include "../VectorMath.hpp"

namespace jkl {


template<typename T> inline
Matrix4x4<T> Translate(const Matrix4x4<T> &original, const Vector3<T> &v)
{
  Matrix4x4<T> t(
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
template<typename T> inline
Matrix4x4<T> Rotate(const Matrix4x4<T> &original, 
  const T angle, const Vector3<T> &axis)
{
  T oneMinusCosine = static_cast<T>(1) - Cos(angle);
  T cosine = Cos(angle);
  T sine = Sin(angle);
  Matrix4x4<T> rotator(
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


template<typename T>
Matrix4x4<T> Scale(const Matrix4x4<T> &original, const Vector3<T> &scale)
{
  Matrix4x4<T> scaleMatrix(
    scale.x,  0,        0,        0,
    0,        scale.y,  0,        0,
    0,        0,        scale.z,  0,
    0,        0,        0,        1
  );
  return scaleMatrix * original;
}


template<typename T> inline
Matrix4x4<T> LookAtRH(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up)
{
  Vector3<T> front(Normalize(center - eye));
  Vector3<T> right(Normalize(Cross(front, up)));
  Vector3<T> u(Cross(right, front));
  Matrix4x4<T> lookAt(
    right.x,          u.x,          -front.x,         static_cast<T>(0),
    right.y,          u.y,          -front.y,         static_cast<T>(0),
    right.z,          u.z,          -front.z,         static_cast<T>(0),
    -Dot(right, eye), -Dot(u, eye), Dot(front, eye),  static_cast<T>(1)
  );
  return lookAt;
}


template<typename T> inline
Matrix4x4<T> LookAtLH(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up)
{
  Vector3<T> front(Normalize(center - eye));
  Vector3<T> right(Normalize(Cross(up, front)));
  Vector3<T> u(Cross(front, right));
  Matrix4x4<T> lookAt(
    right.x,          u.x,          front.x,          static_cast<T>(0),
    right.y,          u.y,          front.y,          static_cast<T>(0),
    right.z,          u.z,          front.z,          static_cast<T>(0),
    -Dot(right, eye), -Dot(u, eye), -Dot(front, eye), static_cast<T>(1)
  );
  return lookAt;
}


template<typename T> inline
Matrix4x4<T> LookAt(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up, bool left)
{
  if (left) {
    return LookAtLH(eye, center, up);
  }
  return LookAtRH(eye, center, up);
}


template<typename T> inline
Matrix4x4<T> PerspectiveRH(const T fov, const T aspect, const T zNear, const T zFar)
{
  T tanHalfFov = Tan(fov / static_cast<T>(2));
  Matrix4x4<T> perspective = Matrix4x4<T>::Identity();
  perspective[3][3] = static_cast<T>(0);
  perspective[0][0] = static_cast<T>(1) / (aspect * tanHalfFov);
  perspective[1][1] = static_cast<T>(1) / (tanHalfFov);
  perspective[2][3] = -static_cast<T>(1);

  perspective[2][2] = -(zFar + zNear) / (zFar - zNear);
  perspective[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
  return perspective;
}


template<typename T> inline
Matrix4x4<T> PerspectiveLH(const T fov, const T aspect, const T zNear, const T zFar)
{
  T tanHalfFov = static_cast<T>(Tan(fov / static_cast<T>(2)));
  Matrix4x4<T> perspective = Matrix4x4<T>::Identity();
  perspective[3][3] = static_cast<T>(0);
  perspective[0][0] = static_cast<T>(1) / (aspect * tanHalfFov);
  perspective[1][1] = static_cast<T>(1) / (tanHalfFov);
  perspective[2][3] = static_cast<T>(1);

  perspective[2][2] = (zFar + zNear) / (zFar - zNear);
  perspective[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
  return perspective;
}
} // jkl