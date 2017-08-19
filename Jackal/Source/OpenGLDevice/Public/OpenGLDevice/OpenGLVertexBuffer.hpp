// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "OpenGLConfigs.hpp"
#include "RenderDevice/VertexBuffer.hpp"

namespace jackal {


// OpenGL Vertex Buffer object.
class OpenGLVertexBuffer : public VertexBuffer {
public:
  OpenGLVertexBuffer()
    : vbo(0)
    , ibo(0) { }

  void Initialize(const Vertex *data, const size_t size, DataT type,
    const uint32 *indices = nullptr, size_t indicesSize = 0) override;


  void CleanUp() override;
  
  // Vertex Buffer Object.
  GLuint vbo;

  // Index Buffer Object.
  GLuint ibo;
};
} // jackal