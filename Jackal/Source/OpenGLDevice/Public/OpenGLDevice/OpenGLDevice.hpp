// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/RenderDevice.hpp"
#include "OpenGLConfigs.hpp"

namespace jackal {


class OpenGLShader;
class OpenGLCommandBuffer;
class OpenGLTexture;
class OpenGLGraphicsPipelineState;
class OpenGLComputePipelineState;
class OpenGLRenderTarget;
class OpenGLRenderPass;
class OpenGLFrameBuffer;
class OpenGLMaterial;
class OpenGLVertexBuffer;
class OpenGLResources;

// OpenGL Rendering Device. This Device handles all 
// Rendering calls, creation, and modification of OpenGL 
// Rendering functionality. It should act as a RHI, or 
// Rendering Hardware Interface implementation of OpenGL.
class OpenGLDevice : public RenderDevice {
  static const tchar *renderAPI;
public:
  // Initialize OpenGL library for first time.
  // This must be called if you plan on using OpenGL.
  static bool8 InitOpenGL();

  OpenGLDevice() { }

  void Init() override;
  Resources *GetResources() override;
  Shader *CreateShader() override;
  FrameBuffer *CreateFrameBuffer() override;
  RenderPass *CreateRenderPass() override;
  Texture *CreateTexture() override;
  UniformBuffer *CreateUniformBuffer() override;
  GraphicsPipelineState *CreateGraphicsPipelineState() override;
  ComputePipelineState *CreateComputePipelineState() override;
  RenderTarget *CreateRenderTarget() override;
  VertexBuffer *CreateVertexBuffer() override;
  CommandBuffer *CreateCommandBuffer() override;
  Material *CreateMaterial() override;

  void SetResourceHandler(Resources *resources) override;
  void DestroyShader(Shader *shader) override;
  void DestroyFrameBuffer(FrameBuffer *framebuffer) override;
  void DestroyRenderPass(RenderPass *pass) override;
  void DestroyTexture(Texture *texture) override;
  void DestoryUniformBuffer(UniformBuffer *uniformbuffer) override;
  void DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline) override;
  void DestroyComputePipelineState(ComputePipelineState *pipeline) override;
  void DestroyCommandBuffer(CommandBuffer *buffer) override;
  void DestroyMaterial(Material *material) override;

  const tchar *API() const override { return renderAPI; }

  // Still Ongoing work.
  // TODO(): Setters for setting up the pipeline and rendering core.

  // Submit command buffers to the GPU for rendering. If OpenGL is being used, 
  // we go with CPU based rendering calls.
  void SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 buffers) override;

private:
  // OpenGL Graphics Pipeline State object currently being used by this rendering 
  // device.
  OpenGLGraphicsPipelineState   *mCurrentGraphicsPipelineState;

  // OpenGL Compute Pipeline State object currently being used by this rendering
  // device.
  OpenGLComputePipelineState    *mCurrentComputePipelineState;

  // OpenGL Vertex Buffer object currently being used by this rendering device.
  OpenGLVertexBuffer            *mCurrentVertexBuffer;

  // OpenGL Material object currently being used by this rendering device.
  OpenGLMaterial                *mCurrentMaterial;
};
} // jackal