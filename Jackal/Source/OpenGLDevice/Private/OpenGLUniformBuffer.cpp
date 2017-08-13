// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"

#include "Core/Logging/Debugging.hpp"

namespace jackal {


void OpenGLUniformBuffer::Initialize(uint32 bind, const char *name)
{

  mBinding = bind;
  mName = name;

  // OpenGL Stuff.
  glGenBuffers(1, &ubo);
  glBindBuffer(GL_UNIFORM_BUFFER, ubo);

  glBufferData(GL_UNIFORM_BUFFER, mMemSize, NULL, 
    (mDataType == DATA_DYNAMIC ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW));

  glBindBufferBase(GL_UNIFORM_BUFFER, mBinding, ubo);
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


void OpenGLUniformBuffer::SetMat4(const char *name, Matrix4 *mat, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = mat;
  ogl.type = MATRIX4;
  ogl.dataSize = sizeof(Matrix4);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetMat3(const char *name, Matrix3 *mat, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = mat;
  ogl.type = MATRIX3;
  ogl.dataSize = sizeof(Matrix3);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetMat2(const char *name, Matrix2 *mat, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = mat;
  ogl.type = MATRIX2;
  ogl.dataSize = sizeof(Matrix2);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetVec4(const char *name, Vector4 *vec, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = vec;
  ogl.type = VEC4;
  ogl.dataSize = sizeof(Vector4);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetVec3(const char *name, Vector3 *vec, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = vec;
  ogl.type = VEC3;
  ogl.dataSize = sizeof(Vector3);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetVec2(const char *name, Vector2 *vec, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = vec;
  ogl.type = VEC2;
  ogl.dataSize = sizeof(Vector2);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetBool(const char *name, bool8 *b, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = b;
  ogl.type = BOOL;
  ogl.dataSize = sizeof(bool8);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetInt32(const char *name, int32 *i, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = i;
  ogl.type = INT;
  ogl.dataSize = sizeof(int32);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetUInt32(const char *name, uint32 *ui, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = ui;
  ogl.type = UINT;
  ogl.dataSize = sizeof(uint32);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetFloat(const char *name, real32 *f, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = f;
  ogl.type = FLOAT;
  ogl.dataSize = sizeof(real32);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetDouble(const char *name, real64 *d, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = d;
  ogl.type = DOUBLE;
  ogl.dataSize = sizeof(real64);
  if (!dynamic) ogl.dataSize *= count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.dataSize;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::Update(uint32 *offsets)
{
  glBindBuffer(GL_UNIFORM_BUFFER, ubo);
  uint32 next = 0;
  for (auto &data : mData) {
    GLint size;
    glGetBufferParameteriv(GL_UNIFORM_BUFFER, GL_BUFFER_SIZE, &size); 
    if (data.second.dynamic) {
      // NOTE(): Possible memory leak? We don't have 
      // a limit for offsets.
      glBufferSubData(GL_UNIFORM_BUFFER, 
        data.second.offset, data.second.dataSize, 
        ((bool8 *)data.second.data + offsets[next]));
        next += 1;
    } else {
      glBufferSubData(GL_UNIFORM_BUFFER,
        data.second.offset, data.second.dataSize, data.second.data);
    }

    uint32 err;
    OPENGL_CHECK_ERROR(err);
    if (err != GL_NONE) {
      JDEBUG("Uniform Buffer Error! Code: %d\n", err);
      break;
    }
  }
  
  glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
} // jackal