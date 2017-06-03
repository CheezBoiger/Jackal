//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "Common.hpp"
#include "Matrix4.hpp"
#include "Vector4.hpp"


namespace jkl {


Matrix4 Inverse(const Matrix4 &original);

Matrix4 Transpose(const Matrix4 &original);

// Translates the given matrix, to a new matrix value output.
// This is handy to move objects in space.
Matrix4 Translate(const Matrix4 &original, const Vector3 &v);

// Rotates the given matrix using the given angle (in radians) along the given
// axis.
Matrix4 Rotate(const Matrix4 &original, const real32 angle, const Vector3 &axis);

// Rotates the given matrix using the given angle (in radians) along its
// x axis.
Matrix4 RotateX(const Matrix4 &original, const real32 angle);

// Rotates the given matrix using the given angle (in radians) along its
// y axis.
Matrix4 RotateY(const Matrix4 &original, const real32 angle);

// Rotates the given matrix using the given angle (in radians) along its
// z axis.
Matrix4 RotateZ(const Matrix4 &original, const real32 angle);

// Scale the matrix, to provide for the zooming in of objects in space.
// This is handy with zooming and whatnot.
Matrix4 Scale(const Matrix4 &original, const Vector3 &scale);

// LookAt, Persepective and Orthographic need to be implemented as well.
Matrix4 LookAtLH(const Vector3 &eye, const Vector3 &center, const Vector3 &up);

//
Matrix4 LookAtRH(const Vector3 &eye, const Vector3 &center, const Vector3 &up);

// Default call of LookAt function, which will return the Left hand side 
// or right hand side matrix depending on the rendering api.
Matrix4 LookAt(const Vector3 &eye, const Vector3 &center, const Vector3 &up, bool left = false);

// Perspective projection matrix.
Matrix4 Perspective(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar);

Matrix4 PerspectiveLH(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar);

Matrix4 PerspectiveRH(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar);

// Orthographic projection matrix. 
Matrix4 Orthographic(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar);

Matrix4 OrthographicLH(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar);

Matrix4 OrthographicRH(const real32 fov, const real32 aspect, const real32 zNear, const real32 zFar);
} // jkl