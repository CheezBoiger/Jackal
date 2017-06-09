// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

namespace jkl {

class Shader;
class RenderPass;
class RenderTarget;
class FrameBuffer;
class VertexBuffer;
class Texture;
class UniformBuffer;
class GraphicsPipelineState;
class ComputePipelineState;
class CommandList;
class CommandBuffer;

// RenderDevice interface, used for the rendering system of the 
// Jackal Game Engine. This is the Rendering Hardware Interface used
// for enabling Graphics for various Rendering APIs such as Vulkan, OpenGL,
// DirectX, and possibly even our own implementation.
class RenderDevice {
public:
  enum Type {
    rOpenGL,
    rVulkan,
    rMetal,
    rDirectX12,
    rNone
  };

protected:
  RenderDevice(Type type) : api(type) { }

public:
  virtual ~RenderDevice() { }

  virtual Shader *CreateShader() = 0;
  virtual FrameBuffer *CreateFrameBuffer() = 0;
  virtual RenderPass *CreateRenderPass() = 0;
  virtual Texture *CreateTexture() = 0;  
  virtual UniformBuffer *CreateUniformBuffer() = 0;
  virtual GraphicsPipelineState *CreateGraphicsPipelineState() = 0;
  virtual ComputePipelineState *CreateComputePipelineState() = 0;
  virtual RenderTarget *CreateRenderTarget() = 0;
  virtual VertexBuffer *CreateVertexBuffer() = 0;
  virtual CommandBuffer *CreateCommandBuffer() = 0;
  virtual CommandList *CreateCommandList() = 0;

  // Still Ongoing work.
  // TODO(): Setters for setting up the pipeline and rendering core.

  // Submit command buffers to the GPU for rendering. If OpenGL is being used, 
  // we go with CPU based rendering calls.
  virtual void SubmitCommandBuffers(CommandBuffer *commandbuffers) = 0;

  virtual const tchar *RenderAPIString() = 0;
  
  Type RenderAPI() { return api; }
private:
  Type api;
};
} // jkl