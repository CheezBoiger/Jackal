// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLCommandBuffer.hpp"
#include "OpenGLComputePipelineState.hpp"
#include "OpenGLTextureCubeMap.hpp"
#include "OpenGLGraphicsPipelineState.hpp"
#include "OpenGLRenderPass.hpp"
#include "OpenGLFrameBuffer.hpp"
#include "OpenGLRenderTarget.hpp"
#include "OpenGLTexture.hpp"
#include "OpenGLTexture2D.hpp"
#include "OpenGLTexture3D.hpp"
#include "OpenGLTextureCubeMap.hpp"
#include "OpenGLMaterialLayout.hpp"
#include "OpenGLVertexBuffer.hpp"
#include "OpenGLUniformBuffer.hpp"

#define CHECK_RECORDING() if (!mRecording) return

namespace jackal {


void OpenGLCommandBuffer::Record()
{
  mRecording = true;
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

void OpenGLCommandBuffer::ClearColor(Color color)
{
  CHECK_RECORDING();

  auto execute = [=] (Color colorf) -> void {
    glClearColor(
      float(colorf.r) / 255.0f, 
      float(colorf.g) / 255.0f, 
      float(colorf.b) / 255.0f, 
      float(colorf.a) / 255.0f
    );
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(color); });
}


void OpenGLCommandBuffer::Clear()
{
  CHECK_RECORDING();

  auto execute = [=] () -> void {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(); });
}


void OpenGLCommandBuffer::BindGraphicsPipelineState(GraphicsPipelineState *pipeline)
{
  CHECK_RECORDING();
 
  auto execute = [=] (GraphicsPipelineState *pipe) -> void {
    OpenGLGraphicsPipelineState *oglPipe = 
      static_cast<OpenGLGraphicsPipelineState *>(pipe);  
    OpenGLDevice* renderDevice = 
      static_cast<OpenGLDevice* >(mOwner);
    
    // No need to update the pipeline, when it is already being used.
    if (oglPipe == renderDevice->mCurrentGraphicsPipelineState) return;

    renderDevice->mCurrentGraphicsPipelineState = oglPipe;
    renderDevice->mCurrentGraphicsPipelineState->UpdateOGLPipeline();
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(pipeline); });
}


void OpenGLCommandBuffer::BindVertexBuffer(VertexBuffer *vb)
{
  CHECK_RECORDING();

  auto execute = [=] (VertexBuffer *vertexbuffer) -> void {
    OpenGLDevice* renderDevice =
      static_cast<OpenGLDevice* >(mOwner);
    OpenGLVertexBuffer* oglBuffer = static_cast<OpenGLVertexBuffer*>(vertexbuffer);
    OpenGLGraphicsPipelineState* pipeline = renderDevice->mCurrentGraphicsPipelineState;

    renderDevice->mCurrentVertexBuffer = oglBuffer;

    // Null vertex buffer.
    if (!renderDevice->mCurrentVertexBuffer) {
      renderDevice->SubmitLastError(RENDER_ERROR_NULL_VERTEX_BUFFER);
      return;
    }

    glBindBuffer(GL_ARRAY_BUFFER, oglBuffer->vbo);    

    if (oglBuffer->ibo) {
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, oglBuffer->ibo);
    }
  };

  mNumRenderCalls += 2;
  mCommandList.push_back([=] () -> void { execute(vb); });
}


void OpenGLCommandBuffer::DrawElements(uint32 count)
{
  CHECK_RECORDING();

  auto execute = [=] (uint32 c) -> void {
    OpenGLDevice* renderDevice =
      static_cast<OpenGLDevice* >(mOwner);

    if (!renderDevice->mCurrentVertexBuffer) {
      renderDevice->SubmitLastError(RENDER_ERROR_NULL_VERTEX_BUFFER);
      return;
    }
    
    glDrawElements(renderDevice->mCurrentGraphicsPipelineState->
      GetNativeTopology(), c, GL_UNSIGNED_INT, nullptr);
  };
  ++mNumDrawCalls;
  mCommandList.push_back([=] () -> void { execute(count); });
}


