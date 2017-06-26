// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once
#include "Core/Platform/JTypes.hpp"
#include "ViewPort.hpp"

namespace jackal {


class VertexBuffer;
class GraphicsPipelineState;
class ComputePipelineState;
class RenderPass;
class Material;


// CommandBuffer is an object that records all commands for use in rendering.
// Once done recording, it will be cool.
class CommandBuffer {
public:
  virtual ~CommandBuffer() { }

  virtual void Record() = 0;
  virtual void EndRecord() = 0;
  virtual void DrawElements(uint32 count) = 0;
  virtual void BindVertexBuffer(const VertexBuffer *vb) = 0;
  virtual void BeginRenderPass(const RenderPass *pass) = 0;
  virtual void BindGraphicsPipelineState(const GraphicsPipelineState *pipeline) = 0;
  virtual void BindComputePipelineState(const ComputePipelineState *pipeline) = 0;
  virtual void BindMaterial(const Material *material) = 0;
  virtual void SetViewPort(ViewPort *viewport) = 0;
  virtual void SetScissor(ScissorRect *scissor) = 0;

  bool8 IsRecording() { return recording; }

protected:
  bool8 recording;
};
} // jackal