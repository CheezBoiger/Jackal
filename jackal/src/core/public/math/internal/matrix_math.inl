//
// Copyright (c) Jackal Engine. MIT License.
//

#include "../matrix_math.hpp"

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
} // jkl