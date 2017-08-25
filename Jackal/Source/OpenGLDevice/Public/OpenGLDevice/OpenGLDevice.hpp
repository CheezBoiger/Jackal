// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/RenderDevice.hpp"
#include "OpenGLConfigs.hpp"
#include "Core/Math/Vector4.hpp"
#include "Core/Math/Color4.hpp"

namespace jackal {

class OpenGLShader;
class OpenGLCommandBuffer;
class OpenGLTexture;
class OpenGLTexture2D;
class OpenGLTexture3D;
class OpenGLCubeMap;
class OpenGLSampler;
class OpenGLGraphicsPipelineState;
class OpenGLComputePipelineState;
class OpenGLRenderTarget;
class OpenGLRenderPass;
class OpenGLVertexBuffer;
class OpenGLUniformBuffer;
class OpenGLResources;
class OpenGLMaterialLayout;

// OpenGL Rendering Device. This Device handles all 
// Rendering calls, creation, and modification of OpenGL 
// Rendering functionality. It should act as a RHI, or 
// Rendering Hardware Interface implementation of OpenGL.
class OpenGLDevice : public RenderDevice {
  static const char *renderAPI;

  // Keep Track of the number of opengl objects allocated by OpenGLDevice.
  static uint32       OGLShaders;
  static uint32       OGLFrameBuffers;
  static uint32       OGLRenderPasses;
  static uint32       OGLTextures;
  static uint32       OGLTexture2Ds;
  static uint32       OGLTexture3Ds;
  static uint32       OGLCubeMaps;
  static uint32       OGLSamplers;
  static uint32       OGLUniformBuffers;
  static uint32       OGLGraphicsPipelineStates;
  static uint32       OGLComputePipelineStates;
  static uint32       OGLRenderTargets;
  static uint32       OGLVertexBuffers;
  static uint32       OGLCommandBuffers;
  static uint32       OGLMaterialLayouts;

public:

  // Initialize OpenGL library for first time.
  // This must be called if you plan on using OpenGL.
  static bool8 InitOpenGL();

  OpenGLDevice()
    : mCurrentComputePipelineState(nullptr)
    , mCurrentGraphicsPipelineState(nullptr)
    , mCurrentVertexBuffer(nullptr)
    , mCurrentUniformBuffer(nullptr)
    , mCurrentRenderPass(nullptr)
    , mClearColor(Color(0, 0, 0, 255)) { }

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

  const char *API() const override { return renderAPI; }

  // Still Ongoing work.
  // TODO(): Setters for setting up the pipeline and rendering core.

  // Submit command buffers to the GPU for rendering. If OpenGL is being used, 
  // we go with CPU based rendering calls.
  void SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 buffers) override;

  // OpenGL Graphics Pipeline State object currently being used by this rendering 
  // device.
  OpenGLGraphicsPipelineState*  mCurrentGraphicsPipelineState;

  // OpenGL Compute Pipeline State object currently being used by this rendering
  // device.
  OpenGLComputePipelineState*   mCurrentComputePipelineState;

  // OpenGL Vertex Buffer object currently being used by this rendering device.
  OpenGLVertexBuffer*           mCurrentVertexBuffer;

  // OpenGL Uniform Buffer object currently being used by this rendering device.
  OpenGLUniformBuffer*          mCurrentUniformBuffer;
  
  // OpenGL Material object currently being use by this rendering device.
  OpenGLMaterialLayout*         mCurrentMaterialLayout;

  // Current OpenGL RenderPass bound.
  OpenGLRenderPass*             mCurrentRenderPass;

  Color                         mClearColor;
};
} // jackal