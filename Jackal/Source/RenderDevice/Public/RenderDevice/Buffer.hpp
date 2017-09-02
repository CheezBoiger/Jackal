// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

#include "RenderDeviceTypes.hpp"

namespace jackal {


typedef struct BufferCreateInfoT {
  BufferType      Type;
  DataT           Usage;
  uint32          Size;
  void*           Data;
} BufferInfo;


// Generic Buffer object, will be used in the near future to define 
// Buffers of all type. RenderDevice will be the handler for these buffers.
class Buffer {
public:
  virtual ~Buffer() { }

  virtual void Initialize(BufferCreateInfoT& info) = 0;
  virtual void**  Map(uint32 size, uint32 offset) = 0;
  virtual void    UnMap() = 0;
};
} // jackal