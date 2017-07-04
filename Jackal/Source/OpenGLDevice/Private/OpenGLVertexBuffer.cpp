// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLDevice/OpenGLVertexBuffer.hpp"


namespace jackal {


void OpenGLVertexBuffer::Initialize(const Vertex *data, 
  const size_t size, DataT type, const uint32 *indices, const size_t indicesSize)
{
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, size * sizeof(real32), data, 
    type == DATA_DYNAMIC ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
  if (indicesSize && indices) {
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(uint32),
    indices, type == DATA_DYNAMIC ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
  }

  size_t stride   = 3 * sizeof(real32);   // position
  stride          += 3 * sizeof(real32);  // normal
  stride          += 2 * sizeof(real32);  // uv/texcoord
  stride          += 3 * sizeof(real32);  // base color.
  
  // Define our data now.
  size_t offset = 0;

  // Position.
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid *)offset);  
  offset += 3 * sizeof(real32);

  // Normal.
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid *)offset);
  offset += 3 * sizeof(real32);  
  
  // UV.
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (GLvoid *)offset);
  offset += 2 * sizeof(real32);

  // Base Color
  glEnableVertexAttribArray(3);
  glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid *)offset);
  offset += 3 * sizeof(real32);

  // TODO(): Add in tangents into the vertex later on...
  // We will need to add them for bump mapping.
  glEnableVertexAttribArray(4);
  offset += 3 * sizeof(real32);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}


void OpenGLVertexBuffer::CleanUp()
{
  glDeleteBuffers(1, &vbo);
  glDeleteBuffers(1, &ibo);
  glDeleteVertexArrays(1, &vao);

  vbo = 0;
  vao = 0;
  ibo = 0;
}
} // jackal