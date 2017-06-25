// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Math/Vector4.hpp"
#include "Core/Math/Vector3.hpp"


namespace jackal {


// Basic Vertex with its value coordinates.
// Will be used later on for other vertex types.
struct Vertex {
  Vector3f Position;
  Vector3f Normal;
  Vector2f TexCoords;
  Vector4f BaseColor;

  // Tangent will be added in later.  
};
} // jackal