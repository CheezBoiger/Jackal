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
} // jkl