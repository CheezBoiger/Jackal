// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

namespace jackal {

class Shader;
class RenderPass;
class RenderTarget;
class FrameBuffer;
class VertexBuffer;
class Texture;
class UniformBuffer;
class GraphicsPipelineState;
class ComputePipelineState;
class CommandBuffer;
class Material;
class Resources;


// RenderDevice error types.
typedef enum {
  RENDER_DEVICE_NONE,
  RENDER_DEVICE_BAD_MEMORY_STRUCTURE_ALLOC,
  RENDER_DEVICE_BAD_TEXTURE_ALLOC,
  RENDER_DEVICE_BAD_RENDER_TARGET_ALLOC,
  RENDER_DEVICE_BAD_RENDER_PASS_ALLOC,
  RENDER_DEVICE_BAD_FRAMEBUFFER_ALLOC,
  RENDER_DEVICE_BAD_UNIFORM_BUFFER_ALLOC,
  RENDER_DEVICE_BAD_GRAPHICS_PIPELINE_STATE_ALLOC,
  RENDER_DEVICE_BAD_COMPUTE_PIPELINE_STATE_ALLOC,
  RENDER_DEVICE_BAD_SHADER_ALLOC,
  RENDER_DEVICE_BAD_VERTEX_BUFFER_ALLOC,
  RENDER_DEVICE_BAD_COMMAND_BUFFER_ALLOC,
} RenderDeviceErrorT;

// RenderDevice interface, used for the rendering system of the 
// Jackal Game Engine. This is the Rendering Hardware Interface used
// for enabling Graphics for various Rendering APIs such as Vulkan, OpenGL,
// DirectX, and possibly even our own implementation.
class RenderDevice {
protected:
  Resources *mResources;
public:
  virtual ~RenderDevice() { }

  // Resources handler.
  Resources *GetResources() { return mResources; }
  void SetResourceHandler(Resources *resources) { mResources = resources; }

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
  virtual Material *CreateMaterial() = 0;


  virtual void DestroyShader(Shader *shader) = 0;
  virtual void DestroyMaterial(Material *material) = 0;
  virtual void DestroyFrameBuffer(FrameBuffer *framebuffer) = 0;
  virtual void DestroyRenderPass(RenderPass *pass) = 0;
  virtual void DestroyTexture(Texture *texture) = 0;
  virtual void DestoryUniformBuffer(UniformBuffer *uniformbuffer) = 0;
  virtual void DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline) = 0;
  virtual void DestroyComputePipelineState(ComputePipelineState *pipeline) = 0;
  virtual void DestroyCommandBuffer(CommandBuffer *buffer) = 0;

  virtual const tchar *API() const = 0;

  // Still Ongoing work.
  // TODO(): Setters for setting up the pipeline and rendering core.

  // Submit command buffers to the GPU for rendering. If OpenGL is being used, 
  // we go with CPU based rendering calls.
  virtual void SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 buffers) = 0;
};
} // jackal