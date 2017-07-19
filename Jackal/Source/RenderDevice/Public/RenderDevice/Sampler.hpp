// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"


namespace jackal {


struct ShaderInfoT {
  WrapModeT   WrapS;
  WrapModeT   WrapT;
  WrapModeT   WrapR;
  FilterModeT MagFilter;
  FilterModeT MinFilter;
  uint32      MinLod;
  uint32      MaxLod;
};


// Sampler Object.
class Sampler : public RenderObject {
protected:
  ShaderInfoT mInformation;

  Sampler() { }

public:
  virtual ~Sampler() { }
  virtual void Bake() = 0;

  ShaderInfoT *GetInformation() { return &mInformation; }
};
} // jackal