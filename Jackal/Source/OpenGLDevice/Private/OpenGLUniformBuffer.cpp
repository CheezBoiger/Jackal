// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"

namespace jackal {


void OpenGLUniformBuffer::Initialize(GraphicsPipelineState *pipe, uint32 bind, const char *name)
{
  // Need to figure out a way to get this error more globally.
  if (!pipe) { 
    return; 
  }

  mBinding = bind;
  mName = name;
  // Reference the pipe.
  OpenGLGraphicsPipelineState *oglPipeRef = 
    static_cast<OpenGLGraphicsPipelineState *>(pipe);
  mProgramRef = oglPipeRef->GetProgramId();


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
  if (dynamic) ogl.size = sizeof(Matrix4);
  else ogl.size = sizeof(Matrix4) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetMat3(const char *name, Matrix3 *mat, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = mat;
  ogl.type = MATRIX3;
  if (dynamic) ogl.size = sizeof(Matrix3);
  else ogl.size = sizeof(Matrix3) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetMat2(const char *name, Matrix2 *mat, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = mat;
  ogl.type = MATRIX2;
  if (dynamic) ogl.size = sizeof(Matrix2);
  else ogl.size = sizeof(Matrix2) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetVec4(const char *name, Vector4 *vec, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = vec;
  ogl.type = VEC4;
  if (dynamic) ogl.size = sizeof(Vector4);
  else ogl.size = sizeof(Vector4) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetVec3(const char *name, Vector3 *vec, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = vec;
  ogl.type = VEC3;
  if (dynamic) ogl.size = sizeof(Vector3);
  else ogl.size = sizeof(Vector3) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetVec2(const char *name, Vector2 *vec, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = vec;
  ogl.type = VEC2;
  if(dynamic) ogl.size = sizeof(Vector2);
  else ogl.size = sizeof(Vector2) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetBool(const char *name, bool8 *b, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = b;
  ogl.type = BOOL;
  if (dynamic) ogl.size = sizeof(bool8);
  else ogl.size = sizeof(bool8) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetInt32(const char *name, int32 *i, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = i;
  ogl.type = INT;
  if (dynamic) ogl.size = sizeof(int32);
  else ogl.size = sizeof(int32) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetUInt32(const char *name, uint32 *ui, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = ui;
  ogl.type = UINT;
  if (dynamic) ogl.size = sizeof(uint32);
  else ogl.size = sizeof(uint32) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetFloat(const char *name, real32 *f, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = f;
  ogl.type = FLOAT;
  if (dynamic) ogl.size = sizeof(real32);
  else ogl.size = sizeof(real32) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::SetDouble(const char *name, real64 *d, uint32 count, bool8 dynamic)
{
  OGLData ogl;
  ogl.data = d;
  ogl.type = DOUBLE;
  if (dynamic) ogl.size = sizeof(real64);
  else ogl.size = sizeof(real64) * count;
  ogl.dynamic = dynamic;
  ogl.offset = mMemSize;
  mMemSize += ogl.size;

  mData.push_back(std::pair<std::string, OGLData>(name, ogl));
}


void OpenGLUniformBuffer::Update(uint32 *offsets)
{
  glBindBuffer(GL_UNIFORM_BUFFER, ubo);
  uint32 next = 0;
  for (auto &data : mData) {

    if (data.second.dynamic) {
      // NOTE(): Possible memory leak? We don't have 
      // a limit for offsets.
      glBufferSubData(GL_UNIFORM_BUFFER, 
        offsets[next], data.second.size, data.second.data);
        next += 1;
    } else {
      glBufferSubData(GL_UNIFORM_BUFFER,
        data.second.offset, data.second.size, data.second.data);
    }
    uint32 err;
    OPENGL_CHECK_ERROR(err);
    if (err != GL_NONE) {
      DebugBreak();
    }
  }
  
  glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
} // jackal