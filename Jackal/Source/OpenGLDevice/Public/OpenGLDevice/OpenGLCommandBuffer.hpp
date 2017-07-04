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
  OpenGLCommandBuffer(OpenGLDevice *device) 
    : mRenderDevice(device) { }
  
  void Record() override;
  void EndRecord() override;

  void ClearRecord() override;
  void Clear() override;
  void ClearColor(Colorf color) override;
  void DrawElements(uint32 count) override;
  void DrawInstanced(uint32 count, uint32 instances) override;
  void BindVertexBuffer(const VertexBuffer *vb) override;
  void BeginRenderPass(const RenderPass *pass) override;
  void BindGraphicsPipelineState(const GraphicsPipelineState *pipeline) override;
  void BindComputePipelineState(const ComputePipelineState *pipeline) override;
  void BindUniformBuffer(const UniformBuffer *ub) override;
  void SetViewPort(ViewPort *viewport) override;  
  void SetScissor(ScissorRect *scissor) override;
  void SetDispatchCompute(uint32 x, uint32 y, uint32 z) override;

  RenderDevice *GetRenderDevice() override { return mRenderDevice; }

private:

  OpenGLDevice                           *mRenderDevice;
  std::list<OGLCommandFunction>           mCommandList;
};
} // jackal