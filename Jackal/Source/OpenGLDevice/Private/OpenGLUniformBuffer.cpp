// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"

#include "Core/Logging/Debugging.hpp"
#include <stdlib.h>

namespace jackal {


void OpenGLUniformBuffer::Initialize(UniformBufferCreateInfoT& info)
{
  CleanUp();
  // OpenGL Stuff.
  glGenBuffers(1, &ubo);
  glBindBuffer(GL_UNIFORM_BUFFER, ubo);

  glBufferData(GL_UNIFORM_BUFFER, info.Size, NULL, 
    (mDataType == DATA_DYNAMIC ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW));

  glBindBufferBase(GL_UNIFORM_BUFFER, (GLuint )info.Bind, ubo);
  void* data = Map();
    memcpy(data, info.Data, info.Size);
  UnMap();
  
  OPENGL_CHECK_ERROR(GLenum error);
  if (error != GL_NO_ERROR) {
    return;
  }
  glBindBuffer(GL_UNIFORM_BUFFER, 0);
}


void OpenGLUniformBuffer::CleanUp()
{
  if (!ubo) {
    return;
  }
  
  glDeleteBuffers(1, &ubo);
  ubo = -1;
}


void* OpenGLUniformBuffer::Map()
{
  glBindBuffer(GL_UNIFORM_BUFFER, ubo);
  void* data = glMapBuffer(GL_UNIFORM_BUFFER, GL_READ_WRITE);
  OPENGL_CHECK_ERROR(GLenum error);
  if (error != GL_NO_ERROR) {
    return nullptr;
  }
  return data; 
}


void OpenGLUniformBuffer::UnMap()
{
  glBindBuffer(GL_UNIFORM_BUFFER, ubo);
  glUnmapBuffer(GL_UNIFORM_BUFFER);
  OPENGL_CHECK_ERROR(GLenum error);
  if (error != GL_NO_ERROR) {
    JDEBUG("UnMap error!\n");
    return;
  }
}
} // jackal