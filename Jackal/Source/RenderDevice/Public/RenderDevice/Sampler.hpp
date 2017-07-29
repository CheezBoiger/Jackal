// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"


namespace jackal {


struct SamplerInfoT {
  WrapModeT   WrapS;
  WrapModeT   WrapT;
  WrapModeT   WrapR;
  FilterModeT MagFilter;
  FilterModeT MinFilter;
  uint32      MinLod;
  uint32      MaxLod;
};


// Sampler Object. Required in order to render out texture objects.
class Sampler : public RenderObject {
protected:
  SamplerInfoT mInformation;

  Sampler() { }

public:
  virtual ~Sampler() { }
  
  // Bake provided information into this sampler.
  virtual void Bake(SamplerInfoT &info) = 0;

  virtual void CleanUp() = 0;

  SamplerInfoT *GetInformation() { return &mInformation; }
};
} // jackal