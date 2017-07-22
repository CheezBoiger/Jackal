// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDevice/FrameBuffer.hpp"

#include "OpenGLConfigs.hpp"


namespace jackal {


class OpenGLFrameBuffer : public FrameBuffer {
public:
  

  void StoreRenderTarget(RenderTarget *target, uint32 index) override;
  RenderTarget *GetRenderTarget(uint32 index) override;
  bool8 RemoveRenderTarget(uint32 index) override;

  void Bake(RenderPass *renderpass) override;

  GLint Handle() const { return mHandle; }

private:
  GLint mHandle;
};
} // jackal