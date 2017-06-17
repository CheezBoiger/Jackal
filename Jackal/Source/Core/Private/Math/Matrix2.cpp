// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/Matrix2.hpp"

namespace jkl {


Matrix2 Matrix2::operator+(const Matrix2 &m) const 
{
  return Matrix2(
    data[0][0] + m.data[0][0], data[0][1] + m.data[0][1],
    data[1][0] + m.data[1][0], data[1][1] + m.data[1][1]
  );
}


Matrix2 Matrix2::operator-(const Matrix2 &m) const 
{
  return Matrix2(
    data[0][0] - m.data[0][0], data[0][1] - m.data[0][1],
    data[1][0] - m.data[1][0], data[1][1] - m.data[1][1]
  );
}


Matrix2 Matrix2::operator*(const Matrix2 &m) const 
{
  // This could be 
  return Matrix2(
    data[0][0] * m.data[0][0] + data[0][1] * m.data[1][0], data[0][0] * m.data[0][1] + data[0][1] * m.data[1][1],
    data[1][0] * m.data[0][0] + data[1][1] * m.data[1][0], data[1][0] * m.data[0][1] + data[1][1] * m.data[1][1]
  );
}


Matrix2 Matrix2::operator+(const real32 scaler) const
{
  return Matrix2(
    data[0][0] + scaler, data[0][1] + scaler,
    data[1][0] + scaler, data[1][1] + scaler
  );
}


Matrix2 Matrix2::operator-(const real32 scaler) const
{
  return Matrix2(
    data[0][0] - scaler, data[0][1] - scaler,
    data[1][0] - scaler, data[1][1] - scaler
  );
}


void Matrix2::operator+=(const Matrix2 &other)
{
  data[0][0] += other.data[0][0]; data[0][1] += other.data[0][1];
  data[1][0] += other.data[1][0]; data[1][1] += other.data[1][1];
}


void Matrix2::operator+=(const real32 scaler)
{
  data[0][0] += scaler; data[0][1] += scaler;
  data[1][0] += scaler; data[1][1] += scaler;
}


void Matrix2::operator-=(const Matrix2 &other)
{
  data[0][0] -= other.data[0][0]; data[0][1] -= other.data[0][1];
  data[1][0] -= other.data[1][0]; data[1][1] -= other.data[1][1];
}


void Matrix2::operator-=(const real32 scaler)
{
  data[0][0] -= scaler; data[0][1] -= scaler;
  data[1][0] -= scaler; data[1][1] -= scaler;
}
} // jkl