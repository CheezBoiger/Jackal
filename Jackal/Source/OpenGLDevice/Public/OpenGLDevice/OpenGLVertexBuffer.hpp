// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "OpenGLConfigs.hpp"
#include "RenderDevice/VertexBuffer.hpp"

namespace jackal {


class OpenGLVertexBuffer : public VertexBuffer {
public:
  OpenGLVertexBuffer()
    : vao(0)
    , vbo(0)
    , ibo(0) { }

  void Initialize(const Vertex *data, const size_t size, DataT type,
    const uint32 *indices = nullptr, size_t indicesSize = 0) override;


  void CleanUp() override;

  // We use a Vertex Array Object to better handle overhead when rendering
  // vertices onto the screen.
  GLuint vao;
  
  // Vertex Buffer Object.
  GLuint vbo;

  // Index Buffer Object.
  GLuint ibo;
};
} // jackal