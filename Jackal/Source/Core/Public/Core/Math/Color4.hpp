// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"

#include "Vector4.hpp"


namespace jackal {


// Standard color values.
static Colorf RED =             Colorf(1.0f, 0.0f, 0.0f, 1.0f);
static Colorf GREEN =           Colorf(0.0f, 1.0f, 0.0f, 1.0f);
static Colorf BLUE =            Colorf(0.0f, 0.0f, 1.0f, 1.0f);
static Colorf BLACK =           Colorf(0.0f, 0.0f, 0.0f, 1.0f);
static Colorf WHITE =           Colorf(1.0f, 1.0f, 1.0f, 1.0f);

// Color values marked with normalized values from [0.0f, 1.0f].
// These values are used to determine the color of some mesh object.
struct Color4f {
  struct { real32 r, g, b, a; };
};

typedef Color4f Color4;
} // jackal