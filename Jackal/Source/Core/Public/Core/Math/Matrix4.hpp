// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Matrix3.hpp"
#include "Vector4.hpp"
#include "Common.hpp"


namespace jkl {

// Matrix 4 by 4 square. Used for mainly things like transformation and whatnot.
// Structure is as follows: 
//      Column
//  Row | a00 a01 a02 a03 |
//      | a10 a11 a12 a13 |     m x n
//      | a20 a21 a22 a23 |
//      | a30 a31 a32 a33 |    
//
// The structure is accessed by matrix[row][column].
struct Matrix4 {
  // Get the Identity Matrix4x4 of this class. By default, this Matrix4x4 creates an
  // identity matrix, so this is simply for code clarification.
  static Matrix4 Identity() {
    return Matrix4();
  }

  // Constructor for a 4x4 matrix.
  Matrix4(
    real32 a00 = 1.0f, real32 a01 = 0.0f, real32 a02 = 0.0f, real32 a03 = 0.0f,
    real32 a10 = 0.0f, real32 a11 = 1.0f, real32 a12 = 0.0f, real32 a13 = 0.0f,
    real32 a20 = 0.0f, real32 a21 = 0.0f, real32 a22 = 1.0f, real32 a23 = 0.0f,
    real32 a30 = 0.0f, real32 a31 = 0.0f, real32 a32 = 0.0f, real32 a33 = 1.0f)
  {
    data[0][0] = a00; data[0][1] = a01; data[0][2] = a02; data[0][3] = a03;
    data[1][0] = a10; data[1][1] = a11; data[1][2] = a12; data[1][3] = a13;
    data[2][0] = a20; data[2][1] = a21; data[2][2] = a22; data[2][3] = a23;
    data[3][0] = a30; data[3][1] = a31; data[3][2] = a32; data[3][3] = a33;
  }

  // Another constructor for a 4x4 matrix, using 4 component vectors as rows.
  Matrix4(
    const Vector4 &r1,
    const Vector4 &r2,
    const Vector4 &r3,
    const Vector4 &r4
  )
  {
    data[0][0] = r1.x; data[0][1] = r1.y; data[0][2] = r1.z; data[0][3] = r1.w;
    data[1][0] = r2.x; data[1][1] = r2.y; data[1][2] = r2.z; data[1][3] = r2.w;
    data[2][0] = r3.x; data[2][1] = r3.y; data[2][2] = r3.z; data[2][3] = r3.w;
    data[3][0] = r4.x; data[3][1] = r4.y; data[3][2] = r4.z; data[3][3] = r4.w;
  }

  Matrix4(const Matrix3 &m)
  {
    data[0][0] = m.data[0][0];  data[0][1] = m.data[0][1];  data[0][2] = m.data[0][2];      data[0][3] = 0.0f;
    data[1][0] = m.data[1][0];  data[1][1] = m.data[1][1];  data[1][2] = m.data[1][2];  data[1][3] = 0.0f;
    data[2][0] = m.data[2][0];  data[2][1] = m.data[2][1];  data[2][2] = m.data[2][2];  data[2][3] = 0.0f;
    data[3][0] = 0.0f;          data[3][1] = 0.0f;          data[3][2] = 0.0f;          data[3][3] = 1.0f;
  }

  // Copy constructor to copy values of m matrix to this matrix.
  Matrix4(const Matrix4 &m)
  {
    data[0][0] = m.data[0][0]; data[0][1] = m.data[0][1]; data[0][2] = m.data[0][2]; data[0][3] = m.data[0][3];
    data[1][0] = m.data[1][0]; data[1][1] = m.data[1][1]; data[1][2] = m.data[1][2]; data[1][3] = m.data[1][3];
    data[2][0] = m.data[2][0]; data[2][1] = m.data[2][1]; data[2][2] = m.data[2][2]; data[2][3] = m.data[2][3];
    data[3][0] = m.data[3][0]; data[3][1] = m.data[3][1]; data[3][2] = m.data[3][2]; data[3][3] = m.data[3][3];
  }

  // Matrix Addition with matrix m. Returns a newly constructed matrix,
  // after adding this with m.
  Matrix4 operator+(const Matrix4 &m) const;

  // Matrix Subtraction with matrix m. Returns a newly constructed matrix,
  // after subtracting this with m.
  Matrix4 operator-(const Matrix4 &m) const;

  // typical matrix multiplication. M1 x M2. Returns a newly constructed
  // matrix after multiplying this with m.
  Matrix4 operator*(const Matrix4 &m) const;

  // Typical matrix multiplication. Instead of constructing a newly created
  // matrix, contents of this matrix are updated and modified.
  void operator*=(const Matrix4 &m);

  // Multiply all values in the matrix with the scaler value.
  Matrix4 operator*(const real32 scale) const;

  // Multiplay all values in the matrix with the scaler value. Does not
  // return a newly constructed matrix.
  void operator*=(const real32 scale);

  // Matrix addition with m matrix. This does not return a newly constructed
  // matrix.
  void operator+=(const Matrix4 &m);

  // Matrix subtraction with m matrix. This does not return a newly constructed
  // matrix.
  void operator-=(const Matrix4 &m);

  // Retrieve the raw data array of the matrix. This is mainly used for the rendering engine.
  real32 *Raw() { 
    return data[0]; 
  }

  // Quick access to a value in the matrix.
  real32 *operator[](const uint32 row) { 
    return data[row]; 
  }

  // Finds the determinant of this 4x4 matrix.
  // Not very high quality, and can be sped up with a little parallel processing, but none the less,
  // any attempted speedup will only increase performance by a fraction of an inch, so no need to speed 
  // up these math calls.
  real32 Determinant() const; 

  // Get the transpose of the matrix. This will create a new matrix.
  Matrix4 Transpose() const;

  // Obtain the inverse of this matrix.
  Matrix4 Inverse() const;

  // TODO(): Implement Adjoint!
  // Retrieves the adjugate matrix from this matrix. The adjugate is the transpose of this
  // matrix's cofactor matrix.
  Matrix4 Adjugate() const;

  Matrix3 Minor(uint32 row, uint32 col) const;

  // Checks if this matrix does not contain a finite number.
  // If a number is NaN, within this matrix, true will be returned. Otherwise, false will
  // return after traversing the entire matrix.
  bool ContainsNaN() const;

  // Check if matrix m is equal to this matrix, by values in their structures.
  // True if m matrix is the same as this matrix.
  bool operator==(const Matrix4 &m) const;

  // Opposite of operator==, checks if matrix m is not equal to this matrix.
  // Should define a tolerance, but for now, it's exact in some way. Float
  // values will likely have issues.
  bool operator!=(const Matrix4 &m) const { 
    return !(*this == m); 
  }

  // Data of the 4x4 matrix.
  real32 data[4][4];
};

typedef Matrix4 Mat4;
typedef Matrix4 Mat4f;
typedef Matrix4 Matrix4f;
} // jkl