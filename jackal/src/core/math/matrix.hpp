//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "../platform/public/platform.hpp"
#include "../platform/public/jtypes.hpp"
#include "vector.hpp"
#include "common.hpp"


namespace jkl {

// TODO(): Keep working on this Math library.
template<typename T> struct Matrix3x3;
template<typename T> struct Matrix2x2;

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
struct Matrix4x4 {
  // Get the Identity Matrix4x4 of this class. By default, this Matrix4x4 creates an
  // identity matrix, so this is simply for code clarification.
  static Matrix4x4<T> Identity() {
    return Matrix4x4<T>();
  }

  // Constructor for a 4x4 matrix.
  Matrix4x4(
    T a00 = static_cast<T>(1), T a01 = static_cast<T>(0), T a02 = static_cast<T>(0), T a03 = static_cast<T>(0),
    T a10 = static_cast<T>(0), T a11 = static_cast<T>(1), T a12 = static_cast<T>(0), T a13 = static_cast<T>(0),
    T a20 = static_cast<T>(0), T a21 = static_cast<T>(0), T a22 = static_cast<T>(1), T a23 = static_cast<T>(0),
    T a30 = static_cast<T>(0), T a31 = static_cast<T>(0), T a32 = static_cast<T>(0), T a33 = static_cast<T>(1));

  // Another constructor for a 4x4 matrix, using 4 component vectors as rows.
  Matrix4x4(
    const Vector4<T> &r1,
    const Vector4<T> &r2,
    const Vector4<T> &r3,
    const Vector4<T> &r4
  );

  Matrix4x4(const Matrix3x3<T> &m);

  // Copy constructor to copy values of m matrix to this matrix.
  Matrix4x4(const Matrix4x4 &m);

  // Matrix Addition with matrix m. Returns a newly constructed matrix,
  // after adding this with m.
  Matrix4x4 operator+(const Matrix4x4 &m) const;

  // Matrix Subtraction with matrix m. Returns a newly constructed matrix,
  // after subtracting this with m.
  Matrix4x4 operator-(const Matrix4x4 &m) const;

  // typical matrix multiplication. M1 x M2. Returns a newly constructed
  // matrix after multiplying this with m.
  Matrix4x4 operator*(const Matrix4x4 &m) const;

  // Typical matrix multiplication. Instead of constructing a newly created
  // matrix, contents of this matrix are updated and modified.
  void operator*=(const Matrix4x4 &m);

  // Multiply all values in the matrix with the scaler value.
  Matrix4x4 operator*(const T scale) const;

  // Multiplay all values in the matrix with the scaler value. Does not
  // return a newly constructed matrix.
  void operator*=(const T scale);

  // Matrix addition with m matrix. This does not return a newly constructed
  // matrix.
  void operator+=(const Matrix4x4 &m);

  // Matrix subtraction with m matrix. This does not return a newly constructed
  // matrix.
  void operator-=(const Matrix4x4 &m);

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
  T Determinant() const; 


  // Get the transpose of the matrix. This will create a new matrix.
  Matrix4x4 Transpose() const;

  
  // Obtain the inverse of this matrix.
  // TODO(): Implement inverse!
  Matrix4x4 Inverse() const;

  // TODO(): Implement Adjoint!
  // Retrieves the adjoint matrix from this matrix. The adjoint is the transpose of this
  // matrix's cofactor matrix.
  Matrix4x4 Adjoint() const;

  // Checks if this matrix does not contain a finite number.
  // If a number is NaN, within this matrix, true will be returned. Otherwise, false will
  // return after traversing the entire matrix.
  bool ContainsNaN() const;

  // Check if matrix m is equal to this matrix, by values in their structures.
  // True if m matrix is the same as this matrix.
  bool operator==(const Matrix4x4 &m) const;

  // Opposite of operator==, checks if matrix m is not equal to this matrix.
  // Should define a tolerance, but for now, it's exact in some way. Float
  // values will likely have issues.
  bool operator!=(const Matrix4x4 &m) const { 
    return !(*this == m); 
  }

  // Data of the 4x4 matrix.
  T data[4][4];
};


// 3x3 matrix implementation.
template<typename T>
struct Matrix3x3 {
  // Creates an identity matrix by default. In reality, this Matrix3x3 class
  // already constructs an identity matrix by default, if no parameters are
  // specified.
  static Matrix3x3<T> Identity() {
    return Matrix3x3<T>();
  }
  
  Matrix3x3(
    T a00 = static_cast<T>(1), T a01 = static_cast<T>(0), T a02 = static_cast<T>(0),
    T a10 = static_cast<T>(0), T a11 = static_cast<T>(1), T a12 = static_cast<T>(0),
    T a20 = static_cast<T>(0), T a21 = static_cast<T>(0), T a22 = static_cast<T>(1));

  Matrix3x3(
    const Vector3<T> &r1,
    const Vector3<T> &r2,
    const Vector3<T> &r3);

  // Typical Matrix addition. Returns a newly constructed matrix after 
  // adding this matrix with m matrix.
  Matrix3x3 operator+(const Matrix3x3 &m) const;

  // Typical Matrix subtraction. Returns a newly constructed matrix after
  // subtracting this matrix with m matrix.
  Matrix3x3 operator-(const Matrix3x3 &m) const;

  // Matrix multiplication. Returns newly constructed matrix after 
  // multiplying this matrix with matrix m.
  Matrix3x3 operator*(const Matrix3x3 &m) const;

  // Checks if this matrix is equal (in terms of values) to matrix m.
  bool operator==(const Matrix3x3 &m) const;

  // Opposite of operator== in that it checks if this matrix is not equal
  // to matrix m.
  bool operator!=(const Matrix3x3 &m) {
    return !(*this == m);
  }

  // Access the matrix without having to access data.
  T *operator[](const uint32 row) {
    return data[row];
  }

  // Data, information of the matrix.
  T data[3][3];
};


// 2x2 Matrix. This handles relatively easy transformations, or conducting minors and whatnot.
template<typename T>
struct Matrix2x2 {
  Matrix2x2(
    T a00 = static_cast<T>(1), T a01 = static_cast<T>(0),
    T a10 = static_cast<T>(0), T a11 = static_cast<T>(1));

  Matrix2x2(
    const Vector2<T> &r1,
    const Vector2<T> &r2);

  // Typical Matrix addition. Returns a newly constructed matrix after 
  // adding this matrix with m matrix.
  Matrix2x2 operator+(const Matrix2x2 &m) const;

  // Typical Matrix subtraction. Returns a newly constructed matrix after
  // subtracting this matrix with m matrix.
  Matrix2x2 operator-(const Matrix2x2 &m) const;

  // Matrix multiplication. Returns newly constructed matrix after 
  // multiplying this matrix with matrix m.
  Matrix2x2 operator*(const Matrix2x2 &m) const;

  T *operator[](const uint32 row) {
    return data[row];
  }
    
  // Data of the matrix.
  T data[2][2];
};


typedef Matrix4x4<real32> Mat4;
typedef Matrix3x3<real32> Mat3;
typedef Matrix2x2<real32> Mat2;
} // jkl
#include "internal/matrix.inl"