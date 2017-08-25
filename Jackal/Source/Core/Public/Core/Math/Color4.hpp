// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"

#include "Vector4.hpp"


namespace jackal {


// Color values marked with normalized values from [0.0f, 1.0f].
// These values are used to determine the color of some mesh object.
struct Color {
  Color(uint8 r = 0, uint8 g = 0, uint8 b = 0, uint8 a = 0)
    : r(r), g(g), b(b), a(a) { }

  struct { uint8 r, g, b, a; };
};

// Standard color values.
static Color RED =             Color(255, 0,    0,    255);
static Color GREEN =           Color(0,   255,  0,    255);
static Color BLUE =            Color(0,   0,    255,  255);
static Color BLACK =           Color(0,   0,    0,    255);
static Color WHITE =           Color(255, 255,  255,  255);
} // jackal