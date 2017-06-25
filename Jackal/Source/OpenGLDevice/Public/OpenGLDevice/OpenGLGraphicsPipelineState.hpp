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
    : GraphicsPipelineState(name) { }

  void SetPipelineState(const GraphicsPipelineInfoT *info) override;
  
  // Update the pipeline.
  void Update() override;

  // Checks if this pipeline state is dirty.
  bool8 Dirty() override { return dirty; }

private:

  // Program id of this pipeline state object.
  GLuint mProgramId;

  bool8 dirty;
};
} // jackal