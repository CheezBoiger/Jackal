// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once
#include "Core/Platform/JTypes.hpp"
#include "ViewPort.hpp"

#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"

#include "Core/Math/Vector4.hpp"
#include "Core/Math/Color4.hpp"


namespace jackal {


class VertexBuffer;
class GraphicsPipelineState;
class ComputePipelineState;
class RenderPass;
class UniformBuffer;
class RenderDevice;
class MaterialLayout;


struct RenderPassBeginInfoT {
  RenderPass*     pRenderPass;
  
};


// CommandBuffer is an object that records all commands for use in rendering.
// Once done recording, it will be sent over to the GPU for rendering.
class CommandBuffer : public RenderObject {
public:
  CommandBuffer()
    : mNumRenderCalls(0)
    , mNumDrawCalls(0)
    , mRecording(false) { }

  virtual ~CommandBuffer() { }

  virtual void Record() = 0;
  virtual void EndRecord() = 0;
  virtual void ClearRecord() = 0;

  virtual void Clear() = 0;
  virtual void ClearColor(Color color) = 0;
  virtual void DrawElements(uint32 count) = 0;
  virtual void Draw(uint32 count) = 0;
  virtual void DrawInstanced(uint32 count, uint32 instances) = 0;
  virtual void BindVertexBuffer(VertexBuffer *vb) = 0;
  virtual void BeginRenderPass(RenderPass *pass) = 0;
  virtual void BindGraphicsPipelineState(GraphicsPipelineState *pipeline) = 0;
  virtual void BindComputePipelineState(ComputePipelineState *pipeline) = 0;
  virtual void EndRenderPass() = 0;

  // Even if we already bound the graphics pipeline state to this material layout,
  // We still call this function in order to bind and update the current state of the
  // Material data inside. If not, we stick with the same data as previous, so be sure
  // to call the material layout for each mesh call.
  virtual void BindMaterialLayout(MaterialLayout *layout, 
    uint32 dynamicOffsetCount = 0, const uint32 *dynamicOffsets = nullptr) = 0;
  virtual void SetViewPort(ViewPort *viewport) = 0;
  virtual void SetScissor(ScissorRect *scissor) = 0;

  // For Compute Pipeline binding. Used to dispatch our threading in the compute
  // shader.
  virtual void SetDispatchCompute(uint32 x, uint32 y, uint32 z) = 0;
  virtual void SetDispatchIndirect(uint32 x, uint32 y, uint32 z) = 0;

  bool8         Recording() const { return mRecording; }
  uint32        NumberOfDrawCalls() const { return mNumDrawCalls; }
  uint32        NumberOfRenderCalls() const { return mNumRenderCalls; }

protected:
  bool8         mRecording;
  uint32        mNumRenderCalls;
  uint32        mNumDrawCalls;
};
} // jackal