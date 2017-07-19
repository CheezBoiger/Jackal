// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"

#include "Shader.hpp"


namespace jackal {


struct ComputePipelineInfoT {
  Shader *ComputeShader;  
};


class ComputePipelineState : public RenderObject {
public:
  virtual ~ComputePipelineState() { }


  virtual void Bake(ComputePipelineInfoT &info) = 0;


  ComputePipelineInfoT *GetPipelineInformation() { return &mInformation; }

protected:
  ComputePipelineInfoT mInformation;;
};
} // jackal