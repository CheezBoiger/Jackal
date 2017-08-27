// Copyright (c) 2017 Jackal Engine, MIT License.


#include "OpenGLDevice.hpp"
#include "OpenGLCommandBuffer.hpp"
#include "OpenGLGraphicsPipelineState.hpp"
#include "OpenGLComputePipelineState.hpp"
#include "OpenGLFrameBuffer.hpp"
#include "OpenGLRenderPass.hpp"
#include "OpenGLMaterialLayout.hpp"
#include "OpenGLRenderTarget.hpp"
#include "OpenGLUniformBuffer.hpp"
#include "OpenGLSampler.hpp"
#include "OpenGLTexture.hpp"
#include "OpenGLTexture2D.hpp"
#include "OpenGLTexture3D.hpp"
#include "OpenGLShader.hpp"
#include "OpenGLVertexBuffer.hpp"

#include "Core/Logging/Debugging.hpp"
#include "Core/Memory/MemoryPool.hpp"


namespace jackal {


const char *OpenGLDevice::renderAPI = "OpenGL";

uint32 OpenGLDevice::OGLShaders = 0;
uint32 OpenGLDevice::OGLFrameBuffers = 0;
uint32 OpenGLDevice::OGLRenderPasses = 0;
uint32 OpenGLDevice::OGLTextures = 0;
uint32 OpenGLDevice::OGLTexture2Ds = 0;
uint32 OpenGLDevice::OGLTexture3Ds = 0;
uint32 OpenGLDevice::OGLCubeMaps = 0;
uint32 OpenGLDevice::OGLSamplers = 0;
uint32 OpenGLDevice::OGLUniformBuffers = 0;
uint32 OpenGLDevice::OGLGraphicsPipelineStates = 0;
uint32 OpenGLDevice::OGLComputePipelineStates = 0;
uint32 OpenGLDevice::OGLRenderTargets = 0;
uint32 OpenGLDevice::OGLVertexBuffers = 0;
uint32 OpenGLDevice::OGLCommandBuffers = 0;
uint32 OpenGLDevice::OGLMaterialLayouts = 0;  

bool8 OpenGLDevice::InitOpenGL()
{
  bool8 success = gladLoadGL();
  JDEBUG("OpenGL init: %d\n", success); 
  return success;
}


UniformBuffer *OpenGLDevice::CreateUniformBuffer()
{
  OpenGLUniformBuffer *ubo = new OpenGLUniformBuffer();
  ubo->SetOwner(this);

  OGLUniformBuffers += 1;
  return ubo;
}


void OpenGLDevice::DestroyUniformBuffer(UniformBuffer *ubo)
{
  if (!ubo) return;
  ubo->CleanUp();

  OpenGLUniformBuffer *oglUbo = static_cast<OpenGLUniformBuffer *>(ubo);
  delete oglUbo;

  OGLUniformBuffers -= 1;  
  ubo = nullptr;
}


GraphicsPipelineState *OpenGLDevice::CreateGraphicsPipelineState()
{
  OpenGLGraphicsPipelineState *pipe = new OpenGLGraphicsPipelineState();
  pipe->SetOwner(this);
  OGLGraphicsPipelineStates += 1;
  return pipe;
}


void OpenGLDevice::DestroyGraphicsPipelineState(GraphicsPipelineState *pipeline)
{
  if (!pipeline) return;

  OpenGLGraphicsPipelineState *oglPipe = 
    static_cast<OpenGLGraphicsPipelineState *>(pipeline);
  delete oglPipe;

  OGLGraphicsPipelineStates -= 1;
  pipeline = nullptr;
}


Shader *OpenGLDevice::CreateShader()
{
  OpenGLShader *shader = new OpenGLShader();

  OGLShaders += 1;
  return shader;
}


void OpenGLDevice::DestroyShader(Shader *shader)
{
  if (!shader) return;
  shader->CleanUp();

  OpenGLShader *oglShader = static_cast<OpenGLShader *>(shader);
  delete oglShader;
  
  OGLShaders -= 1;
  shader = nullptr;
}


void OpenGLDevice::Initialize()
{
  OPENGL_CHECK_ERROR(GLenum err);
  if (err != GL_NO_ERROR) {
    return;
  }
  mCommandBuffersCount = 2;
  mCommandBuffers = new CommandBuffer*[mCommandBuffersCount];

  for (uint16 i = 0; i < mCommandBuffersCount; ++i) {
    mCommandBuffers[i] = CreateCommandBuffer();
  }

  mInitialized = true;  
}


void OpenGLDevice::CleanUp()
{
  if (mCommandBuffers) {
    for (uint16 i = 0; i < mCommandBuffersCount; ++i) {
      delete mCommandBuffers[i];
    }
    delete[] mCommandBuffers;
  }

  mInitialized = false;
}


CommandBuffer *OpenGLDevice::CreateCommandBuffer()
{
  OpenGLCommandBuffer *cmdBuffer = new OpenGLCommandBuffer();
  cmdBuffer->SetOwner(this);
  OGLCommandBuffers += 1;
  return cmdBuffer;
}


void OpenGLDevice::DestroyCommandBuffer(CommandBuffer *buffer)
{
  buffer->ClearRecord();
  OpenGLCommandBuffer *oglBuffer = static_cast<OpenGLCommandBuffer *>(buffer);
  delete oglBuffer;

  OGLCommandBuffers -= 1;
  buffer = nullptr;
}


RenderPass *OpenGLDevice::CreateRenderPass()
{
  OpenGLRenderPass* renderpass = new OpenGLRenderPass();
  renderpass->SetOwner(this);
  OGLRenderPasses += 1;
  return renderpass;
}


Resources *OpenGLDevice::GetResources()
{
  return nullptr;
}


Texture *OpenGLDevice::CreateTexture()
{
  OpenGLTexture* texture = new OpenGLTexture();
  texture->SetOwner(this);
  OGLTextures += 1;
  return texture;
}


ComputePipelineState *OpenGLDevice::CreateComputePipelineState()
{
  return nullptr;
}


RenderTarget *OpenGLDevice::CreateRenderTarget()
{
  OpenGLRenderTarget* rendertarget = new OpenGLRenderTarget();
  rendertarget->SetOwner(this);
  OGLRenderTargets += 1;
  return rendertarget;
}


VertexBuffer *OpenGLDevice::CreateVertexBuffer()
{
  OpenGLVertexBuffer* vertexbuffer = new OpenGLVertexBuffer();
  vertexbuffer->SetOwner(this);
  OGLVertexBuffers += 1;
  return vertexbuffer;
}


MaterialLayout *OpenGLDevice::CreateMaterialLayout()
{
  OpenGLMaterialLayout* material = new OpenGLMaterialLayout();
  material->SetOwner(this);
  OGLMaterialLayouts += 1;
  return material;
}


Sampler *OpenGLDevice::CreateSampler()
{
  OpenGLSampler* sampler = new OpenGLSampler();
  sampler->SetOwner(this);
  OGLSamplers += 1;
  return sampler;
}


Texture2D *OpenGLDevice::CreateTexture2D()
{
  OpenGLTexture2D* texture = new OpenGLTexture2D();
  texture->SetOwner(this);
  OGLTexture2Ds += 1;
  return texture;
}


Texture3D *OpenGLDevice::CreateTexture3D()
{
  OpenGLTexture3D* texture = new OpenGLTexture3D();
  texture->SetOwner(this);
  OGLTexture3Ds += 1;
  return texture;
}


CubeMap *OpenGLDevice::CreateCubeMap()
{
  OGLCubeMaps += 1;
  return nullptr;
}


void OpenGLDevice::SetResourceHandler(Resources *resources)
{
}


void OpenGLDevice::DestroyRenderPass(RenderPass *renderpass)
{
}


void OpenGLDevice::DestroyTexture(Texture *texture)
{
}


void OpenGLDevice::DestroyComputePipelineState(ComputePipelineState *compute)
{
}


void OpenGLDevice::DestroyRenderTarget(RenderTarget *target)
{
}


void OpenGLDevice::DestroyMaterialLayout(MaterialLayout *layout)
{
}


void OpenGLDevice::DestroyVertexBuffer(VertexBuffer *vb)
{
}


void OpenGLDevice::DestroySampler(Sampler *sampler)
{
}


void OpenGLDevice::DestroyTexture2D(Texture2D *texture)
{
}


void OpenGLDevice::DestroyTexture3D(Texture3D *texture)
{
}


void OpenGLDevice::DestroyCubeMap(CubeMap *cube)
{
}


CommandBuffer** OpenGLDevice::SwapChainCommandBuffers(uint16* count)
{
  *count = mCommandBuffersCount;
  return mCommandBuffers;
}


void OpenGLDevice::SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 buffers)
{
  if (!commandbuffers || !buffers) {
    mLastError = RENDER_ERROR_NULL_COMMAND_BUFFER_LIST;
    return;
  }

  if (!mInitialized) {
    mLastError = RENDER_ERROR_RENDER_DEVICE_UNINITIALIZED;
    return;
  }

  mRendering = true;

  // Run the Commands in the command list.
  for (uint32 i = 0; i < buffers; ++i) {
    OpenGLCommandBuffer *oglCommandList = 
      static_cast<OpenGLCommandBuffer *>(&commandbuffers[i]);
    auto &commandList = oglCommandList->GetNativeCommandList();

    for (auto &command : commandList) {

      // Run the recorded command.
      command();

      // Issue has occured, which must cause the device to stop
      // rendering. Should an error occur, must take action to 
      // clean up resources bound to the rendering pipeline.
      if (mLastError != RENDER_ERROR_NONE) break;
    }
  }

  // Signal end of rendering.
  mRendering = false;
}
} // jackal