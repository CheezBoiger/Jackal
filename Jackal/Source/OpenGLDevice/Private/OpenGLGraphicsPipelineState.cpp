// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLShader.hpp"

// Registers an opengl error.
#define REGISTER_OPENGL_ERROR() OPENGL_CHECK_ERROR(mNativeError); \
  if (mNativeError) { \
    RegisterNativeError(); \
    return; \
  }


namespace jackal {


GLenum OpenGLGraphicsPipelineState::GetOpenGLBlendT(BlendT blend)
{
  switch (blend) {
      case BLEND_ZERO: return GL_NEVER;
      case BLEND_ONE: return GL_ONE;
      case BLEND_SRC_COLOR: return GL_SRC_COLOR;
      case BLEND_ONE_MINUS_SRC_COLOR: return GL_ONE_MINUS_SRC_COLOR;
      case BLEND_DST_COLOR: return GL_DST_COLOR;
      case BLEND_ONE_MINUS_DST_COLOR: return GL_ONE_MINUS_DST_COLOR;
      case BLEND_SRC_ALPHA: return GL_SRC_ALPHA;
      case BLEND_ONE_MINUS_SRC_ALPHA: return GL_ONE_MINUS_SRC_ALPHA;
      case BLEND_DST_ALPHA: return GL_DST_ALPHA;
      case BLEND_ONE_MINUS_DST_ALPHA: return GL_ONE_MINUS_DST_ALPHA;
      case BLEND_CONSTANT_COLOR: return GL_CONSTANT_COLOR;
      case BLEND_ONE_MINUS_CONSTANT_COLOR: return GL_ONE_MINUS_CONSTANT_COLOR;
      case BLEND_CONSTANT_ALPHA: return GL_CONSTANT_ALPHA;
      case BLEND_ONE_MINUS_CONSTANT_ALPHA: return GL_ONE_MINUS_CONSTANT_ALPHA;
      case BLEND_SRC_ALPHA_SATURATE: return GL_SRC_ALPHA_SATURATE;
      case BLEND_SRC1_COLOR: return GL_SRC1_COLOR;
      case BLEND_ONE_MINUS_SRC1_COLOR: return GL_ONE_MINUS_SRC1_COLOR;
      case BLEND_SRC1_ALPHA: return GL_SRC1_ALPHA;
      case BLEND_ONE_MINUS_SRC1_ALPHA: return GL_ONE_MINUS_SRC1_ALPHA;
      default: return GL_NEVER;
  }
}


void OpenGLGraphicsPipelineState::SetPipelineState(const 
  GraphicsPipelineInfoT *info)
{
  CopyPipelineInfo(info);
}


void OpenGLGraphicsPipelineState::Update()
{
  SetUpShaderPipeline();

  // No program id? Return with errors.
  if (!mProgramId) {
    return;
  }

  if (!dirty) return;

  // Set the depth test for the pipeline.
  if (mPipelineInfo.ZBufferEnable) {
    glEnable(GL_DEPTH_TEST);
    switch (mPipelineInfo.DepthTestCompare) {
      case COMPARE_NEVER: glDepthFunc(GL_NEVER);
      case COMPARE_LESS: glDepthFunc(GL_LESS);
      case COMPARE_EQUAL: glDepthFunc(GL_EQUAL);
      case COMPARE_LESS_OR_EQUAL: glDepthFunc(GL_LEQUAL);
      case COMPARE_GREATER: glDepthFunc(GL_GREATER);
      case COMPARE_NOT_EQUAL: glDepthFunc(GL_NOTEQUAL);
      case COMPARE_GREATER_OR_EQUAL: glDepthFunc(GL_GEQUAL);
      case COMPARE_ALWAYS: glDepthFunc(GL_ALWAYS);
      default: glDepthFunc(GL_LESS);
    }
    REGISTER_OPENGL_ERROR();

  } else {
    glDisable(GL_DEPTH_TEST);
  }

  // Set the blend mode for the pipeline.
  if (mPipelineInfo.BlendEnable) {
    glEnable(GL_BLEND);
    switch (mPipelineInfo.BlendOp) {
      case BLEND_OPERATION_ADD: glBlendEquation(GL_FUNC_ADD); break;
      case BLEND_OPERATION_SUBTRACT: glBlendEquation(GL_FUNC_SUBTRACT); break;
      case BLEND_OPERATION_REVERSE_SUBTRACT: glBlendEquation(GL_FUNC_REVERSE_SUBTRACT); break;
      case BLEND_OPERATION_MIN: glBlendEquation(GL_MIN); break;
      case BLEND_OPERATION_MAX: glBlendEquation(GL_MAX); break;
      default: glBlendEquation(GL_FUNC_ADD); break;
    }
    
    REGISTER_OPENGL_ERROR();

    glBlendFunc(
      GetOpenGLBlendT(mPipelineInfo.SrcBlendMode),
      GetOpenGLBlendT(mPipelineInfo.DstBlendMode)
    );
    
    REGISTER_OPENGL_ERROR();

    if (mNativeError) {
      RegisterNativeError();
      return;  
    }

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
    
    REGISTER_OPENGL_ERROR();
    
    if (mNativeError) {
      RegisterNativeError();
      return;
    }

    switch (mPipelineInfo.FrontFace) {
      case FRONT_FACE_CLOCKWISE:          glFrontFace(GL_CW);   break;
      case FRONT_FACE_COUNTER_CLOCKWISE:  glFrontFace(GL_CCW);  break;
      default:                            glFrontFace(GL_CCW);  break;
    }

    REGISTER_OPENGL_ERROR();

    if (mNativeError) {
      RegisterNativeError();
      return;
    }
  } else {
    glDisable(GL_CULL_FACE);
  }


  if (mPipelineInfo.StencilEnable) {
    glEnable(GL_STENCIL);
  } else {
    glDisable(GL_STENCIL);
  }
}


void OpenGLGraphicsPipelineState::SetUpShaderPipeline()
{
  if (mProgramId) {
    glDeleteProgram(mProgramId);
    mProgramId = glCreateProgram();
  }

  if (!mPipelineInfo.VertexShader) {
    mLastError = RENDER_ERROR_PIPELINE_NULL_VERTEX_SHADER;
    return;
  }

  if (!mPipelineInfo.PixelShader) {
    mLastError = RENDER_ERROR_PIPELINE_NULL_PIXEL_SHADER;
  }

  OpenGLShader *shader = static_cast<OpenGLShader *>(mPipelineInfo.VertexShader);
  if (shader->Compiled()) {
    glAttachShader(mProgramId, shader->GetUID());
  }

  shader = static_cast<OpenGLShader *>(mPipelineInfo.PixelShader);
  if (shader->Compiled()) {
    glAttachShader(mProgramId, shader->GetUID());
  }

  if (mPipelineInfo.HullShader) {
    shader = static_cast<OpenGLShader *>(mPipelineInfo.HullShader);
    if (shader->Compiled()) {
      glAttachShader(mProgramId, shader->GetUID());
    }
  }

  if (mPipelineInfo.DomainShader) {
    shader = static_cast<OpenGLShader *>(mPipelineInfo.DomainShader);
    if (shader->Compiled()) {
      glAttachShader(mProgramId, shader->GetUID());
    }
  }

  if (mPipelineInfo.GeometryShader) {
    shader = static_cast<OpenGLShader *>(mPipelineInfo.GeometryShader);
    if (shader->Compiled()) {
      glAttachShader(mProgramId, shader->GetUID());
    }
  }

  // Link the program now.
  glLinkProgram(mProgramId);

  // Time to check its state.
  GLint success;
  glGetProgramiv(mProgramId, GL_LINK_STATUS, &success);
  if (!success) {
    mLastError = RENDER_ERROR_PIPELINE_SHADER_LINK_ERROR;
    glDeleteProgram(mProgramId);
    mProgramId = 0;
    return;
  }
}

#define CHANGE_PIPELINE(cmp1, cmp2) if (cmp1 != cmp2) dirty = true; \
  cmp1 = cmp2;

void OpenGLGraphicsPipelineState::CopyPipelineInfo(const GraphicsPipelineInfoT *info)
{
  CHANGE_PIPELINE(mPipelineInfo.BlendEnable, info->BlendEnable);
  CHANGE_PIPELINE(mPipelineInfo.BlendEnable, info->BlendEnable);
  CHANGE_PIPELINE(mPipelineInfo.BlendOp, info->BlendOp);
  CHANGE_PIPELINE(mPipelineInfo.CullFaceEnable, info->CullFaceEnable);
  CHANGE_PIPELINE(mPipelineInfo.CullMode, info->CullMode);
  CHANGE_PIPELINE(mPipelineInfo.DepthTestCompare, info->DepthTestCompare);
  CHANGE_PIPELINE(mPipelineInfo.DstBlendMode, info->DstBlendMode);
  CHANGE_PIPELINE(mPipelineInfo.SrcBlendMode, info->SrcBlendMode);
  CHANGE_PIPELINE(mPipelineInfo.FrontFace, info->FrontFace);
  CHANGE_PIPELINE(mPipelineInfo.ZBufferEnable, info->ZBufferEnable);
  CHANGE_PIPELINE(mPipelineInfo.StencilEnable, info->StencilEnable);
  
  CHANGE_PIPELINE(mPipelineInfo.VertexShader, info->VertexShader);
  CHANGE_PIPELINE(mPipelineInfo.PixelShader, info->PixelShader);
  CHANGE_PIPELINE(mPipelineInfo.HullShader, info->HullShader);
  CHANGE_PIPELINE(mPipelineInfo.DomainShader, info->DomainShader);
  CHANGE_PIPELINE(mPipelineInfo.GeometryShader, info->GeometryShader);
}


void OpenGLGraphicsPipelineState::RegisterNativeError()
{
  // TODO(): Do something here!! Need to register native errors.
}
} // jackal