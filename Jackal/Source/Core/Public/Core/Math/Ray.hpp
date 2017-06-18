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
  Vector3 point;
  Vector3 direction;
};
} // jackal