// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderDevice.hpp"
#include "VulkanConfigs.hpp"

namespace jackal {


// Vulkan Render Device, which handles all of Vulkan rendering API and 
// whatnot. Use this device to handle drawing on the screen.
class VulkanDevice : public RenderDevice {
public:
  // TODO(): Need to figure out how to pass window handle to vulkan.
  void Initialize() override;

  Resources*                        GetResources() override;
  Shader*                           CreateShader() override;
  FrameBuffer*                      CreateFrameBuffer() override;
  RenderPass*                       CreateRenderPass() override;
  Texture*                          CreateTexture() override;
  UniformBuffer*                    CreateUniformBuffer() override;
  GraphicsPipelineState*            CreateGraphicsPipelineState() override;
  ComputePipelineState*             CreateComputePipelineState() override;
  RenderTarget*                     CreateRenderTarget() override;
  VertexBuffer*                     CreateVertexBuffer() override;
  CommandBuffer*                    CreateCommandBuffer() override;
  void                              SetResourceHandler(Resources *resources) override;

  void                              DestroyShader(Shader *shader) override;
  void                              DestroyFrameBuffer(FrameBuffer *framebuffer) override;
  void                              DestroyRenderPass(RenderPass *pass) override;
  void                              DestroyTexture(Texture *texture) override;
  void                              DestroyUniformBuffer(UniformBuffer *uniformbuffer) override;
  void                              DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline) override;
  void                              DestroyComputePipelineState(ComputePipelineState *pipeline) override;
  void                              DestroyCommandBuffer(CommandBuffer *buffer) override;

  // Submit command buffers to the Vulkan Rendering API.
  void SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 numBuffers) override;

protected:
  // Check for support for extensions in the instance.
  void CheckExtensionSupport();

private:
  VkInstance        mInstance;
  VkDevice          mLogicalDevice;
  VkPhysicalDevice  mPhyicalDevice;

  // Window surface for vulkan to render onto.
  VkSurfaceKHR      mSurface;
  VkCommandPool     mCommandPool;
};
} // jackal