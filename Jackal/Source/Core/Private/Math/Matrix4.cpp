// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Math/Matrix4.hpp"


namespace jkl {


Matrix4 Matrix4::operator+(const Matrix4 &m) const 
{
  return Matrix4(
    data[0][0] + m.data[0][0], data[0][1] + m.data[0][1], data[0][2] + m.data[0][2], data[0][3] + m.data[0][3],
    data[1][0] + m.data[1][0], data[1][1] + m.data[1][1], data[1][2] + m.data[1][2], data[1][3] + m.data[1][3],
    data[2][0] + m.data[2][0], data[2][1] + m.data[2][1], data[2][2] + m.data[2][2], data[2][3] + m.data[2][3],
    data[3][0] + m.data[3][0], data[3][1] + m.data[3][1], data[3][2] + m.data[3][2], data[3][3] + m.data[3][3]
  ); 
}


Matrix4 Matrix4::operator-(const Matrix4 &m) const 
{
  return Matrix4(
    data[0][0] - m.data[0][0], data[0][1] - m.data[0][1], data[0][2] - m.data[0][2], data[0][3] - m.data[0][3],
    data[1][0] - m.data[1][0], data[1][1] - m.data[1][1], data[1][2] - m.data[1][2], data[1][3] - m.data[1][3],
    data[2][0] - m.data[2][0], data[2][1] - m.data[2][1], data[2][2] - m.data[2][2], data[2][3] - m.data[2][3],
    data[3][0] - m.data[3][0], data[3][1] - m.data[3][1], data[3][2] - m.data[3][2], data[3][3] - m.data[3][3]
  );
}


Matrix4 Matrix4::operator*(const Matrix4 &m) const
 {
  return Matrix4(
    data[0][0] * m.data[0][0] + data[0][1] * m.data[1][0] + data[0][2] * m.data[2][0] + data[0][3] * m.data[3][0],
    data[0][0] * m.data[0][1] + data[0][1] * m.data[1][1] + data[0][2] * m.data[2][1] + data[0][3] * m.data[3][1],
    data[0][0] * m.data[0][2] + data[0][1] * m.data[1][2] + data[0][2] * m.data[2][2] + data[0][3] * m.data[3][2],
    data[0][0] * m.data[0][3] + data[0][1] * m.data[1][3] + data[0][2] * m.data[2][3] + data[0][3] * m.data[3][3],

    data[1][0] * m.data[0][0] + data[1][1] * m.data[1][0] + data[1][2] * m.data[2][0] + data[1][3] * m.data[3][0],
    data[1][0] * m.data[0][1] + data[1][1] * m.data[1][1] + data[1][2] * m.data[2][1] + data[1][3] * m.data[3][1],
    data[1][0] * m.data[0][2] + data[1][1] * m.data[1][2] + data[1][2] * m.data[2][2] + data[1][3] * m.data[3][2],
    data[1][0] * m.data[0][3] + data[1][1] * m.data[1][3] + data[1][2] * m.data[2][3] + data[1][3] * m.data[3][3],

    data[2][0] * m.data[0][0] + data[2][1] * m.data[1][0] + data[2][2] * m.data[2][0] + data[2][3] * m.data[3][0],
    data[2][0] * m.data[0][1] + data[2][1] * m.data[1][1] + data[2][2] * m.data[2][1] + data[2][3] * m.data[3][1],
    data[2][0] * m.data[0][2] + data[2][1] * m.data[1][2] + data[2][2] * m.data[2][2] + data[2][3] * m.data[3][2],
    data[2][0] * m.data[0][3] + data[2][1] * m.data[1][3] + data[2][2] * m.data[2][3] + data[2][3] * m.data[3][3],

    data[3][0] * m.data[0][0] + data[3][1] * m.data[1][0] + data[3][2] * m.data[2][0] + data[3][3] * m.data[3][0],
    data[3][0] * m.data[0][1] + data[3][1] * m.data[1][1] + data[3][2] * m.data[2][1] + data[3][3] * m.data[3][1],
    data[3][0] * m.data[0][2] + data[3][1] * m.data[1][2] + data[3][2] * m.data[2][2] + data[3][3] * m.data[3][2],
    data[3][0] * m.data[0][3] + data[3][1] * m.data[1][3] + data[3][2] * m.data[2][3] + data[3][3] * m.data[3][3]
  );
}


Matrix4 Matrix4::operator*(const real32 scale) const 
{
  return Matrix4(
    data[0][0] * scale, data[0][1] * scale, data[0][2] * scale, data[0][3] * scale,
    data[1][0] * scale, data[1][1] * scale, data[1][2] * scale, data[1][3] * scale,
    data[2][0] * scale, data[2][1] * scale, data[2][2] * scale, data[2][3] * scale,
    data[3][0] * scale, data[3][1] * scale, data[3][2] * scale, data[3][3] * scale
  );
}


void Matrix4::operator*=(const real32 scale) 
{
  data[0][0] *= scale; data[0][1] *= scale; data[0][2] *= scale; data[0][3] *= scale;
  data[1][0] *= scale; data[1][1] *= scale; data[1][2] *= scale; data[1][3] *= scale;
  data[2][0] *= scale; data[2][1] *= scale; data[2][2] *= scale; data[2][3] *= scale;
  data[3][0] *= scale; data[3][1] *= scale; data[3][2] *= scale; data[3][3] *= scale;
}


void Matrix4::operator+=(const Matrix4 &m) 
{
  data[0][0] += m.data[0][0]; data[0][1] += m.data[0][1]; data[0][2] += m.data[0][2]; data[0][3] += m.data[0][3];
  data[1][0] += m.data[1][0]; data[1][1] += m.data[1][1]; data[1][2] += m.data[1][2]; data[1][3] += m.data[1][3];
  data[2][0] += m.data[2][0]; data[2][1] += m.data[2][1]; data[2][2] += m.data[2][2]; data[2][3] += m.data[2][3];
  data[3][0] += m.data[3][0]; data[3][1] += m.data[3][1]; data[3][2] += m.data[3][2]; data[3][3] += m.data[3][3];
}


void Matrix4::operator-=(const Matrix4 &m) 
{
  data[0][0] -= m.data[0][0]; data[0][1] -= m.data[0][1]; data[0][2] -= m.data[0][2]; data[0][3] -= m.data[0][3];
  data[1][0] -= m.data[1][0]; data[1][1] -= m.data[1][1]; data[1][2] -= m.data[1][2]; data[1][3] -= m.data[1][3];
  data[2][0] -= m.data[2][0]; data[2][1] -= m.data[2][1]; data[2][2] -= m.data[2][2]; data[2][3] -= m.data[2][3];
  data[3][0] -= m.data[3][0]; data[3][1] -= m.data[3][1]; data[3][2] -= m.data[3][2]; data[3][3] -= m.data[3][3];
}


void Matrix4::operator*=(const Matrix4 &m) 
{
  Matrix4 ori = *this;
  data[0][0] = ori[0][0] * m.data[0][0] + ori[0][1] * m.data[1][0] + ori[0][2] * m.data[2][0] + ori[0][3] * m.data[3][0];
  data[0][1] = ori[0][0] * m.data[0][1] + ori[0][1] * m.data[1][1] + ori[0][2] * m.data[2][1] + ori[0][3] * m.data[3][1];
  data[0][2] = ori[0][0] * m.data[0][2] + ori[0][1] * m.data[1][2] + ori[0][2] * m.data[2][2] + ori[0][3] * m.data[3][2];
  data[0][3] = ori[0][0] * m.data[0][3] + ori[0][1] * m.data[1][3] + ori[0][2] * m.data[2][3] + ori[0][3] * m.data[3][3];

  data[1][0] = ori[1][0] * m.data[0][0] + ori[1][1] * m.data[1][0] + ori[1][2] * m.data[2][0] + ori[1][3] * m.data[3][0];
  data[1][1] = ori[1][0] * m.data[0][1] + ori[1][1] * m.data[1][1] + ori[1][2] * m.data[2][1] + ori[1][3] * m.data[3][1];
  data[1][2] = ori[1][0] * m.data[0][2] + ori[1][1] * m.data[1][2] + ori[1][2] * m.data[2][2] + ori[1][3] * m.data[3][2];
  data[1][3] = ori[1][0] * m.data[0][3] + ori[1][1] * m.data[1][3] + ori[1][2] * m.data[2][3] + ori[1][3] * m.data[3][3];

  data[2][0] = ori[2][0] * m.data[0][0] + ori[2][1] * m.data[1][0] + ori[2][2] * m.data[2][0] + ori[2][3] * m.data[3][0];
  data[2][1] = ori[2][0] * m.data[0][1] + ori[2][1] * m.data[1][1] + ori[2][2] * m.data[2][1] + ori[2][3] * m.data[3][1];
  data[2][2] = ori[2][0] * m.data[0][2] + ori[2][1] * m.data[1][2] + ori[2][2] * m.data[2][2] + ori[2][3] * m.data[3][2];
  data[2][3] = ori[2][0] * m.data[0][3] + ori[2][1] * m.data[1][3] + ori[2][2] * m.data[2][3] + ori[2][3] * m.data[3][3];

  data[3][0] = ori[3][0] * m.data[0][0] + ori[3][1] * m.data[1][0] + ori[3][2] * m.data[2][0] + ori[3][3] * m.data[3][0];
  data[3][1] = ori[3][0] * m.data[0][1] + ori[3][1] * m.data[1][1] + ori[3][2] * m.data[2][1] + ori[3][3] * m.data[3][1];
  data[3][2] = ori[3][0] * m.data[0][2] + ori[3][1] * m.data[1][2] + ori[3][2] * m.data[2][2] + ori[3][3] * m.data[3][2];
  data[3][3] = ori[3][0] * m.data[0][3] + ori[3][1] * m.data[1][3] + ori[3][2] * m.data[2][3] + ori[3][3] * m.data[3][3];
}


real32 Matrix4::Determinant() const 
{
  return  data[0][0] * (  data[1][1] * (data[2][2] * data[3][3] - data[2][3] * data[3][2]) -
                          data[1][2] * (data[2][1] * data[3][3] - data[2][3] * data[3][1]) +
                          data[1][3] * (data[2][1] * data[3][2] - data[2][2] * data[3][1])  
                      ) - 
          data[0][1] * (  data[1][0] * (data[2][2] * data[3][3] - data[2][3] * data[3][2]) -
                          data[1][2] * (data[2][0] * data[3][3] - data[2][3] * data[3][0]) +
                          data[1][3] * (data[2][0] * data[3][2] - data[2][2] * data[3][0])  
                      ) +
          data[0][2] * (  data[1][0] * (data[2][1] * data[3][3] - data[2][3] * data[3][1]) -
                          data[1][1] * (data[2][0] * data[3][3] - data[2][3] * data[3][0]) +
                          data[1][3] * (data[2][0] * data[3][1] - data[2][1] * data[3][0])  
                      ) - 
          data[0][3] * (  data[1][0] * (data[2][1] * data[3][2] - data[2][2] * data[3][1]) -
                          data[1][1] * (data[2][0] * data[3][2] - data[2][2] * data[3][0]) +
                          data[1][2] * (data[2][0] * data[3][1] - data[2][1] * data[3][0])  );
} 


Matrix4 Matrix4::Transpose() const 
{
  return Matrix4(
    data[0][0], data[1][0], data[2][0], data[3][0],
    data[0][1], data[1][1], data[2][1], data[3][1],
    data[0][2], data[1][2], data[2][2], data[3][2],
    data[0][3], data[1][3], data[2][3], data[3][3]
  );
}


// We calculate the inverse of a 4x4 matrix using the standard method
// of finding the adjugate and multiplying it with one over
// the determinant. The formula: 
//
// inv(A) = (1/detA) * adj(A)
Matrix4 Matrix4::Inverse() const 
{
  real32 detA = Determinant();
  if (detA == 0.0f) {
    return Matrix4::Identity();
  }
  Matrix4 inverse = Adjugate() * (1.0f / detA);
  return inverse;
}


Matrix4 Matrix4::Adjugate() const 
{
  // Calculating our adjugate using the transpose of the cofactor of our
  // matrix.
  Matrix4 CofactorMatrix;
  real32 sign = 1.0f;
  for (uint32 row = 0; row < 4; ++row) {
    sign = -sign;
    for (uint32 col = 0; col < 4; ++col) {
      sign = -sign;
      CofactorMatrix[row][col] = Minor(row, col).Determinant() * sign;
    }
  }
  // Transpose this CofactorMatrix to get the adjugate.
  return CofactorMatrix.Transpose();
}


Matrix3 Matrix4::Minor(uint32 row, uint32 col) const
{
  Matrix3 minor;
  uint32 r = 0, c;
  for (uint32 i = 0; i < 4; ++i) {
    if (i == row) continue;
    c = 0;
    for (uint32 j = 0; j < 4; ++j) {
      if (j == col) continue;
      minor[r][c] = data[i][j];
      c++;
    }
    r++;
  }
  return minor;
}


bool Matrix4::ContainsNaN() const 
{
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      if (IsNaN(data[i][j])) {
        return true;
      }
    }
  }
  return false;
}


bool Matrix4::operator==(const Matrix4 &m) const 
{
  for (uint32 i = 0; i < 4; ++i) {
    for (uint32 j = 0; j < 4; ++j) {
      if (data[i][j] != m.data[i][j]) {
        return false;
      }
    }
  }
  return true;
}
} // jkl