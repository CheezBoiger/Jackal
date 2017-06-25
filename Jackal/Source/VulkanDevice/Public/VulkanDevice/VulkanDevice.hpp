// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderDevice.hpp"
#include "VulkanConfigs.hpp"

namespace jackal {


// Vulkan Render Device, which handles all of Vulkan rendering API and 
// whatnot. Use this device to handle drawing on the screen.
class VulkanDevice : public RenderDevice {
public:
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
  void DestroyMaterial(Material *material) override;
  void DestroyFrameBuffer(FrameBuffer *framebuffer) override;
  void DestroyRenderPass(RenderPass *pass) override;
  void DestroyTexture(Texture *texture) override;
  void DestoryUniformBuffer(UniformBuffer *uniformbuffer) override;
  void DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline) override;
  void DestroyComputePipelineState(ComputePipelineState *pipeline) override;
  void DestroyCommandBuffer(CommandBuffer *buffer) override;
private:
  VkDevice          mLogicalDevice;
  VkPhysicalDevice  mPhyicalDevice;
};
} // jackal