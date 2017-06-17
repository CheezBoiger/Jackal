// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/Matrix3.hpp"


namespace jkl {


Matrix3 Matrix3::operator+(const Matrix3 &m) const
{
  return Matrix3(
    data[0][0] + m.data[0][0], data[0][1] + m.data[0][1], data[0][2] + m.data[0][2],
    data[1][0] + m.data[1][0], data[1][1] + m.data[1][1], data[1][2] + m.data[1][2],
    data[2][0] + m.data[2][0], data[2][1] + m.data[2][1], data[2][2] + m.data[2][2]
  );
}


Matrix3 Matrix3::operator-(const Matrix3 &m) const 
{
  return Matrix3(
    data[0][0] - m.data[0][0], data[0][1] - m.data[0][1], data[0][2] - m.data[0][2],
    data[1][0] - m.data[1][0], data[1][1] - m.data[1][1], data[1][2] - m.data[1][2],
    data[2][0] - m.data[2][0], data[2][1] - m.data[2][1], data[2][2] - m.data[2][2]
  );
}


Matrix3 Matrix3::operator*(const Matrix3 &m) const 
{
  return Matrix3(
    data[0][0] * m.data[0][0] + data[0][1] * m.data[1][0] + data[0][2] * m.data[2][0],
    data[0][0] * m.data[0][1] + data[0][1] * m.data[1][1] + data[0][2] * m.data[2][1],
    data[0][0] * m.data[0][2] + data[0][1] * m.data[1][2] + data[0][2] * m.data[2][2],

    data[1][0] * m.data[0][0] + data[1][1] * m.data[1][0] + data[1][2] * m.data[2][0],
    data[1][0] * m.data[0][1] + data[1][1] * m.data[1][1] + data[1][2] * m.data[2][1],
    data[1][0] * m.data[0][2] + data[1][1] * m.data[1][2] + data[1][2] * m.data[2][2],

    data[2][0] * m.data[0][0] + data[2][1] * m.data[1][0] + data[2][2] * m.data[2][0],
    data[2][0] * m.data[0][1] + data[2][1] * m.data[1][1] + data[2][2] * m.data[2][1],
    data[2][0] * m.data[0][2] + data[2][1] * m.data[1][2] + data[2][2] * m.data[2][2]
  );
}


bool Matrix3::operator==(const Matrix3 &m) const
{
  for (uint32 i = 0; i < 3; ++i) {
    for (uint32 j = 0; j < 3; ++j) {
      if (data[i][j] != m.data[i][j]) {
        return false;
      }
    }
  }
  return true;
}


real32 Matrix3::Determinant() const
{
  return  data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
          data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
          data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
}


Matrix3 Matrix3::operator*(const real32 scaler) const
{
  return Matrix3(
    data[0][0] * scaler, data[0][1] * scaler, data[0][2] * scaler,
    data[1][0] * scaler, data[1][1] * scaler, data[1][2] * scaler,
    data[2][0] * scaler, data[2][1] * scaler, data[2][2] * scaler
  );
}


void Matrix3::operator+=(const Matrix3 &other)
{
  data[0][0] += other.data[0][0]; data[0][1] += other.data[0][1]; data[0][2] += other.data[0][2];
  data[1][0] += other.data[1][0]; data[1][1] += other.data[1][1]; data[1][2] += other.data[1][2];
  data[2][0] += other.data[2][0]; data[2][1] += other.data[2][1]; data[2][2] += other.data[2][2];
}


void Matrix3::operator-=(const Matrix3 &other)
{
  data[0][0] -= other.data[0][0]; data[0][1] -= other.data[0][1]; data[0][2] -= other.data[0][2];
  data[1][0] -= other.data[1][0]; data[1][1] -= other.data[1][1]; data[1][2] -= other.data[1][2];
  data[2][0] -= other.data[2][0]; data[2][1] -= other.data[2][1]; data[2][2] -= other.data[2][2];
}


void Matrix3::operator*=(const Matrix3 &other)
{
  // TODO(): Still need to do. 
}


void Matrix3::operator*=(const real32 scaler)
{
  data[0][0] *= scaler; data[0][1] *= scaler; data[0][2] *= scaler;
  data[1][0] *= scaler; data[1][1] *= scaler; data[1][2] *= scaler;
  data[2][0] *= scaler; data[2][1] *= scaler; data[2][2] *= scaler;
}


Matrix3 Matrix3::Inverse() const
{
  Matrix3 invert;

  return invert;
}


Matrix3 Matrix3::Adjugate() const
{
  Matrix3 adj;

  return adj;
}


Matrix2 Matrix3::Minor(uint32 row, uint32 col) const
{
  Matrix2 minor;
  
  return minor;
}
} // jkl