void OpenGLCommandBuffer::Draw(uint32 count)
{
  CHECK_RECORDING();

  auto execute = [=] (uint32 c) -> void {
    OpenGLDevice* renderDevice =
      static_cast<OpenGLDevice* >(mOwner);

    if (!renderDevice->mCurrentVertexBuffer) {
      renderDevice->SubmitLastError(RENDER_ERROR_NULL_VERTEX_BUFFER);
      return;
    }
    glDrawArrays(renderDevice->mCurrentGraphicsPipelineState->
      GetNativeTopology(), 0, c);
  };
  ++mNumDrawCalls;
  mCommandList.push_back([=] () -> void { execute(count); });
}


void OpenGLCommandBuffer::SetViewPort(ViewPort *viewport)
{
  CHECK_RECORDING();

  auto execute = [=] (ViewPort *vp) -> void {
    OpenGLDevice* renderDevice =
      static_cast<OpenGLDevice* >(mOwner);

    if (!renderDevice->mCurrentGraphicsPipelineState) {
      renderDevice->SubmitLastError(RENDER_ERROR_NULL_GRAPHICS_PIPELINE_STATE);
      return;
    }
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
  CHECK_RECORDING();

  auto execute = [=] (ScissorRect *sr) -> void {
    OpenGLDevice* renderDevice =
      static_cast<OpenGLDevice* >(mOwner);

    if (!renderDevice->mCurrentGraphicsPipelineState) {
      renderDevice->SubmitLastError(RENDER_ERROR_NULL_GRAPHICS_PIPELINE_STATE);
      return;
    }
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
  CHECK_RECORDING();

  auto execute = [=] (uint32 c, uint32 i) -> void {
    OpenGLDevice* renderDevice =
      static_cast<OpenGLDevice* >(mOwner);

    if (!renderDevice->mCurrentGraphicsPipelineState) {
      renderDevice->SubmitLastError(RENDER_ERROR_NULL_GRAPHICS_PIPELINE_STATE);
      return;
    }
    glDrawElementsInstanced(renderDevice->mCurrentGraphicsPipelineState->GetNativeTopology(),
      c, GL_UNSIGNED_INT, nullptr, i);
  };

  ++mNumDrawCalls;
  mCommandList.push_back([=] () -> void { execute(count, instances); });
}


void OpenGLCommandBuffer::BeginRenderPass(RenderPass *pass)
{
  CHECK_RECORDING();

  auto execute = [=] (RenderPass* renderpass) -> void {
    OpenGLRenderPass* oglPass = static_cast<OpenGLRenderPass*>(renderpass);
    OpenGLDevice* device = static_cast<OpenGLDevice*>(mOwner);

    if (!renderpass) {
      return;
    }

    device->mCurrentRenderPass = oglPass;
    
    glBindFramebuffer(GL_FRAMEBUFFER, oglPass->FrameBufferHandle());
  };  

  mCommandList.push_back([=] () -> void { execute(pass); });
}


void OpenGLCommandBuffer::BindComputePipelineState(ComputePipelineState *compute)
{
  CHECK_RECORDING();
}


void OpenGLCommandBuffer::BindMaterialLayout(MaterialLayout *layout,
  uint32 dynamicOffsetCount, const uint32 *dynamicOffsets)
{
  CHECK_RECORDING();

  auto execute = [=] (MaterialLayout *ml, uint32 dyOffCnt, const uint32 *dynOff) -> void {
    // TODO(): We have our dynamic offsets and our material layout, we need to bind them 
    // to the pipeline now.
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(layout, dynamicOffsetCount, dynamicOffsets); });
}


void OpenGLCommandBuffer::SetDispatchCompute(uint32 x, uint32 y, uint32 z)
{
  CHECK_RECORDING();


}


void OpenGLCommandBuffer::SetDispatchIndirect(uint32 x, uint32 y, uint32 z)
{
  CHECK_RECORDING();


}


void OpenGLCommandBuffer::EndRenderPass()
{
  CHECK_RECORDING();
  auto execute = [=] () -> void {
    OpenGLDevice* device = static_cast<OpenGLDevice*>(mOwner);

    device->mCurrentRenderPass = nullptr;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(); });
}
} // jackal