// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once
#include "Core/Platform/JTypes.hpp"
#include "ViewPort.hpp"

#include "RenderDeviceTypes.hpp"
#include "Core/Math/Vector4.hpp"


namespace jackal {


class VertexBuffer;
class GraphicsPipelineState;
class ComputePipelineState;
class RenderPass;
class UniformBuffer;
class RenderDevice;


// CommandBuffer is an object that records all commands for use in rendering.
// Once done recording, it will be sent over to the GPU for rendering.
class CommandBuffer {
public:
  virtual ~CommandBuffer() { }

  virtual void Record() = 0;
  virtual void EndRecord() = 0;
  virtual void ClearRecord() = 0;
  virtual void Clear() = 0;
  virtual void ClearColor(Colorf color) = 0;
  virtual void DrawElements(uint32 count) = 0;
  virtual void Draw(uint32 count) = 0;
  virtual void DrawInstanced(uint32 count, uint32 instances) = 0;
  virtual void BindVertexBuffer(VertexBuffer *vb) = 0;
  virtual void BeginRenderPass(RenderPass *pass) = 0;
  virtual void BindGraphicsPipelineState(GraphicsPipelineState *pipeline) = 0;
  virtual void BindComputePipelineState(ComputePipelineState *pipeline) = 0;
  virtual void BindUniformBuffer(UniformBuffer *ub) = 0;
  virtual void SetViewPort(ViewPort *viewport) = 0;
  virtual void SetScissor(ScissorRect *scissor) = 0;
  virtual void SetDispatchCompute(uint32 x, uint32 y, uint32 z) = 0;

  bool8         Recording() const { return mRecording; }
  uint32        NumberOfDrawCalls() const { return mNumDrawCalls; }
  uint32        NumberOfRenderCalls() const { return mNumRenderCalls; }
  
  virtual RenderDevice *GetRenderDevice() = 0;  

protected:
  bool8         mRecording;
  uint32        mNumRenderCalls;
  uint32        mNumDrawCalls;
};
} // jackal