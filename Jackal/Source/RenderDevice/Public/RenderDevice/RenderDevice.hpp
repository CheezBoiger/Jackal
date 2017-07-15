// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"

namespace jackal {

class Shader;
class RenderPass;
class RenderTarget;
class FrameBuffer;
class VertexBuffer;
class Texture;
class Texture2D;
class Texture3D;
class CubeMap;
class UniformBuffer;
class GraphicsPipelineState;
class ComputePipelineState;
class CommandBuffer;
class Resources;
class Sampler;
class MaterialLayout;

// RenderDevice interface, used for the rendering system of the 
// Jackal Game Engine. This is the Rendering Hardware Interface used
// for enabling Graphics for various Rendering APIs such as Vulkan, OpenGL,
// DirectX, and possibly even our own implementation.
class RenderDevice {
protected:
  // Protected constructor.
  RenderDevice() 
    : mLastError(RENDER_ERROR_NONE)
    , mRendering(false) { }

public:
  virtual ~RenderDevice() { }

  // Resources handler.
  virtual Resources*              GetResources() = 0;
  virtual void                    SetResourceHandler(Resources *resources) = 0;
  
  virtual void                    Initialize() = 0;
  virtual Shader*                 CreateShader() = 0;
  virtual FrameBuffer*            CreateFrameBuffer() = 0;
  virtual RenderPass*             CreateRenderPass() = 0;
  virtual Texture*                CreateTexture() = 0;
  virtual Texture2D*              CreateTexture2D() = 0;
  virtual Texture3D*              CreateTexture3D() = 0;
  virtual CubeMap*                CreateCubeMap() = 0;
  virtual UniformBuffer*          CreateUniformBuffer() = 0;
  virtual GraphicsPipelineState*  CreateGraphicsPipelineState() = 0;
  virtual ComputePipelineState*   CreateComputePipelineState() = 0;
  virtual RenderTarget*           CreateRenderTarget() = 0;
  virtual VertexBuffer*           CreateVertexBuffer() = 0;
  virtual CommandBuffer*          CreateCommandBuffer() = 0;
  virtual Sampler*                CreateSampler() = 0;
  virtual MaterialLayout*         CreateMaterialLayout() = 0;

  virtual void                    DestroyShader(Shader *shader) = 0;
  virtual void                    DestroyFrameBuffer(FrameBuffer *framebuffer) = 0;
  virtual void                    DestroyRenderPass(RenderPass *pass) = 0;
  virtual void                    DestroyRenderTarget(RenderTarget *target) = 0;
  virtual void                    DestroyVertexBuffer(VertexBuffer *vb) = 0;
  virtual void                    DestroyTexture(Texture *texture) = 0;
  virtual void                    DestroyUniformBuffer(UniformBuffer *uniformbuffer) = 0;
  virtual void                    DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline) = 0;
  virtual void                    DestroyComputePipelineState(ComputePipelineState *pipeline) = 0;
  virtual void                    DestroyCommandBuffer(CommandBuffer *buffer) = 0;
  virtual void                    DestroySampler(Sampler *sampler) = 0;
  virtual void                    DestroyMaterialLayout(MaterialLayout *mlayout) = 0;
  virtual void                    DestroyTexture2D(Texture2D *texture) = 0;
  virtual void                    DestroyTexture3D(Texture3D *texture) = 0;
  virtual void                    DestroyCubeMap(CubeMap *cube) = 0;

  virtual const tchar*            API() const = 0;

  // Retrieve the last error that was dispatched from this render device.
  RenderErrorT GetLastError() {
    RenderErrorT error = mLastError;
    mLastError = RENDER_ERROR_NONE; 
    return error; 
  }

  void SubmitLastError(RenderErrorT error) { mLastError = error; }


  // Check if this device is currently performing rendering.
  bool8 Rendering() { return mRendering; }

  // Still Ongoing work.
  // TODO(): Setters for setting up the pipeline and rendering core.

  // Submit command buffers to the GPU for rendering. If OpenGL is being used, 
  // we go with CPU based rendering calls.
  // 
  // @param commandbuffers Pointer to the list of commandbuffers.
  // @param numBuffers Number of commandbuffers to submit.
  virtual void SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 numBuffers) = 0;

protected:
  // Last error that was conducted in this render device.
  RenderErrorT mLastError;

  bool8        mRendering;
};
} // jackal