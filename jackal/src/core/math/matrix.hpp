//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "../platform/public/platform.hpp"
#include "../platform/public/jtypes.hpp"
#include "vector.hpp"


namespace jkl {


template<typename T> class Matrix3x3;
template<typename T> class Matrix2x2;

// Matrix 4 by 4 square. Used for mainly things like transformation and whatnot.
// Structure is as follows: 
//      Column
//  Row | a00 a01 a02 a03 |
//      | a10 a11 a12 a13 |     m x n
//      | a20 a21 a22 a23 |
//      | a30 a31 a32 a33 |    
//
// The structure is accessed by matrix[row][column].
template<typename T>
class Matrix4x4 {
public:
  Matrix4x4(
    T a00 = static_cast<T>(1), T a01 = static_cast<T>(0), T a02 = static_cast<T>(0), T a03 = static_cast<T>(0),
    T a10 = static_cast<T>(0), T a11 = static_cast<T>(1), T a12 = static_cast<T>(0), T a13 = static_cast<T>(0),
    T a20 = static_cast<T>(0), T a21 = static_cast<T>(0), T a22 = static_cast<T>(1), T a23 = static_cast<T>(0),
    T a30 = static_cast<T>(0), T a31 = static_cast<T>(0), T a32 = static_cast<T>(0), T a33 = static_cast<T>(1)
  ) {
    data[0][0] = a00; data[0][1] = a01; data[0][2] = a02; data[0][3] = a03;
    data[1][0] = a10; data[1][1] = a11; data[1][2] = a12; data[1][3] = a13;
    data[2][0] = a20; data[2][1] = a21; data[2][2] = a22; data[2][3] = a23;
    data[3][0] = a30; data[3][1] = a31; data[3][2] = a32; data[3][3] = a33; 
  }

  Matrix4x4(
    const Vector4<T> &r1,
    const Vector4<T> &r2,
    const Vector4<T> &r3,
    const Vector4<T> &r4
  ) {
    data[0][0] = r1.x; data[0][1] = r1.y; data[0][2] = r1.z; data[0][3] = r1.w;
    data[1][0] = r2.x; data[1][1] = r2.y; data[1][2] = r2.z; data[1][3] = r2.w;
    data[2][0] = r3.x; data[2][1] = r3.y; data[2][2] = r3.z; data[2][3] = r3.w;
    data[3][0] = r4.x; data[3][1] = r4.y; data[3][2] = r4.z; data[3][3] = r4.w;
  } 

  Matrix4x4(const Matrix3x3<T> &m) {
    data[0][0] = m[0][0];           data[0][1] = m[0][1];           data[0][2] = m[0][2];           data[0][3] = static_cast<T>(0);
    data[1][0] = m[1][0];           data[1][1] = m[1][1];           data[1][2] = m[1][2];           data[1][3] = static_cast<T>(0);
    data[2][0] = m[2][0];           data[2][1] = m[2][1];           data[2][2] = m[2][2];           data[2][3] = static_cast<T>(0);
    data[3][0] = static_cast<T>(0); data[3][1] = static_cast<T>(0); data[3][2] = static_cast<T>(0); data[3][3] = static_cast<T>(1);
  }

  Matrix4x4 operator+(const Matrix4x4 &m) {
    return Matrix4x4(
      data[0][0] + m.data[0][0], data[0][1] + m.data[0][1], data[0][2] + m.data[0][2], data[0][3] + m.data[0][3],
      data[1][0] + m.data[1][0], data[1][1] + m.data[1][1], data[1][2] + m.data[1][2], data[1][3] + m.data[1][3],
      data[2][0] + m.data[2][0], data[2][1] + m.data[2][1], data[2][2] + m.data[2][2], data[2][3] + m.data[2][3],
      data[3][0] + m.data[3][0], data[3][1] + m.data[3][1], data[3][2] + m.data[3][2], data[3][3] + m.data[3][3]
    );
  }

  Matrix4x4 operator-(const Matrix4x4 &m) {
    return Matrix4x4(
      data[0][0] - m.data[0][0], data[0][1] - m.data[0][1], data[0][2] - m.data[0][2], data[0][3] - m.data[0][3],
      data[1][0] - m.data[1][0], data[1][1] - m.data[1][1], data[1][2] - m.data[1][2], data[1][3] - m.data[1][3],
      data[2][0] - m.data[2][0], data[2][1] - m.data[2][1], data[2][2] - m.data[2][2], data[2][3] - m.data[2][3],
      data[3][0] - m.data[3][0], data[3][1] - m.data[3][1], data[3][2] - m.data[3][2], data[3][3] - m.data[3][3]
    );
  }

  // typical matrix multiplication. M1 x M2.
  Matrix4x4 operator*(const Matrix4x4 &m) {
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

  // Retrieve the raw data array of the matrix. This is mainly used for the rendering engine.
  T *Raw() {
    return data;
  }

  // Quick access to a value in the matrix.
  T *operator[](const uint32 row) {
    return data[row];
  }

  // Finds the determinant of this 4x4 matrix.
  // Not very high quality, and can be sped up with a little parallel processing, but none the less,
  // any attempted speedup will only increase performance by a fraction of an inch, so no need to speed 
  // up these math calls.
  T Determinant() {
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

private:
  // Data of the 4x4 matrix.
  T data[4][4];
};


template<typename T>
class Matrix3x3 {
};


template<typename T>
class Matrix2x2 {
};
} // jkl