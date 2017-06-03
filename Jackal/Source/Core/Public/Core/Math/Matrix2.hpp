// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Vector4.hpp"
#include "Common.hpp"


namespace jkl {


// 2x2 Matrix. This handles relatively easy transformations, or conducting minors and whatnot.
struct Matrix2 {
  Matrix2(
    real32 a00 = 1.0f, real32 a01 = 0.0f,
    real32 a10 = 0.0f, real32 a11 = 1.0f)
  {
    data[0][0] = a00; data[0][1] = a01;
    data[1][0] = a10; data[1][1] = a11;
  }

  Matrix2(
    const Vector2 &r1,
    const Vector2 &r2)
  {
    data[0][0] = r1.x; data[0][1] = r1.y;
    data[1][0] = r2.x; data[1][1] = r2.y;
  }

  // Typical Matrix addition. Returns a newly constructed matrix after 
  // adding this matrix with m matrix.
  Matrix2 operator+(const Matrix2 &m) const;

  // Typical Matrix subtraction. Returns a newly constructed matrix after
  // subtracting this matrix with m matrix.
  Matrix2 operator-(const Matrix2 &m) const;

  // Matrix multiplication. Returns newly constructed matrix after 
  // multiplying this matrix with matrix m.
  Matrix2 operator*(const Matrix2 &m) const;

  // Get the determinant of this 2x2 matrix.
  real32 Determinant() const;

  // Get the adjugate of this 2x2 matrix.
  Matrix2 Adjugate() const;
  
  // Get the inverse of this matrix.
  Matrix2 Inverse() const;

  real32 *operator[](const uint32 row) {
    return data[row];
  }

  real32 *Raw() {
    return data[0];
  }
    
  // Data of the matrix.
  real32 data[2][2];
};


typedef Matrix2 Mat2;
typedef Matrix2 Mat2f;
typedef Matrix2 Matrix2f;
} // jkl