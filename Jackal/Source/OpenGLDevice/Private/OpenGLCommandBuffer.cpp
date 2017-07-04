// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "OpenGLDevice/OpenGLCommandBuffer.hpp"
#include "OpenGLDevice/OpenGLComputePipelineState.hpp"
#include "OpenGLDevice/OpenGLCubemap.hpp"
#include "OpenGLDevice/OpenGLGraphicsPipelineState.hpp"
#include "OpenGLDevice/OpenGLFrameBuffer.hpp"
#include "OpenGLDevice/OpenGLRenderTarget.hpp"
#include "OpenGLDevice/OpenGLRenderTarget.hpp"
#include "OpenGLDevice/OpenGLTexture.hpp"
#include "OpenGLDevice/OpenGLVertexBuffer.hpp"
#include "OpenGLDevice/OpenGLUniformBuffer.hpp"


namespace jackal {


void OpenGLCommandBuffer::Record()
{
  mRecording = true;
  mNumDrawCalls = 0;
  mNumRenderCalls = 0;
}

void OpenGLCommandBuffer::EndRecord()
{
  mRecording = false;
}

void OpenGLCommandBuffer::ClearRecord()
{
  mCommandList.clear();
  mNumDrawCalls = 0;
  mNumRenderCalls = 0;
  mRecording = false;
}

void OpenGLCommandBuffer::ClearColor(Colorf color)
{
  auto execute = [=] (Colorf color) -> void {
    glClearColor(color.r, color.g, color.b, color.a);
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(color); });
}


void OpenGLCommandBuffer::Clear()
{
  auto execute = [=] () -> void {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  };
  ++mNumRenderCalls;
  mCommandList.push_back([=] () -> void { execute(); });
}
}