// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

#include "RenderDeviceTypes.hpp"
#include "MaterialLayout.hpp"
#include "RenderObject.hpp"

namespace jackal {


class Shader;

struct VertexAttributeT {
  uint32  Binding;
  uint32  Location;
  FormatT Format;
  uint32  Offset;
};

struct VertexBindingInfoT {
  uint32            Binding;
  uint32            Stride;
  VertexInputRate   InputRate;
  uint32            VertexAttributesCount;
  VertexAttributeT* VertexAttribute;
};

// Graphics Pipeline information. This information is 
// sent through the graphics pipeline state object to parse
// and set values.
typedef struct {
  // Add a Vertex Shader to the rendering pipeline. This is 
  // MANDATORY or else the pipeline state will not function,
  // or even build.
  Shader*         VertexShader;

  // Add a Hull Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader*         HullShader;

  // Add a Domain Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader*         DomainShader;

  // Add a Geometry Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader*         GeometryShader;

  // Add a Pixel Shader to the rendering pipeline. This is optional.
  // Best to leave this null if not in use.
  Shader*         PixelShader;

  BlendT              SrcBlendMode;
  BlendT              DstBlendMode;
  BlendOperationT     BlendOp;
  CullModeT           CullMode;
  FrontFaceT          FrontFace;
  CompareT            DepthTestCompare;
  TopologyT           Topology;
  VertexBindingInfoT  VertexBindingInfo;

  // This is the layout of the Graphics Pipeline shaders, in terms of how 
  // samplers, uniforms, and data is laid out in shader code. Pipeline needs 
  // reference to the material layout that defines how data given it will be
  // used.
  MaterialLayout* Layout;
  
  bool8           ZBufferEnable   : 1,
                  StencilEnable   : 1,
                  BlendEnable     : 1,
                  CullFaceEnable  : 1;
} GraphicsPipelineInfoT;


struct GraphicsPipelineStateInfo {
  BlendT              SrcBlendMode;
  BlendT              DstBlendMode;
  BlendOperationT     BlendOp;
  CullModeT           CullMode;
  FrontFaceT          FrontFace;
  CompareT            DepthTestCompare;
  TopologyT           Topology;
  VertexBindingInfoT  VertexBindingInfo;

  // This is the layout of the Graphics Pipeline shaders, in terms of how 
  // samplers, uniforms, and data is laid out in shader code. Pipeline needs 
  // reference to the material layout that defines how data given it will be
  // used.
  MaterialLayout* Layout;

  bool8           ZBufferEnable : 1,
                  StencilEnable : 1,
                  BlendEnable : 1,
                  CullFaceEnable : 1;
};


// Graphics pipeline state object. Used to set up the rendering
// pipeline of the render device.
class GraphicsPipelineState : public RenderObject {
protected:
  GraphicsPipelineState(JString name = JTEXT("Default-GraphicsPipeline")) { }
public:
  virtual ~GraphicsPipelineState() { }

  // Set the pipeline state of this rendering pipe. This function will
  // bake the info provided to this pipeline, can not reverse this once
  // done!
  virtual void Bake(const GraphicsPipelineInfoT &info) = 0;
  virtual void CleanUp() = 0;

  // Get the information of this pipeline state.
  GraphicsPipelineStateInfo *GetPipelineInformation() { return &mPipelineInfo; }

  RenderErrorT GetLastError() { return mLastError; }

protected:
  GraphicsPipelineStateInfo   mPipelineInfo;
  RenderErrorT            mLastError;
};
} // jackal