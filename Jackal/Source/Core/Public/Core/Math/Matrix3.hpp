// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Matrix2.hpp"
#include "Vector4.hpp"
#include "Common.hpp"


namespace jackal {


// 3x3 matrix implementation.
struct Matrix3 {
  // Creates an identity matrix by default. In reality, this Matrix3x3 class
  // already constructs an identity matrix by default, if no parameters are
  // specified.
  static Matrix3 Identity() {
    return Matrix3();
  }
  
  Matrix3(
    real32 a00 = 1.0f, real32 a01 = 0.0f, real32 a02 = 0.0f,
    real32 a10 = 0.0f, real32 a11 = 1.0f, real32 a12 = 0.0f,
    real32 a20 = 0.0f, real32 a21 = 0.0f, real32 a22 = 1.0f)
  {
    data[0][0] = a00; data[0][1] = a01; data[0][2] = a02;
    data[1][0] = a10; data[1][1] = a11; data[1][2] = a12;
    data[2][0] = a20; data[2][1] = a21; data[2][2] = a22;
  }

  Matrix3(
    const Vector3 &r1,
    const Vector3 &r2,
    const Vector3 &r3)
  {
    data[0][0] = r1.x; data[0][1] = r1.y; data[0][2] = r1.z;
    data[1][0] = r2.x; data[1][1] = r2.y; data[1][2] = r2.z;
    data[2][0] = r3.x; data[2][1] = r3.y; data[2][2] = r3.z;
  }

  // Typical Matrix addition. Returns a newly constructed matrix after 
  // adding this matrix with m matrix.
  Matrix3 operator+(const Matrix3 &m) const;

  // Typical Matrix subtraction. Returns a newly constructed matrix after
  // subtracting this matrix with m matrix.
  Matrix3 operator-(const Matrix3 &m) const;

  // Matrix multiplication. Returns newly constructed matrix after 
  // multiplying this matrix with matrix m.
  Matrix3 operator*(const Matrix3 &m) const;

  // Matrix multiplation with scaler. It is commutative.
  Matrix3 operator*(const real32 scaler) const;

  // Matrix addition. Adds m matrix to this, without the need to 
  // create a new matrix.
  void operator+=(const Matrix3 &m);

  // Matrix subtraction. Subtracts m matrix from this, without the
  // need to create a new matrix. This matrix gets modified.
  void operator-=(const Matrix3 &m);

  void operator*=(const Matrix3 &m);

  void operator*=(const real32 scaler);

  // Checks if this matrix is equal (in terms of values) to matrix m.
  bool operator==(const Matrix3 &m) const;

  // Get the 2x2 minor matrix within any position in the matrix.
  Matrix2 Minor(uint32 row, uint32 col) const;

  // Get the inverse of this 3x3 matrix.
  Matrix3 Inverse() const;

  // Get the adjugate of this 3x3 matrix.
  Matrix3 Adjugate() const;

  // Get the determinant of this matrix 3x3.
  real32 Determinant() const;

  // Opposite of operator== in that it checks if this matrix is not equal
  // to matrix m.
  bool operator!=(const Matrix3 &m) {
    return !(*this == m);
  }

  real32 *Raw() {
    return data[0];
  }

  // Access the matrix without having to access data.
  real32 *operator[](const uint32 row) {
    return data[row];
  }

  // Data, information of the matrix.
  real32 data[3][3];
};


typedef Matrix3 Mat3;
typedef Matrix3 Mat3f;
typedef Matrix3 Matrix3f;
} // jackal