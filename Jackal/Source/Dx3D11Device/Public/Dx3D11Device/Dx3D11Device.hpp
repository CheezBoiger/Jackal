// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderDevice.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"

#include "Dx3D11Config.hpp"


namespace jackal {


// Direct X 11 rendering device.
class Dx3D11Device : public RenderDevice {
  static const char *renderAPI;
public:

  void                            Initialize() override;
  void                            CleanUp() override;

  Resources*                      GetResources() override;
  Shader*                         CreateShader() override;
  RenderPass*                     CreateRenderPass() override;
  Texture*                        CreateTexture() override;
  UniformBuffer*                  CreateUniformBuffer() override;
  GraphicsPipelineState*          CreateGraphicsPipelineState() override;
  ComputePipelineState*           CreateComputePipelineState() override;
  RenderTarget*                   CreateRenderTarget() override;
  VertexBuffer*                   CreateVertexBuffer() override;
  CommandBuffer*                  CreateCommandBuffer() override;
  MaterialLayout*                 CreateMaterialLayout() override;
  Sampler*                        CreateSampler() override;
  Texture2D*                      CreateTexture2D() override;
  Texture3D*                      CreateTexture3D() override;
  CubeMap*                        CreateCubeMap() override;
  StorageBuffer*                  CreateStorageBuffer() override { return nullptr; }

  void                            SetResourceHandler(Resources *resources) override;
  void                            DestroyShader(Shader *shader) override;
  void                            DestroyRenderPass(RenderPass *pass) override;
  void                            DestroyTexture(Texture *texture) override;
  void                            DestroyUniformBuffer(UniformBuffer *uniformbuffer) override;
  void                            DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline) override;
  void                            DestroyComputePipelineState(ComputePipelineState *pipeline) override;
  void                            DestroyRenderTarget(RenderTarget *target) override;
  void                            DestroyCommandBuffer(CommandBuffer *buffer) override;
  void                            DestroyMaterialLayout(MaterialLayout *material) override;
  void                            DestroyVertexBuffer(VertexBuffer *vb) override;
  void                            DestroySampler(Sampler *sampler) override;
  void                            DestroyTexture2D(Texture2D *texture) override;
  void                            DestroyTexture3D(Texture3D *texture) override;
  void                            DestroyCubeMap(CubeMap *cube) override;
  void                            DestroyStorageBuffer(StorageBuffer* buffer) override { }

  const char *API() const override { return renderAPI; }

  CommandBuffer**                SwapChainCommandBuffers(uint16* count) override;

private:
  ID3D11Device*           mNativeDevice;
  ID3D11DeviceContext*    mNativeContext;
  IDXGISwapChain*         mSwapChain;
};
} // jackal