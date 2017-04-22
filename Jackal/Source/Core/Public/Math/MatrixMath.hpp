//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "Common.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"


namespace jkl {


// Translates the given matrix, to a new matrix value output.
// This is handy to move objects in space.
template<typename T> inline
Matrix4x4<T> Translate(const Matrix4x4<T> &original, const Vector3<T> &v);

// Rotates the given matrix using the given angle (in radians) along the given
// axis.
template<typename T> inline
Matrix4x4<T> Rotate(const Matrix4x4<T> &original, const T angle, const Vector3<T> &axis);

// Scale the matrix, to provide for the zooming in of objects in space.
// This is handy with zooming and whatnot.
template<typename T> inline
Matrix4x4<T> Scale(const Matrix4x4<T> &original, const Vector3<T> &scale);

// LookAt, Persepective and Orthographic need to be implemented as well!
template<typename T> inline
Matrix4x4<T> LookAtLH(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up);

//
template<typename T> inline
Matrix4x4<T> LookAtRH(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up);

// Default call of LookAt function, which will return the Left hand side 
// or right hand side matrix depending on the rendering api.
template<typename T> inline
Matrix4x4<T> LookAt(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up, bool left = false);

// Perspective projection matrix.
template<typename T> inline
Matrix4x4<T> Perspective(const T fov, const T aspect, const T zNear, const T zFar);

template<typename T> inline
Matrix4x4<T> PerspectiveLH(const T fov, const T aspect, const T zNear, const T zFar);

template<typename T> inline
Matrix4x4<T> PerspectiveRH(const T fov, const T aspect, const T zNear, const T zFar);

// Orthographic projection matrix. 
template<typename T> inline
Matrix4x4<T> Orthographic(const T fov, const T aspect, const T zNear, const T zFar);

template<typename T> inline
Matrix4x4<T> OrthographicLH(const T fov, const T aspect, const T zNear, const T zFar);

template<typename T> inline
Matrix4x4<T> OrthographicRH(const T fov, const T aspect, const T zNear, const T zFar);
} // jkl
#include "Internal/MatrixMath.inl"