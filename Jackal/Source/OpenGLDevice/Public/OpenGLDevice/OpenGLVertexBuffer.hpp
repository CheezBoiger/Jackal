// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "OpenGLConfigs.hpp"
#include "RenderDevice/VertexBuffer.hpp"

namespace jackal {


class OpenGLVertexBuffer : public VertexBuffer {
public:

  void SetBufferData(const Vertex *data, const size_t size) override;


  GLuint vao;
  GLuint vbo;
  GLuint ibo;
};
} // jackal