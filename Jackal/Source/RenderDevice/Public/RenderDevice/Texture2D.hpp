// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Core/Platform/JTypes.hpp"

#include "Texture.hpp"

namespace jackal {

struct Sampler2DInfoT {
  WrapModeT WrapS;
  WrapModeT WrapT;
  FilterModeT FilterMode;
};


class Sampler2D {
public:
  virtual ~Sampler2D() { }

protected:
  Sampler2DInfoT mInfo;
};


class Texture2D {
public:
  virtual ~Texture2D() { }
};
} // jackal