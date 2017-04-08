//
// Copyright (c) Jackal Engine. MIT License.
// 
//#include "../matrix.hpp"


namespace jkl {


template<typename T>
Matrix4x4<T>::Matrix4x4(
    T a00, T a01, T a02, T a03,
    T a10, T a11, T a12, T a13,
    T a20, T a21, T a22, T a23,
    T a30, T a31, T a32, T a33)
{
  data[0][0] = a00; data[0][1] = a01; data[0][2] = a02; data[0][3] = a03;
  data[1][0] = a10; data[1][1] = a11; data[1][2] = a12; data[1][3] = a13;
  data[2][0] = a20; data[2][1] = a21; data[2][2] = a22; data[2][3] = a23;
  data[3][0] = a30; data[3][1] = a31; data[3][2] = a32; data[3][3] = a33;
}


template<typename T>
Matrix4x4<T>::Matrix4x4(
  const Vector4<T> &r1,
  const Vector4<T> &r2,
  const Vector4<T> &r3,
  const Vector4<T> &r4) 
{
  data[0][0] = r1.x; data[0][1] = r1.y; data[0][2] = r1.z; data[0][3] = r1.w;
  data[1][0] = r2.x; data[1][1] = r2.y; data[1][2] = r2.z; data[1][3] = r2.w;
  data[2][0] = r3.x; data[2][1] = r3.y; data[2][2] = r3.z; data[2][3] = r3.w;
  data[3][0] = r4.x; data[3][1] = r4.y; data[3][2] = r4.z; data[3][3] = r4.w;
}


template<typename T>
Matrix4x4<T>::Matrix4x4(const Matrix3x3<T> &m) 
{
  data[0][0] = m.data[0][0];      data[0][1] = m.data[0][1];      data[0][2] = m.data[0][2];      data[0][3] = static_cast<T>(0);
  data[1][0] = m.data[1][0];      data[1][1] = m.data[1][1];      data[1][2] = m.data[1][2];      data[1][3] = static_cast<T>(0);
  data[2][0] = m.data[2][0];      data[2][1] = m.data[2][1];      data[2][2] = m.data[2][2];      data[2][3] = static_cast<T>(0);
  data[3][0] = static_cast<T>(0); data[3][1] = static_cast<T>(0); data[3][2] = static_cast<T>(0); data[3][3] = static_cast<T>(1);
}


template<typename T>
Matrix4x4<T>::Matrix4x4(const Matrix4x4 &m) 
{
  data[0][0] = m.data[0][0]; data[0][1] = m.data[0][1]; data[0][2] = m.data[0][2]; data[0][3] = m.data[0][3];
  data[1][0] = m.data[1][0]; data[1][1] = m.data[1][1]; data[1][2] = m.data[1][2]; data[1][3] = m.data[1][3];
  data[2][0] = m.data[2][0]; data[2][1] = m.data[2][1]; data[2][2] = m.data[2][2]; data[2][3] = m.data[2][3];
  data[3][0] = m.data[3][0]; data[3][1] = m.data[3][1]; data[3][2] = m.data[3][2]; data[3][3] = m.data[3][3];
}


template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator+(const Matrix4x4 &m) const 
{
  return Matrix4x4(
    data[0][0] + m.data[0][0], data[0][1] + m.data[0][1], data[0][2] + m.data[0][2], data[0][3] + m.data[0][3],
    data[1][0] + m.data[1][0], data[1][1] + m.data[1][1], data[1][2] + m.data[1][2], data[1][3] + m.data[1][3],
    data[2][0] + m.data[2][0], data[2][1] + m.data[2][1], data[2][2] + m.data[2][2], data[2][3] + m.data[2][3],
    data[3][0] + m.data[3][0], data[3][1] + m.data[3][1], data[3][2] + m.data[3][2], data[3][3] + m.data[3][3]
  );
}


template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator-(const Matrix4x4 &m) const 
{
  return Matrix4x4(
    data[0][0] - m.data[0][0], data[0][1] - m.data[0][1], data[0][2] - m.data[0][2], data[0][3] - m.data[0][3],
    data[1][0] - m.data[1][0], data[1][1] - m.data[1][1], data[1][2] - m.data[1][2], data[1][3] - m.data[1][3],
    data[2][0] - m.data[2][0], data[2][1] - m.data[2][1], data[2][2] - m.data[2][2], data[2][3] - m.data[2][3],
    data[3][0] - m.data[3][0], data[3][1] - m.data[3][1], data[3][2] - m.data[3][2], data[3][3] - m.data[3][3]
  );
}


template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4 &m) const
 {
  return Matrix4x4(
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


template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator*(const T scale) const 
{
  return Matrix4x4(
    data[0][0] * scale, data[0][1] * scale, data[0][2] * scale, data[0][3] * scale,
    data[1][0] * scale, data[1][1] * scale, data[1][2] * scale, data[1][3] * scale,
    data[2][0] * scale, data[2][1] * scale, data[2][2] * scale, data[2][3] * scale,
    data[3][0] * scale, data[3][1] * scale, data[3][2] * scale, data[3][3] * scale
  );
}


template<typename T>
void Matrix4x4<T>::operator*=(const T scale) 
{
  data[0][0] *= scale; data[0][1] *= scale; data[0][2] *= scale; data[0][3] *= scale;
  data[1][0] *= scale; data[1][1] *= scale; data[1][2] *= scale; data[1][3] *= scale;
  data[2][0] *= scale; data[2][1] *= scale; data[2][2] *= scale; data[2][3] *= scale;
  data[3][0] *= scale; data[3][1] *= scale; data[3][2] *= scale; data[3][3] *= scale;
}


template<typename T>
void Matrix4x4<T>::operator+=(const Matrix4x4 &m) 
{
  data[0][0] += m.data[0][0]; data[0][1] += m.data[0][1]; data[0][2] += m.data[0][2]; data[0][3] += m.data[0][3];
  data[1][0] += m.data[1][0]; data[1][1] += m.data[1][1]; data[1][2] += m.data[1][2]; data[1][3] += m.data[1][3];
  data[2][0] += m.data[2][0]; data[2][1] += m.data[2][1]; data[2][2] += m.data[2][2]; data[2][3] += m.data[2][3];
  data[3][0] += m.data[3][0]; data[3][1] += m.data[3][1]; data[3][2] += m.data[3][2]; data[3][3] += m.data[3][3];
}


template<typename T>
void Matrix4x4<T>::operator-=(const Matrix4x4 &m) 
{
  data[0][0] -= m.data[0][0]; data[0][1] -= m.data[0][1]; data[0][2] -= m.data[0][2]; data[0][3] -= m.data[0][3];
  data[1][0] -= m.data[1][0]; data[1][1] -= m.data[1][1]; data[1][2] -= m.data[1][2]; data[1][3] -= m.data[1][3];
  data[2][0] -= m.data[2][0]; data[2][1] -= m.data[2][1]; data[2][2] -= m.data[2][2]; data[2][3] -= m.data[2][3];
  data[3][0] -= m.data[3][0]; data[3][1] -= m.data[3][1]; data[3][2] -= m.data[3][2]; data[3][3] -= m.data[3][3];
}


template<typename T>
void Matrix4x4<T>::operator*=(const Matrix4x4 &m) 
{
  Matrix4x4 ori = *this;
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


template<typename T>
T Matrix4x4<T>::Determinant() const 
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


template<typename T>
Matrix4x4<T> Matrix4x4<T>::Transpose() const 
{
  return Matrix4x4(
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
template<typename T>
Matrix4x4<T> Matrix4x4<T>::Inverse() const 
{
  T detA = Determinant();
  if (detA == static_cast<T>(0)) {
    return Matrix4x4<T>::Identity();
  }
  Matrix4x4<T> inverse = Adjugate() * (static_cast<T>(1) / detA);
  return inverse;
}


template<typename T>
Matrix4x4<T> Matrix4x4<T>::Adjugate() const 
{
  // Calculating our adjugate using the transpose of the cofactor of our
  // matrix.
  Matrix4x4<T> CofactorMatrix;
  T sign = static_cast<T>(1);
  for (uint32 row = 0; row < 4; ++row) {
    sign = -sign;
    for (uint32 col = 0; col < 4; ++col) {
      sign = -sign;
      CofactorMatrix[row][col] = Minor(row, col).Determinant() * sign;    }
  }
  // Transpose this CofactorMatrix to get the adjugate.
  return CofactorMatrix.Transpose();
}


template<typename T>
Matrix3x3<T> Matrix4x4<T>::Minor(uint32 row, uint32 col) const
{
  Matrix3x3<T> minor;
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


template<typename T>
bool Matrix4x4<T>::ContainsNaN() const 
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


template<typename T>
bool Matrix4x4<T>::operator==(const Matrix4x4 &m) const 
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


template<typename T>
Matrix3x3<T>::Matrix3x3(
  T a00, T a01, T a02,
  T a10, T a11, T a12,
  T a20, T a21, T a22) 
{
  data[0][0] = a00; data[0][1] = a01; data[0][2] = a02;
  data[1][0] = a10; data[1][1] = a11; data[1][2] = a12;
  data[2][0] = a20; data[2][1] = a21; data[2][2] = a22;
}


template<typename T>
Matrix3x3<T>::Matrix3x3(
  const Vector3<T> &r1,
  const Vector3<T> &r2,
  const Vector3<T> &r3) 
{
  data[0][0] = r1.x; data[0][1] = r1.y; data[0][2] = r1.z;
  data[1][0] = r2.x; data[1][1] = r2.y; data[1][2] = r2.z;
  data[2][0] = r3.x; data[2][1] = r3.y; data[2][2] = r3.z;
}


template<typename T>
Matrix3x3<T> Matrix3x3<T>::operator+(const Matrix3x3 &m) const
{
  return Matrix3x3(
    data[0][0] + m.data[0][0], data[0][1] + m.data[0][1], data[0][2] + m.data[0][2],
    data[1][0] + m.data[1][0], data[1][1] + m.data[1][1], data[1][2] + m.data[1][2],
    data[2][0] + m.data[2][0], data[2][1] + m.data[2][1], data[2][2] + m.data[2][2]
  );
}


template<typename T>
Matrix3x3<T> Matrix3x3<T>::operator-(const Matrix3x3 &m) const 
{
  return Matrix3x3(
    data[0][0] - m.data[0][0], data[0][1] - m.data[0][1], data[0][2] - m.data[0][2],
    data[1][0] - m.data[1][0], data[1][1] - m.data[1][1], data[1][2] - m.data[1][2],
    data[2][0] - m.data[2][0], data[2][1] - m.data[2][1], data[2][2] - m.data[2][2]
  );
}


template<typename T>
Matrix3x3<T> Matrix3x3<T>::operator*(const Matrix3x3 &m) const 
{
  return Matrix3x3(
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


template<typename T>
bool Matrix3x3<T>::operator==(const Matrix3x3 &m) const
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


template<typename T>
T Matrix3x3<T>::Determinant() const
{
  return  data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
          data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
          data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
}


template<typename T>
Matrix2x2<T>::Matrix2x2(
  T a00, T a01,
  T a10, T a11) 
{
  data[0][0] = a00; data[0][1] = a01;
  data[1][0] = a10; data[1][1] = a11;
}


template<typename T>
Matrix2x2<T>::Matrix2x2(
  const Vector2<T> &r1,
  const Vector2<T> &r2) 
{
  data[0][0] = r1.x; data[0][1] = r1.y;
  data[1][0] = r2.x; data[1][1] = r2.y;
}


template<typename T>
Matrix2x2<T> Matrix2x2<T>::operator+(const Matrix2x2 &m) const 
{
  return Matrix2x2(
    data[0][0] + m.data[0][0], data[0][1] + m.data[0][1],
    data[1][0] + m.data[1][0], data[1][1] + m.data[1][1]
  );
}


template<typename T>
Matrix2x2<T> Matrix2x2<T>::operator-(const Matrix2x2 &m) const 
{
  return Matrix2x2(
    data[0][0] - m.data[0][0], data[0][1] - m.data[0][1],
    data[1][0] - m.data[1][0], data[1][1] - m.data[1][1]
  );
}


template<typename T>
Matrix2x2<T> Matrix2x2<T>::operator*(const Matrix2x2 &m) const 
{
  // This could be 
  return Matrix2x2(
    data[0][0] * m.data[0][0] + data[0][1] * m.data[1][0], data[0][0] * m.data[0][1] + data[0][1] * m.data[1][1],
    data[1][0] * m.data[0][0] + data[1][1] * m.data[1][0], data[1][0] * m.data[0][1] + data[1][1] * m.data[1][1]
  );
}
} // jkl