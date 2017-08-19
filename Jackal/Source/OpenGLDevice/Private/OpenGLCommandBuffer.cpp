// Copyright (c) 2017 Jackal Engine, MIT License.

#include "OpenGLDevice/OpenGLCommandBuffer.hpp"
#include "OpenGLDevice/OpenGLComputePipelineState.hpp"
#include "OpenGLDevice/OpenGLTextureCubeMap.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLFrameBuffer.hpp"
#include "OpenGLDevice/OpenGLRenderTarget.hpp"
#include "OpenGLDevice/OpenGLTexture.hpp"
#include "OpenGLDevice/OpenGLVertexBuffer.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"


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

    // TODO(): Bind the buffer according to the layout provided by the graphics pipeline state.
    VertexBindingInfoT& vinfo = pipeline->GetPipelineInformation()->VertexBindingInfo;

    for (uint32 i = 0; i < vinfo.VertexAttributesCount; ++i) {
      VertexAttributeT& attribute = vinfo.VertexAttribute[i];
      uint32 size = 0;
      switch (attribute.Format) {
        case FORMAT_R8G8B8A8_SINT:
        case FORMAT_R16G16B16A16_SFLOAT:
        case FORMAT_R32G32B32A32_SFLOAT: size = 4; break;

        case FORMAT_R32G32B32_SFLOAT: size = 3; break;

        case FORMAT_R32G32_SFLOAT:   size = 2; break;

        case FORMAT_R32_SFLOAT: size = 1; break;

        default: size = 3; break;
      }

      glEnableVertexAttribArray(attribute.Location);
      glVertexAttribPointer(attribute.Location, size, GL_FLOAT, GL_FALSE, vinfo.Stride, 
        (GLvoid*)&attribute.Offset); 
    } 
  };

  mNumRenderCalls += 2;
  mCommandList.push_back([=] () -> void { execute(vb); });
}


void OpenGLCommandBuffer::DrawElements(uint32 count)
{
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
}


void OpenGLCommandBuffer::BindComputePipelineState(ComputePipelineState *compute)
{
}


void OpenGLCommandBuffer::BindMaterialLayout(MaterialLayout *layout,
  uint32 dynamicOffsetCount, const uint32 *dynamicOffsets)
{
  auto execute = [=] (MaterialLayout *ml, uint32 dyOffCnt, const uint32 *dynOff) -> void {
    // TODO(): We have our dynamic offsets and our material layout, we need to bind them 
    // to the pipeline now.
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(layout, dynamicOffsetCount, dynamicOffsets); });
}


void OpenGLCommandBuffer::SetDispatchCompute(uint32 x, uint32 y, uint32 z)
{
}


void OpenGLCommandBuffer::SetDispatchIndirect(uint32 x, uint32 y, uint32 z)
{
}
} // jackal