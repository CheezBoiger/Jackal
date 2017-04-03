//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "common.hpp"
#include "matrix.hpp"
#include "vector.hpp"


namespace jkl {


// Translates the given matrix, to a new matrix value output.
// This is handy to move objects in space.
template<typename T>
Matrix4x4<T> Translate(const Matrix4x4<T> &original, const Vector3<T> &v);

// Rotates the given matrix using the given angle (in radians) along the given
// axis.
template<typename T>
Matrix4x4<T> Rotate(const Matrix4x4<T> &original, T angle, const Vector3<T> &axis);

// Scale the matrix, to provide for the zooming in of objects in space.
// This is handy with zooming and whatnot.
template<typename T>
Matrix4x4<T> Scale(const Matrix4x4<T> &original, const Vector3<T> &scale);


// LookAt, Persepective and Orthographic need to be implemented as well!
} // jkl