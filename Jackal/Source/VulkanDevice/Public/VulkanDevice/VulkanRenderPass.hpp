// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/RenderPass.hpp"
#include "VulkanConfigs.hpp"

namespace jackal {


class VulkanRenderPass : public RenderPass {
public:


private:
  VkRenderPass mNativeRenderPass;
};
} // jackal