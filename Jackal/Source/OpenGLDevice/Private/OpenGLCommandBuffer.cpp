// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLDevice/OpenGLCommandBuffer.hpp"
#include "OpenGLDevice/OpenGLComputePipelineState.hpp"
#include "OpenGLDevice/OpenGLCubemap.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLFrameBuffer.hpp"
#include "OpenGLDevice/OpenGLRenderTarget.hpp"
#include "OpenGLDevice/OpenGLRenderTarget.hpp"
#include "OpenGLDevice/OpenGLTexture.hpp"
#include "OpenGLDevice/OpenGLVertexBuffer.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"


namespace jackal {


void OpenGLCommandBuffer::Record()
{
  mRecording = true;
  mNumDrawCalls = 0;
  mNumRenderCalls = 0;
}

void OpenGLCommandBuffer::EndRecord()
{
  mRecording = false;
}

void OpenGLCommandBuffer::ClearRecord()
{
  mCommandList.clear();
  mNumDrawCalls = 0;
  mNumRenderCalls = 0;
  mRecording = false;
}

void OpenGLCommandBuffer::ClearColor(Colorf color)
{
  auto execute = [=] (Colorf colorf) -> void {
    glClearColor(colorf.r, colorf.g, color.b, colorf.a);
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(color); });
}


void OpenGLCommandBuffer::Clear()
{
  auto execute = [=] () -> void {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(); });
}


void OpenGLCommandBuffer::BindGraphicsPipelineState(GraphicsPipelineState *pipeline)
{ 
  auto execute = [=] (GraphicsPipelineState *pipe) -> void {
    OpenGLGraphicsPipelineState *oglPipe = 
      static_cast<OpenGLGraphicsPipelineState *>(pipe);  
    
    // No need to update the pipeline, when it is already being used.
    if (oglPipe == mRenderDevice->mCurrentGraphicsPipelineState) return;

    mRenderDevice->mCurrentGraphicsPipelineState = oglPipe;
    mRenderDevice->mCurrentGraphicsPipelineState->UpdateOGLPipeline();
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(pipeline); });
}


void OpenGLCommandBuffer::BindVertexBuffer(VertexBuffer *vb)
{
  auto execute = [=] (VertexBuffer *vertexbuffer) -> void {
    mRenderDevice->mCurrentVertexBuffer = 
      static_cast<OpenGLVertexBuffer *>(vertexbuffer);

    // Null vertex buffer.
    if (!mRenderDevice->mCurrentVertexBuffer) {
      mRenderDevice->SubmitLastError(RENDER_ERROR_NULL_VERTEX_BUFFER);
      return;
    }

    glBindVertexArray(mRenderDevice->mCurrentVertexBuffer->vao);
    
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(vb); });
}
} // jackal