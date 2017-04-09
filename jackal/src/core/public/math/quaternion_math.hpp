//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once


#include "platform/jtypes.hpp"
#include "platform/platform.hpp"
#include "common.hpp"
#include "quaternion.hpp"
#include "vector.hpp"
#include "matrix.hpp"


namespace jkl {


// Convert a quaternion into a 4 component vector
// representation.
template<typename T> inline
Vector4<T> ToVector4(const Quaternion<T> &q);

// Convert a quaternion into a 4 by 4 matrix
// representation.
template<typename T> inline
Matrix4x4<T> ToMatrix4x4(const Quaternion<T> &q);


template<typename T> inline
Quaternion<T> ToQuaternion(const Vector3<T> &eulerAngle);

// Normalize the quaternion. Normally, we should
// be sticking to unit quaternions, so this call
// should be kept limited.
template<typename T> inline
Quaternion<T> Normalize(const Quaternion<T> &q);

// Spherical Linear Interpolation. Useful for 
// animations and whatnot.
template<typename T> inline
Quaternion<T> Slerp(const Quaternion<T> &q0, const Quaternion<T> &q1, T t);

// Produce a rotation about the hypersphere using x, y, z coordinates
// and an angle to tell about how much the quaternion will rotate.
// Quaternion q param descibes the initial position of the quaternion.
template<typename T> inline
Quaternion<T> AngleAxis(T angle, const Vector3<T> &axis);
} // jkl