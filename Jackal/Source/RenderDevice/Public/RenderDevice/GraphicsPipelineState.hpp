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
  Shader     *VertexShader;

  // Add a Hull Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader     *HullShader;

  // Add a Domain Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader     *DomainShader;

  // Add a Geometry Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader     *GeometryShader;

  // Add a Pixel Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader     *PixelShader;

  BlendT      BlendType;
  CullModeT   CullMode;
  FrontFaceT  FrontFace;
  
  bool8       ZBufferEnable   : 1,
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

  // Set the pipeline state of this rendering pipe.
  virtual void SetPipelineState(const GraphicsPipelineInfoT *info) = 0;

  // Get the information of this pipeline state.
  GraphicsPipelineInfoT *GetPipelineInformation() { return &mPipelineInfo; }

  // Update the Graphics Pipeline if need be.
  virtual void Update() = 0;

  // Check if this graphics pipeline is dirty, and must be 
  // updated.
  virtual bool8 Dirty() = 0;

  void SetName(JString name) { mName = name; }
  JString &Name() { return mName; }

protected:
  GraphicsPipelineInfoT mPipelineInfo;
  JString mName;
};
} // jackal