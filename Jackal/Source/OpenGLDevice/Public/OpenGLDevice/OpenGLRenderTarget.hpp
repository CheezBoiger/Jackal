// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"
#include "Core/Platform/Platform.hpp"

#include "RenderDevice/RenderTarget.hpp"

#include "OpenGLConfigs.hpp"


namespace jackal {


class OpenGLRenderTarget : public RenderTarget {
public:

  void Bake(RenderTargetCreateInfoT &information) override;

  GLuint Handle() const { return mHandle; }

private:
  GLuint mHandle;
};
} // jackal