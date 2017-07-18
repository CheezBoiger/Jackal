// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "Core/Math/Matrix4.hpp"
#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix2.hpp"

#include "Texture.hpp"
#include "RenderObject.hpp"
#include "GraphicsPipelineState.hpp"


namespace jackal {


class GraphicsPipelineState;

// Uniform Buffer object, which allows the manipulation of 
// information to be passed to uniform buffers, or uniform values 
// in shaders.
class UniformBuffer : public RenderObject {
protected:
  UniformBuffer() 
    : mBinding(0) 
    , mDataType(DataT::DATA_STATIC)
    , mMemSize(0) { }

public:
  typedef uint32 mem_offset_t;
  virtual ~UniformBuffer() { }

  // TODO(): Figure out how to properly add in model matrices to these,
  // Vulkan is not dynamic, so everything must be done before actual rendering,
  // this leaves little room to add multiple model matrices in the form of an array.
  // Current approach:
  // Store into binding indices. Any values stored into the same binding, are 
  // stored depending on data type. If two values of the same data type are stored,
  // will add into a list. OpenGL will read the binding description, as well as
  // vulkan.

  // Set a matrix variable in the uniform buffer, with the provided offset from
  // 0 of the struct. Returns the current offset after setting the variable. You
  // can use the value returned as the parameter for these functions in order to
  // store them sequentially.
  virtual void SetMat4(const char *name, Matrix4 *mat, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetMat3(const char *name, Matrix3 *mat, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetMat2(const char *name, Matrix2 *mat, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetVec4(const char *name, Vector4 *vec, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetVec3(const char *name, Vector3 *vec, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetVec2(const char *name, Vector2 *vec, uint32 count = 1, bool8 dynamic = false) = 0;

  virtual void SetBool(const char *name, bool8 *b, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetInt32(const char *name, int32 *i, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetUInt32(const char *name, uint32 *ui, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetFloat(const char *name, real32 *f, uint32 count = 1, bool8 dynamic = false) = 0;
  virtual void SetDouble(const char *name, real64 *d, uint32 count = 1, bool8 dynamic = false) = 0;

  uint32 GetBindingIndex() { return mBinding; }

  // Set Data type, determine whether or not it is going to be updated
  // frequently or not.
  void SetDataType(DataT d) { mDataType = d; }

  DataT GetDataType() { return mDataType; }
  const char *GetName() { return mName; }

  // Initialize this object. Must provide it with the name given from the shader
  // file, along with the graphics pipeline state that it resides in. Be Sure to 
  // set your variables before initializing, otherwise this buffer won't know the 
  // size of the data to store!
  virtual void Initialize(GraphicsPipelineState *pipe, uint32 bind, const char *name) = 0;

  // Get the total size of the uniform buffer object in memory.
  virtual uint32 GetTotalSize() { return mMemSize; }

  // Update the uniform buffer, should update information on the gpu, along provided
  // binding points inside a program. Offsets depend on whether this UBO is dynamic,
  // to which we need to specify offsets that are prevalent in our ubo data. This 
  // can be ignored if ubo is static. Offsets are laid out according to the order of 
  // how data was stored inside this ubo.
  virtual void Update(uint32 *offsets = nullptr) = 0;

  virtual void CleanUp() = 0;

protected:
  DataT       mDataType;
  uint32      mBinding;
  const char  *mName;
  uint32      mMemSize;
};
} // jackal