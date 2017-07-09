// Copyright (c) 2017 Jackal Engine, MIT License.


#include "OpenGLDevice/OpenGLDevice.hpp"
#include "OpenGLDevice/OpenGLCommandBuffer.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLFrameBuffer.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"

#include "Core/Logging/Debugging.hpp"

namespace jackal {


const tchar *OpenGLDevice::renderAPI = JTEXT("OpenGL");

bool8 OpenGLDevice::InitOpenGL()
{
  bool8 success = gladLoadGL();
  JDEBUG("OpenGL init: %d\n", success);
  return success;
}


UniformBuffer *OpenGLDevice::CreateUniformBuffer()
{
  OpenGLUniformBuffer *ubo = new OpenGLUniformBuffer();
  return ubo;
}


void OpenGLDevice::DestoryUniformBuffer(UniformBuffer *ubo)
{
  OpenGLUniformBuffer *oglUbo = static_cast<OpenGLUniformBuffer *>(ubo);
  delete oglUbo;
  
  ubo = nullptr;
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