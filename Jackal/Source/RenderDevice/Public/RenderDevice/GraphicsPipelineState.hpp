// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

#include "RenderDeviceTypes.hpp"

namespace jackal {


class Shader;

// Graphics Pipeline information. This information is 
// sent through the graphics pipeline state object to parse
// and set values.
typedef struct {
  // Add a Vertex Shader to the rendering pipeline. This is 
  // MANDATORY or else the pipeline state will not function,
  // or even build.
  Shader         *VertexShader;

  // Add a Hull Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader         *HullShader;

  // Add a Domain Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader         *DomainShader;

  // Add a Geometry Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader         *GeometryShader;

  // Add a Pixel Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader         *PixelShader;
  BlendT          SrcBlendMode;
  BlendT          DstBlendMode;
  BlendOperationT BlendOp;
  CullModeT       CullMode;
  FrontFaceT      FrontFace;
  CompareT        DepthTestCompare;
  
  bool8           ZBufferEnable   : 1,
                  StencilEnable   : 1,
                  BlendEnable     : 1,
                  CullFaceEnable  : 1;
} GraphicsPipelineInfoT;


// Graphics pipeline state object. Used to set up the rendering
// pipeline of the render device.
class GraphicsPipelineState {
protected:
  GraphicsPipelineState(JString name = JTEXT("Default-GraphicsPipeline")) { }
public:
  virtual ~GraphicsPipelineState() { }

  // Set the pipeline state of this rendering pipe. This function will
  // bake the info provided to this pipeline, can not reverse this once
  // done!
  virtual void Bake(const GraphicsPipelineInfoT &info) = 0;

  // Get the information of this pipeline state.
  GraphicsPipelineInfoT *GetPipelineInformation() { return &mPipelineInfo; }

  void SetName(JString name) { mName = name; }
  JString &Name() { return mName; }

  RenderErrorT GetLastError() { return mLastError; }

protected:
  GraphicsPipelineInfoT mPipelineInfo;
  JString mName;
  RenderErrorT mLastError;
};
} // jackal