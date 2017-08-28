// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

namespace jackal {


class Buffer {
public:
  virtual ~Buffer() { }

  virtual void**  Map(uint32 size, uint32 offset) = 0;
  virtual void    UnMap() = 0;
};
} // jackal