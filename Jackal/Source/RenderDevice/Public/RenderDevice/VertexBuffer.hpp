// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Vertex.hpp"
#include "RenderObject.hpp"

namespace jackal {


// Vertex Buffer object, used for rendering vertex data onto a surface.
class VertexBuffer : public RenderObject {
protected:
  VertexBuffer() { }

public:

  virtual ~VertexBuffer() { }

  virtual void SetBufferData(const Vertex *data, const size_t size) = 0; 


};
} // jackal