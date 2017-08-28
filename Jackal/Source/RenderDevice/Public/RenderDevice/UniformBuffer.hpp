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


struct UniformBufferCreateInfoT {
  size_t  Bind;
  size_t  Size;
  DataT   Type;
  void*   Data;
};

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
  uint32 GetBindingIndex() { return mBinding; }

  // Initialize this object. Must provide it with the name given from the shader
  // file, along with the graphics pipeline state that it resides in. Be Sure to 
  // set your variables before initializing, otherwise this buffer won't know the 
  // size of the data to store!
  virtual void Initialize(UniformBufferCreateInfoT& info) = 0;

  virtual void* Map() = 0;
  virtual void UnMap() = 0;

  // Get the total size of the uniform buffer object in memory.
  virtual uint32 GetTotalSize() { return mMemSize; }

  virtual void CleanUp() = 0;

protected:
  DataT       mDataType;
  uint32      mBinding;
  const char  *mName;
  uint32      mMemSize;
};
} // jackal