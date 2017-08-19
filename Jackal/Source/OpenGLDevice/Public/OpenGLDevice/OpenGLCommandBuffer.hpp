// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "RenderDevice/CommandBuffer.hpp"
#include "OpenGLDevice.hpp"

#include <list>
#include <functional>


namespace jackal {


typedef std::function<void()> OGLCommandFunction;


// CommandBuffer for OpenGL, this holds all render commands into
// a buffer for use in the RenderDevice for OpenGL. Since OpenGL is 
// Dynamic, it must be read from the cpu to the gpu. Draw calls can
// be easily monitored this way however.
class OpenGLCommandBuffer : public CommandBuffer {
public:
  OpenGLCommandBuffer() { }
  
  void Record() override;
  void EndRecord() override;

  void ClearRecord() override;
  void Clear() override;
  void ClearColor(Colorf color) override;
  void DrawElements(uint32 count) override;
  void Draw(uint32 count) override;
  void DrawInstanced(uint32 count, uint32 instances) override;
  void BindVertexBuffer(VertexBuffer *vb) override;
  void BeginRenderPass(RenderPass *pass) override;
  void BindGraphicsPipelineState(GraphicsPipelineState *pipeline) override;
  void BindComputePipelineState(ComputePipelineState *pipeline) override;
  void BindMaterialLayout(MaterialLayout *layout, 
    uint32 dynamicOffsetCount = 0, const uint32 *dynamicOffsets = nullptr) override;
  void SetViewPort(ViewPort *viewport) override;  
  void SetScissor(ScissorRect *scissor) override;
  void SetDispatchCompute(uint32 x, uint32 y, uint32 z) override;
  void SetDispatchIndirect(uint32 x, uint32 y, uint32 z) override;

  std::list<OGLCommandFunction> &GetNativeCommandList() { return mCommandList; }

private:
  std::list<OGLCommandFunction>           mCommandList;
};
} // jackal