// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "OpenGLConfigs.hpp"
#include "RenderDevice/GraphicsPipelineState.hpp"


namespace jackal {


// OpenGL Graphics Pipeline State object. Use for the OpenGL rendering
// context.
class OpenGLGraphicsPipelineState : public GraphicsPipelineState {
public:
  OpenGLGraphicsPipelineState(JString name = JTEXT("Default-GraphicsPipeline"))
    : mProgramId(0)
    , dirty(false)
    , mNativeError(0)
    , GraphicsPipelineState(name) 
  {
    mProgramId = glCreateProgram(); 
  }

  void Bake(const GraphicsPipelineInfoT &info) override;
  void CleanUp() override;
  
  // Update the pipeline. This can be done with OpenGL, since it is
  // a dynamic pipeline, and we can only update that pipeline.
  void UpdateOGLPipeline();
;
  GLenum        GetNativeError() { return mNativeError; }
  GLenum        GetNativeTopology() { return mNativeTopology; }

  GLuint GetProgramId() { return mProgramId; }
  bool8 Dirty() { return dirty; }
  

private:

  static GLenum GetOpenGLBlendT(BlendT blend);
  static GLenum GetOpenGLTopology(TopologyT topology);

  // TODO(): Work on this later. Needs a definition.
  void RegisterNativeError();
  void CopyPipelineInfo(const GraphicsPipelineInfoT *info);
  void SetUpShaderPipeline(const GraphicsPipelineInfoT& info);

  // Program id of this pipeline state object.
  GLuint mProgramId;
  GLenum mNativeError;
  bool8 dirty;
  GLenum mNativeTopology;
};
} // jackal