// Copyright (c) 2017 Jackal Engine, MIT License.
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"

namespace jackal {


OpenGLUniformBuffer::~OpenGLUniformBuffer()
{

}


void OpenGLUniformBuffer::Initialize(GraphicsPipelineState *pipe, uint32 bind, const char *name)
{
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


void OpenGLUniformBuffer::SetMat4(const char *name, Matrix4 mat)
{
  struct Mat4Data : public OGLData {
  public:
    Mat4Data(Matrix4 m) : matrix(m) { }
    void *GetData() override { return &matrix; }
    GLintptr GetSize() override { return sizeof(Matrix4); } 
    void Store(void *data) override { matrix = *static_cast<Matrix4 *>(data); }
    Matrix4 matrix;
  };
  
  auto it = mData.find(name);
  if (it == mData.end()) {
    Mat4Data * dat = new Mat4Data(mat);
    dat->offset = mMemSize;
    dat->type = MATRIX4;
    mData[name].reset(dat);

    mMemSize += sizeof(Matrix4);
  } else {
    if (it->second->type == MATRIX4) it->second->Store(&mat);
  }
}


void OpenGLUniformBuffer::SetMat3(const char *name, Matrix3 mat)
{
  class Mat3Data : public OGLData {
  public:
    Mat3Data(Matrix3 m) : matrix(m) { }
    void *GetData() override { return &matrix; }
    GLintptr GetSize() override { return sizeof(Matrix3); }
    void Store(void *data) override { matrix = *static_cast<Matrix3 *>(data); }
    Matrix3 matrix;
  };

  auto it = mData.find(name);
  if (it == mData.end()) {
    Mat3Data *dat = new Mat3Data(mat);
    dat->dirty = true;
    dat->type = MATRIX3;
    dat->offset = mMemSize;
    mData[name].reset(dat);

    // Always update the size of the ubo. we will need it later.
    mMemSize += sizeof(Matrix3);
  } else {
    if (it->second->type == MATRIX3) it->second->Store(&mat);
  }
}


void OpenGLUniformBuffer::SetMat2(const char *name, Matrix2 mat)
{
}


void OpenGLUniformBuffer::SetVec4(const char *name, Vector4 vec)
{
}


void OpenGLUniformBuffer::SetVec3(const char *name, Vector3 vec)
{
}


void OpenGLUniformBuffer::SetVec2(const char *name, Vector2 vec)
{
}


void OpenGLUniformBuffer::SetBool(const char *name, bool8 b)
{
}


void OpenGLUniformBuffer::SetInt32(const char *name, int32 i)
{
}


void OpenGLUniformBuffer::SetUInt32(const char *name, uint32 ui)
{
}


void OpenGLUniformBuffer::SetFloat(const char *name, real32 f)
{
}


void OpenGLUniformBuffer::SetDouble(const char *name, real64 d)
{
}

void OpenGLUniformBuffer::Update()
{
  glBindBuffer(GL_UNIFORM_BUFFER, ubo);

  for (auto &data : mData) {
    if (data.second->dirty) {
      glBufferSubData(GL_UNIFORM_BUFFER, 
        data.second->offset, data.second->GetSize(), data.second->GetData());
    }
  }
  
  glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
} // jackal