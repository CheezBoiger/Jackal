// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/RenderDevice.hpp"


namespace jkl {


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

  OpenGLDevice() : RenderDevice(Type::rOpenGL) { }

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

  void DestroyShader(Shader *shader) override;
  void DestroyFrameBuffer(FrameBuffer *framebuffer) override;
  void Destroy(RenderPass *pass) override;
  void Destroy(Texture *texture) override;
  void DestoryUniformBuffer(UniformBuffer *uniformbuffer) override;
  void DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline) override;
  void DestroyComputePipelineState(ComputePipelineState *pipeline) override;
  void DestroyCommandBuffer(CommandBuffer *buffer) override;

  // Still Ongoing work.
  // TODO(): Setters for setting up the pipeline and rendering core.

  // Submit command buffers to the GPU for rendering. If OpenGL is being used, 
  // we go with CPU based rendering calls.
  void SubmitCommandBuffers(CommandBuffer *commandbuffers) override;

  const tchar *RenderAPIString() override {  
    return renderAPI;
  }

private:
};
} // jkl