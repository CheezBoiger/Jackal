// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Common.hpp"
#include "Quaternion.hpp"
#include "Vector4.hpp"
#include "Matrix4.hpp"


namespace jackal {

// Convert a quaternion into a 4 by 4 matrix
// representation.
Matrix4 ToMatrix4(const Quaternion &q);

Quaternion ToQuaternion(const Vector3f &eulerAngle);

// Convert a quaternion to euler angles.
Vector3f ToEulerAngles(const Quaternion &quat);

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

// Dot product between two quaternions.
real32 Dot(const Quaternion &quat1, const Quaternion &quat2);

// Rotate a quaternion to the direction of a vector.
Quaternion Rotate(const Quaternion &quat, const Vector3f &dir);
} // jackal