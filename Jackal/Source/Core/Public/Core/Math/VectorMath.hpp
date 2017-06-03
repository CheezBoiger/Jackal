// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Vector4.hpp"
#include "Common.hpp"


namespace jkl {


// Normalize the Vector4 object to a unit length.
Vector4 Normalize(const Vector4 &vec);

// Normalize a Vector3 object to a unit length.
Vector3 Normalize(const Vector3 &vec);

// Normalize a Vector2 object to a unit length.
Vector2 Normalize(const Vector2 &vec);

// Get the cross product of two 3-component vectors.
Vector3 Cross(const Vector3 &u, const Vector3 &v);

// Get the dot product of two 3-component vectors.
real32 Dot(const Vector3 &u, const Vector3 &v);

// Get the dot product of two 4-component vectors.
real32 Dot(const Vector4 &u, const Vector4 &v);

// Get the dot product of two 2-component vectors.
real32 Dot(const Vector2 &u, const Vector2 &v); 

// Calculate the linear interpolation of a 3-component vector in space, at time
// t.
Vector3 Lerp(const Vector3 &u, const Vector3 &v, real32 t);

// Calculat the linear interpolation of a 2-component vector in space, at time
// t.
Vector2 Lerp(const Vector2 &v0, const Vector2 &v1, real32 t);
} // jkl