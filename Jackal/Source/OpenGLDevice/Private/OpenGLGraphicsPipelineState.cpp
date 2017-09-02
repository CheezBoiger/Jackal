// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLGraphicsPipelineState.hpp"
#include "OpenGLShader.hpp"

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


GLenum OpenGLGraphicsPipelineState::GetOpenGLTopology(TopologyT topology)
{
  switch (topology) {
    case TOPOLOGY_POINT_LIST: return GL_POINTS;
    case TOPOLOGY_LINE_LIST: return GL_LINES;
    case TOPOLOGY_LINE_STRIP: return GL_LINE_STRIP;
    case TOPOLOGY_TRIANGLE_LIST: return GL_TRIANGLES;
    case TOPOLOGY_TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
    case TOPOLOGY_TRIANGLE_FAN: return GL_TRIANGLE_FAN;
    case TOPOLOGY_LINE_LIST_WITH_ADJACENCY: return GL_LINES_ADJACENCY;
    case TOPOLOGY_LINE_STRIP_WITH_ADJACENCY: return GL_LINE_STRIP_ADJACENCY;
    case TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY: return GL_TRIANGLES_ADJACENCY;
    case TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY: return GL_TRIANGLE_STRIP_ADJACENCY;
    default: return GL_TRIANGLES;
  }
}


void OpenGLGraphicsPipelineState::Bake(const 
  GraphicsPipelineInfoT &info)
{
  mPipelineInfo.VertexBindingInfo.VertexAttribute = nullptr;
  mPipelineInfo.VertexBindingInfo.VertexAttributesCount = 0;
  CopyPipelineInfo(&info);
  SetUpShaderPipeline(info);
  mNativeTopology = GetOpenGLTopology(mPipelineInfo.Topology);
}


void OpenGLGraphicsPipelineState::UpdateOGLPipeline()
{
  // No program id? Return with errors.
  if (!mProgramId) {
    return;
  }

  // Use the program.
  glUseProgram(mProgramId);

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

  // TODO(): Bind the buffer according to the layout provided by the graphics pipeline state.
  VertexBindingInfoT& vinfo = mPipelineInfo.VertexBindingInfo;

  for (uint32 i = 0; i < vinfo.VertexAttributesCount; ++i) {
    VertexAttributeT& attribute = vinfo.VertexAttribute[i];
    uint32 size = 0;
    GLenum type = GL_FLOAT;

    switch (attribute.Format) {
      case FORMAT_R8G8B8A8_SINT:
      {
        size = 4;
        type = GL_INT;
      } break;
      case FORMAT_R16G16B16A16_SFLOAT:
      case FORMAT_R32G32B32A32_SFLOAT: 
      {
        size = 4;
        type = GL_FLOAT; 
      } break;
      case FORMAT_R32G32B32_SFLOAT: 
      {
        size = 3;
        type = GL_FLOAT; 
      } break;
      case FORMAT_R32G32_SFLOAT:   
      {
        size = 2;
        type = GL_FLOAT; 
      } break;
      case FORMAT_R32_SFLOAT: 
      {
        size = 1;
        type = GL_FLOAT; 
      } break;
      default: 
      {
        size = 3;
        type = GL_FLOAT; 
      } break;
    }

    glEnableVertexAttribArray(attribute.Location);
    glVertexAttribPointer(attribute.Location, size, type, GL_FALSE, vinfo.Stride,
      (GLvoid*)&attribute.Offset);
  }
 
  REGISTER_OPENGL_ERROR();

  dirty = false;
}


void OpenGLGraphicsPipelineState::SetUpShaderPipeline(const GraphicsPipelineInfoT& info)
{
  if (mProgramId) {
    glDeleteProgram(mProgramId);
    mProgramId = glCreateProgram();
  }

  if (!info.VertexShader) {
    mLastError = RENDER_ERROR_PIPELINE_NULL_VERTEX_SHADER;
    return;
  }

  if (!info.PixelShader) {
    mLastError = RENDER_ERROR_PIPELINE_NULL_PIXEL_SHADER;
    return;
  }

  OpenGLShader *shader = static_cast<OpenGLShader *>(info.VertexShader);
  if (shader->Compiled()) {
    glAttachShader(mProgramId, shader->Handle());
  } else {
    mLastError = RENDER_ERROR_PIPELINE_UNCOMPILED_SHADER;
    return;
  }

  shader = static_cast<OpenGLShader *>(info.PixelShader);
  if (shader->Compiled()) {
    glAttachShader(mProgramId, shader->Handle());
  } else {
    mLastError = RENDER_ERROR_PIPELINE_UNCOMPILED_SHADER;
    return;
  }

  if (info.HullShader) {
    shader = static_cast<OpenGLShader *>(info.HullShader);
    if (shader->Compiled()) {
      glAttachShader(mProgramId, shader->Handle());
    } else {
      mLastError = RENDER_ERROR_PIPELINE_UNCOMPILED_SHADER;
      return;
    }
  }

  if (info.DomainShader) {
    shader = static_cast<OpenGLShader *>(info.DomainShader);
    if (shader->Compiled()) {
      glAttachShader(mProgramId, shader->Handle());
    } else {
      mLastError = RENDER_ERROR_PIPELINE_UNCOMPILED_SHADER;
      return;
    }
  }

  if (info.GeometryShader) {
    shader = static_cast<OpenGLShader *>(info.GeometryShader);
    if (shader->Compiled()) {
      glAttachShader(mProgramId, shader->Handle());
    } else {
      mLastError = RENDER_ERROR_PIPELINE_UNCOMPILED_SHADER; 
      return;
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
  CHANGE_PIPELINE(mPipelineInfo.Topology, info->Topology);

  // TODO(): Need to update the vertex attributes in order for this opengl pipeline
  // to know what that is.
  if (!info->VertexBindingInfo.VertexAttributesCount) return;

  VertexAttributeT* attributes = info->VertexBindingInfo.VertexAttribute;
  if (mPipelineInfo.VertexBindingInfo.VertexAttribute) {
    delete[] mPipelineInfo.VertexBindingInfo.VertexAttribute;
  }

  mPipelineInfo.VertexBindingInfo.VertexAttributesCount = info->VertexBindingInfo.VertexAttributesCount;
  
  mPipelineInfo.VertexBindingInfo.VertexAttribute = 
    new VertexAttributeT[mPipelineInfo.VertexBindingInfo.VertexAttributesCount];

  // Copy values into this pipeline info.
  for (uint32 i = 0; i < info->VertexBindingInfo.VertexAttributesCount; ++i) {
    VertexAttributeT& attribute = attributes[i];
    VertexAttributeT& copyAttrib = mPipelineInfo.VertexBindingInfo.VertexAttribute[i];
    copyAttrib.Binding = attribute.Binding;
    copyAttrib.Format = attribute.Format;
    copyAttrib.Location = attribute.Location;
    copyAttrib.Offset = attribute.Offset;
  }
}


void OpenGLGraphicsPipelineState::CleanUp()
{
  if (mProgramId) {
    glDeleteProgram(mProgramId);
    mProgramId = 0;
  }

  if (mPipelineInfo.VertexBindingInfo.VertexAttributesCount) { 
    delete[] mPipelineInfo.VertexBindingInfo.VertexAttribute;
  }
}


void OpenGLGraphicsPipelineState::RegisterNativeError()
{
  // TODO(): Do something here!! Need to register native errors.
}
} // jackal