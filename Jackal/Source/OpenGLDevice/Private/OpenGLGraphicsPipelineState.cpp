// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"


namespace jackal {


void OpenGLGraphicsPipelineState::SetPipelineState(const 
  GraphicsPipelineInfoT *info)
{
}


void OpenGLGraphicsPipelineState::Update()
{
  // No program id? Return with errors.
  if (!mProgramId) {
    mOpenGLLastError = OPENGL_ERROR_PIPELINE_NO_PROGRAM_ID;
    mLastError = RENDER_ERROR_PIPELINE_FAIL;
    return;
  }

  if (!dirty) return;

  // Set the depth test for the pipeline.
  if (mPipelineInfo.ZBufferEnable) {
    glEnable(GL_DEPTH_TEST);
  } else {
    glDisable(GL_DEPTH_TEST);
  }

  // Set the blend mode for the pipeline.
  if (mPipelineInfo.BlendEnable) {
    glEnable(GL_BLEND);
  } else {
    glDisable(GL_BLEND);
  }

  // Set Cull Face mode for the pipeline.
  if (mPipelineInfo.CullFaceEnable) {
    glEnable(GL_CULL_FACE);
    switch (mPipelineInfo.CullMode) {
      case CULL_MODE_BACK:            glCullFace(GL_BACK);            break;
      case CULL_MODE_FRONT:           glCullFace(GL_FRONT);           break;
      case CULL_MODE_FRONT_AND_BACK:  glCullFace(GL_FRONT_AND_BACK);  break;
      default:                        glCullFace(GL_BACK);            break;
    }
  
    switch (mPipelineInfo.FrontFace) {
      case FRONT_FACE_CLOCKWISE:          glFrontFace(GL_CW);   break;
      case FRONT_FACE_COUNTER_CLOCKWISE:  glFrontFace(GL_CCW);  break;
      default:                            glFrontFace(GL_CCW);  break;
    }
  } else {
    glDisable(GL_CULL_FACE);
  }
}
} // jackal