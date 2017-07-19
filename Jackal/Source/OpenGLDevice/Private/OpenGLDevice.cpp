// Copyright (c) 2017 Jackal Engine, MIT License.


#include "OpenGLDevice/OpenGLDevice.hpp"
#include "OpenGLDevice/OpenGLCommandBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLComputePipelineState.hpp"
#include "OpenGLDevice/OpenGLFrameBuffer.hpp"
#include "OpenGLDevice/OpenGLRenderPass.hpp"
#include "OpenGLDevice/OpenGLMaterialLayout.hpp"
#include "OpenGLDevice/OpenGLRenderTarget.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
#include "OpenGLDevice/OpenGLTexture.hpp"
#include "OpenGLDevice/OpenGLShader.hpp"

#include "Core/Logging/Debugging.hpp"


namespace jackal {


const tchar *OpenGLDevice::renderAPI = JTEXT("OpenGL");

uint32 OpenGLDevice::OGLShaders = 0;
uint32 OpenGLDevice::OGLFrameBuffers = 0;
uint32 OpenGLDevice::OGLRenderPasses = 0;
uint32 OpenGLDevice::OGLTextures = 0;
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
}


void OpenGLDevice::CleanUp()
{
}


CommandBuffer *OpenGLDevice::CreateCommandBuffer()
{
  OpenGLCommandBuffer *cmdBuffer = new OpenGLCommandBuffer(this);
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


FrameBuffer *OpenGLDevice::CreateFrameBuffer()
{
  return nullptr;
}


RenderPass *OpenGLDevice::CreateRenderPass()
{
  return nullptr;
}


Resources *OpenGLDevice::GetResources()
{
  return nullptr;
}


Texture *OpenGLDevice::CreateTexture()
{
  return nullptr;
}


ComputePipelineState *OpenGLDevice::CreateComputePipelineState()
{
  return nullptr;
}


RenderTarget *OpenGLDevice::CreateRenderTarget()
{
  return nullptr;
}


VertexBuffer *OpenGLDevice::CreateVertexBuffer()
{
  return nullptr;
}


MaterialLayout *OpenGLDevice::CreateMaterialLayout()
{
  return nullptr;
}


Sampler *OpenGLDevice::CreateSampler()
{
  return nullptr;
}


Texture2D *OpenGLDevice::CreateTexture2D()
{
  return nullptr;
}


Texture3D *OpenGLDevice::CreateTexture3D()
{
  return nullptr;
}


CubeMap *OpenGLDevice::CreateCubeMap()
{
  return nullptr;
}


void OpenGLDevice::SetResourceHandler(Resources *resources)
{
}


void OpenGLDevice::DestroyFrameBuffer(FrameBuffer *framebuffer)
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


void OpenGLDevice::SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 buffers)
{
  if (!commandbuffers || !buffers) {
    mLastError = RENDER_ERROR_NULL_COMMAND_BUFFER_LIST;
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