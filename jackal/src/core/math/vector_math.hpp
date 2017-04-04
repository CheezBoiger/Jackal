//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "vector.hpp"
#include "common.hpp"


namespace jkl {


// Normalize the Vector4 object to a unit length.
template<typename T>
Vector4<T> Normalize(const Vector4<T> &vec);

// Normalize a Vector3 object to a unit length.
template<typename T>
Vector3<T> Normalize(const Vector3<T> &vec);

// Normalize a Vector2 object to a unit length.
template<typename T>
Vector2<T> Normalize(const Vector2<T> &vec);

// Get the cross product of two 3-component vectors.
template<typename T>
Vector3<T> Cross(const Vector3<T> &u, const Vector3<T> &v);

// Get the dot product of two 3-component vectors.
template<typename T>
T Dot(const Vector3<T> &u, const Vector3<T> &v);

// Get the dot product of two 4-component vectors.
template<typename T>
T Dot(const Vector4<T> &u, const Vector4<T> &v);

// Get the dot product of two 2-component vectors.
template<typename T>
T Dot(const Vector2<T> &u, const Vector2<T> &v); 

// Calculate the linear interpolation of a 3-component vector in space, at time
// t.
template<typename T>
Vector3<T> Lerp(const Vector3<T> &u, const Vector3<T> &v, T t);

// Calculat the linear interpolation of a 2-component vector in space, at time
// t.
template<typename T>
Vector2<T> Lerp(const Vector2<T> &v0, const Vector2<T> &v1, T t);
} // jkl

#include "internal/vector_math.inl"