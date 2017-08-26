// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once 


#include "VulkanConfigs.hpp"
#include "RenderDevice/Sampler.hpp"


namespace jackal {


class VulkanSampler : public Sampler {
public:
  VulkanSampler()
    : mNativeSampler(VK_NULL_HANDLE) { }
  void Bake(SamplerInfoT& info) override;
  void CleanUp() override;

private:
  VkSampler mNativeSampler;
};
} // jackal