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
    , mOpenGLLastError(OPENGL_ERROR_NONE)
    , mNativeError(0)
    , GraphicsPipelineState(name) 
  {
    mProgramId = glCreateProgram(); 
  }

  void SetPipelineState(const GraphicsPipelineInfoT *info) override;
  
  // Update the pipeline.
  void Update() override;

  OpenGLErrorT  GetOpenGLLastError() { return mOpenGLLastError; }
  GLenum        GetNativeError() { return mNativeError; }
private:

  // Program id of this pipeline state object.
  GLuint mProgramId;
  OpenGLErrorT mOpenGLLastError;
  GLenum mNativeError;
  bool8 dirty;
};
} // jackal