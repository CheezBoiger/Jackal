// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"

#include "RenderDevice/Sampler.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"

#include "OpenGLConfigs.hpp"

namespace jackal {


class OpenGLSampler : public Sampler {
public:
 
  void Bake(SamplerInfoT &info) override;

  // Get the native handle of this sampler.
  GLint Handle() const { return mHandle; }


private:
  GLint mHandle;
};
} // jackal