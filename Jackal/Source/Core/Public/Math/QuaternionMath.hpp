// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"
#include "Common.hpp"
#include "Quaternion.hpp"
#include "Vector4.hpp"
#include "Matrix4.hpp"


namespace jkl {


// Convert a quaternion into a 4 component vector
// representation.
Vector4f ToVector4(const Quaternion &q);

// Convert a quaternion into a 4 by 4 matrix
// representation.
Matrix4 ToMatrix4x4(const Quaternion &q);


Quaternion ToQuaternion(const Vector3f &eulerAngle);

// Normalize the quaternion. Normally, we should
// be sticking to unit quaternions, so this call
// should be kept limited.
Quaternion Normalize(const Quaternion &q);

// Spherical Linear Interpolation. Useful for 
// animations and whatnot.
Quaternion Slerp(const Quaternion &q0, const Quaternion &q1, real32 t);

// Produce a rotation about the hypersphere using x, y, z coordinates
// and an angle to tell about how much the quaternion will rotate.
// Quaternion q param descibes the initial position of the quaternion.
Quaternion AngleAxis(real32 angle, const Vector3f &axis);
} // jkl