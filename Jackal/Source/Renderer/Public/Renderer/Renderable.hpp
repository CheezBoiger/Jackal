// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

namespace jackal {


typedef uint64_t render_id_t;


class Renderable {
public:
  virtual ~Renderable() { }

};
} // jackal