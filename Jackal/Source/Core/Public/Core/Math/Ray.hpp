// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Platform/Api.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Common.hpp"

#include "Vector3.hpp"


namespace jackal {


// Ray class defines a Ray object in 3D space that defines
// a start point, and a direction. Such an object theoretically
// extends infinitely, as we can assume. The importance simply allows
// for raycasting, ray tracing, and many other useful tools for our arsenal.
struct Ray {
  Ray(Vector3 origin, Vector3 direction)
    : Origin(origin)
    , Direction(direction) { }

  // Obtain a point along this ray at time t, in seconds.
  // Equation of a ray at t. 
  Vector3 Point(real32 t) {
    return Origin + (Direction * t);
  }

  // The P0 origin of this ray, otherwise known as the starting point.
  Vector3 Origin;
  
  // The Direction of where this ray is pointing. This value MUST be normalized.
  Vector3 Direction;
};
} // jackal