// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Vertex.hpp"
#include "RenderObject.hpp"
#include "RenderDeviceTypes.hpp"


namespace jackal {


// Vertex Buffer object, used for rendering vertex data onto a surface.
class VertexBuffer : public RenderObject {
protected:
  VertexBuffer() { }

public:

  virtual ~VertexBuffer() { }

  // Store vertices into this vertex buffer.
  virtual void Initialize(const Vertex *data, const size_t size, DataT type,
    const uint32 *indices = nullptr, size_t indicesSize = 0) = 0; 

  virtual void CleanUp() = 0;
};
} // jackal