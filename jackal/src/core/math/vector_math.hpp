//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once

#include "vector.hpp"
#include "common.hpp"


namespace jkl {


template<typename T>
Vector4<T> Normalize(const Vector4<T> &vec);

template<typename T>
Vector3<T> Normalize(const Vector3<T> &vec);

template<typename T>
Vector2<T> Normalize(const Vector2<T> &vec);

template<typename T>
Vector3<T> Cross(const Vector3<T> &a, const Vector3<T> &b);

template<typename T>
Vector3<T> Dot(const Vector3<T> &a, const Vector3<T> &b);

template<typename T>
Vector4<T> Dot(const Vector4<T> &a, const Vector4<T> &b);

template<typename T>
Vector2<T> Dot(const Vector2<T> &a, const Vector2<T> &b); 
} // jkl