// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLDevice/OpenGLVertexBuffer.hpp"

#include "Core/Logging/Assertions.hpp"
#include "Core/Logging/Debugging.hpp"

namespace jackal {


void OpenGLVertexBuffer::Initialize(const Vertex *data, 
  const size_t size, DataT type, const uint32 *indices, const size_t indicesSize)
{
  glGenBuffers(1, &vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, size * sizeof(real32), data, 
    type == DATA_DYNAMIC ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
  if (indicesSize && indices) {
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(uint32),
    indices, type == DATA_DYNAMIC ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);   
  }

  OPENGL_CHECK_ERROR(GLenum err);
  if (err != GL_NO_ERROR) {
    JDEBUG("Error setting up vertex buffers!\n");
  }
}


void OpenGLVertexBuffer::CleanUp()
{
  glDeleteBuffers(1, &vbo);
  glDeleteBuffers(1, &ibo);

  vbo = 0;
  ibo = 0;
}
} // jackal