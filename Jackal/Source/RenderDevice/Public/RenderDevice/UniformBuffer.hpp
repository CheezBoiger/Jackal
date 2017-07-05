// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "Core/Math/Matrix4.hpp"
#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix2.hpp"

#include "Texture.hpp"
#include "RenderObject.hpp"


namespace jackal {


// Uniform Buffer object, which allows the manipulation of 
// information to be passed to uniform buffers, or uniform values 
// in shaders.
class UniformBuffer : public RenderObject {
protected:
  UniformBuffer(DataT dataType) { }

public:
  virtual ~UniformBuffer() { }

  // TODO(): Figure out how to properly add in model matrices to these,
  // Vulkan is not dynamic, so everything must be done before actual rendering,
  // this leaves little room to add multiple model matrices in the form of an array.
  // Current approach:
  // Store into binding indices. Any values stored into the same binding, are 
  // stored depending on data type. If two values of the same data type are stored,
  // will add into a list. OpenGL will read the binding description, as well as
  // vulkan.
  virtual void SetMat4(JString name, Matrix4 mat, uint32 binding) = 0;
  virtual void SetMat3(JString name, Matrix3 mat, uint32 binding) = 0;
  virtual void SetMat2(JString name, Matrix2 mat, uint32 binding) = 0;
  virtual void SetVec4(JString name, Vector4 vec, uint32 binding) = 0;
  virtual void SetVec3(JString name, Vector3 vec, uint32 binding) = 0;
  virtual void SetVec2(JString name, Vector2 vec, uint32 binding) = 0;

  virtual void SetBool(JString name, bool8 b, uint32 binding) = 0;
  virtual void SetInt32(JString name, int32 i, uint32 binding) = 0;
  virtual void SetUInt32(JString name, uint32 ui, uint32 binding) = 0;
  virtual void SetFloat(JString name, real32 f, uint32 binding) = 0;
  virtual void SetDouble(JString name, real64 d, uint32 binding) = 0;

  virtual void Update() = 0;

protected:
  DataT       mDataType;
};
} // jackal