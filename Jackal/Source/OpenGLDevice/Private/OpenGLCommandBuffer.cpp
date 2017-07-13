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


void OpenGLCommandBuffer::DrawElements(uint32 count)
{
  auto execute = [=] (uint32 c) -> void {

    if (!mRenderDevice->mCurrentVertexBuffer) {
      mRenderDevice->SubmitLastError(RENDER_ERROR_NULL_VERTEX_BUFFER);
      return;
    }

    glDrawElements(mRenderDevice->mCurrentGraphicsPipelineState->
      GetNativeTopology(), c, GL_UNSIGNED_INT, nullptr);
  };
  ++mNumDrawCalls;
  mCommandList.push_back([=] () -> void { execute(count); });
}


void OpenGLCommandBuffer::Draw(uint32 count)
{
  auto execute = [=] (uint32 c) -> void {
    if (!mRenderDevice->mCurrentVertexBuffer) {
      mRenderDevice->SubmitLastError(RENDER_ERROR_NULL_VERTEX_BUFFER);
      return;
    }
    glDrawArrays(mRenderDevice->mCurrentGraphicsPipelineState->
      GetNativeTopology(), 0, c);
  };
  ++mNumDrawCalls;
  mCommandList.push_back([=] () -> void { execute(count); });
}


void OpenGLCommandBuffer::SetViewPort(ViewPort *viewport)
{
  auto execute = [=] (ViewPort *vp) -> void {
    glViewport( 
      static_cast<GLint>(vp->X),
      static_cast<GLint>(vp->Y),
      static_cast<GLsizei>(vp->Width),
      static_cast<GLsizei>(vp->Height)
    );
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(viewport); });
}


void OpenGLCommandBuffer::SetScissor(ScissorRect *scissor)
{
  auto execute = [=] (ScissorRect *sr) -> void {
    glScissor(sr->Offset.x,
              sr->Offset.y,
              sr->Extent.Width,
              sr->Extent.Height
    );
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(scissor); });
}


void OpenGLCommandBuffer::DrawInstanced(uint32 count, uint32 instances)
{
}


void OpenGLCommandBuffer::BeginRenderPass(RenderPass *pass)
{
}


void OpenGLCommandBuffer::BindComputePipelineState(ComputePipelineState *compute)
{
}


void OpenGLCommandBuffer::BindMaterialLayout(MaterialLayout *layout)
{
}


void OpenGLCommandBuffer::SetDispatchCompute(uint32 x, uint32 y, uint32 z)
{
}
} // jackal