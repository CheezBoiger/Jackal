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

  void SetPipelineState(const GraphicsPipelineInfoT *info) override;
  
  // Update the pipeline.
  void Update() override;
  GLenum        GetNativeError() { return mNativeError; }
private:

  static GLenum GetOpenGLBlendT(BlendT blend);

  // TODO(): Work on this later. Needs a definition.
  void RegisterNativeError();
  void CopyPipelineInfo(const GraphicsPipelineInfoT *info);
  void SetUpShaderPipeline();

  // Program id of this pipeline state object.
  GLuint mProgramId;
  GLenum mNativeError;
  bool8 dirty;
};
} // jackal