// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDevice/UniformBuffer.hpp"

#include "OpenGLConfigs.hpp"

#include <map>
#include <string>
#include <memory>


namespace jackal {


class OpenGLUniformBuffer : public UniformBuffer { 
public:
  ~OpenGLUniformBuffer();
  
  void SetMat4(const char *name, Matrix4 mat) override;
  void SetMat3(const char *name, Matrix3 mat) override;
  void SetMat2(const char *name, Matrix2 mat) override;
  void SetVec4(const char *name, Vector4 vec) override;
  void SetVec3(const char *name, Vector3 vec) override;
  void SetVec2(const char *name, Vector2 vec) override;

  void SetBool(const char *name, bool8 b) override;
  void SetInt32(const char *name, int32 i) override;
  void SetUInt32(const char *name, uint32 ui) override;
  void SetFloat(const char *name, real32 f) override;
  void SetDouble(const char *name, real64 d) override;

  void Initialize(GraphicsPipelineState *pipe, uint32 bind, const char *name) override;
  void Update() override;

private:
  // The type of data we are storing.
  enum Type {
    MATRIX4, MATRIX3, MATRIX2,
    VEC4, VEC3, VEC2,
    BOOL, INT, UINT,
    FLOAT, DOUBLE,
  };

  // Data object to store in the buffer.
  struct OGLData {
    Type type;
    mem_offset_t  offset;
    bool8         dirty; 

    virtual GLintptr GetSize() = 0;
    virtual void *GetData() = 0;
    virtual void Store(void *data) = 0;
    OGLData() { }
    virtual ~OGLData() { }
  };  

  GLuint mProgramRef;
  GLuint ubo;
  std::map<std::string, std::unique_ptr<OGLData> > mData;
};
} // jackal