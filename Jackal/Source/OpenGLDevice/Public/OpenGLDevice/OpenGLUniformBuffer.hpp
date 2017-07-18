// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDevice/UniformBuffer.hpp"

#include "OpenGLConfigs.hpp"

#include <list>
#include <string>
#include <memory>


namespace jackal {


// OpenGL Native Uniform Buffer.
class OpenGLUniformBuffer : public UniformBuffer { 
public:
  
  void SetMat4(const char *name, Matrix4 *mat, uint32 count, bool8 dynamic = false) override;
  void SetMat3(const char *name, Matrix3 *mat, uint32 count, bool8 dynamic = false) override;
  void SetMat2(const char *name, Matrix2 *mat, uint32 count, bool8 dynamic = false) override;
  void SetVec4(const char *name, Vector4 *vec, uint32 count, bool8 dynamic = false) override;
  void SetVec3(const char *name, Vector3 *vec, uint32 count, bool8 dynamic = false) override;
  void SetVec2(const char *name, Vector2 *vec, uint32 count, bool8 dynamic = false) override;

  void SetBool(const char *name, bool8 *b, uint32 count, bool8 dynamic = false) override;
  void SetInt32(const char *name, int32 *i, uint32 count, bool8 dynamic = false) override;
  void SetUInt32(const char *name, uint32 *ui, uint32 count, bool8 dynamic = false) override;
  void SetFloat(const char *name, real32 *f, uint32 count, bool8 dynamic = false) override;
  void SetDouble(const char *name, real64 *d, uint32 count, bool8 dynamic = false) override;

  void Initialize(GraphicsPipelineState *pipe, uint32 bind, const char *name) override;
  void Update(uint32 *offsets = nullptr) override;
  void CleanUp() override;

  GLuint GetProgramRef() const { return mProgramRef; }
  GLuint Handle() const { return ubo; }

private:
  // The type of data we are storing.
  enum Type {
    MATRIX4, MATRIX3, MATRIX2,
    VEC4, VEC3, VEC2,
    BOOL, INT, UINT,
    FLOAT, DOUBLE,
  };

  // Data object to store in the buffer.
  // TODO(): Need to figure out a way to prevent constant updating of data when it is not 
  // needed for updating.
  struct OGLData {
    Type          type; // data type of this value.
    mem_offset_t  offset; // offset value within the uniform buffer.
    uint32        dataSize; // This is the size of each object in our data, not the size of the array.
    void *        data; // the actual data. 
    bool8         dynamic; // whether the data is dynamic.
  };  

  // Shader Program reference.
  GLuint mProgramRef;

  // OpenGL native buffer object handle.
  GLuint ubo;

  // Map to data that is stored in this uniform buffer object.
  std::list<std::pair<std::string, OGLData> > mData;
};
} // jackal