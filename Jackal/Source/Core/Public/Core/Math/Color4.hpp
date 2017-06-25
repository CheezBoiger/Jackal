// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"



namespace jackal {


// Color values marked with normalized values from [0.0f, 1.0f].
// These values are used to determine the color of some mesh object.
struct Color4f {
  struct { real32 r, g, b, a; };
};

typedef Color4f Color4;
} // jackal