// Copyright (c) 2017 Jackal Engine, MIT License.


#include "OpenGLDevice/OpenGLDevice.hpp"
#include "OpenGLDevice/OpenGLCommandBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLFrameBuffer.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"
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


void OpenGLDevice::DestoryUniformBuffer(UniformBuffer *ubo)
{
  if (!ubo) return;

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

  OpenGLShader *oglShader = static_cast<OpenGLShader *>(shader);
  delete oglShader;
  
  OGLShaders -= 1;
  shader = nullptr;
}


void OpenGLDevice::SubmitCommandBuffers(CommandBuffer *commandbuffers, uint32 buffers)
{
  if (!commandbuffers || !buffers) {
    mLastError = RENDER_ERROR_NULL_COMMAND_BUFFER_LIST;
    return;
  }

  // Run the Commands in the command list.
  for (uint32 i = 0; i < buffers; ++i) {
    OpenGLCommandBuffer *oglCommandList = 
      static_cast<OpenGLCommandBuffer *>(&commandbuffers[i]);
    auto &commandList = oglCommandList->GetCommandList();
    for (auto &command : commandList) {
      command();
    }
  }
}
} // jackal