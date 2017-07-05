// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "RenderDevice/GraphicsPipelineState.hpp"
#include "VulkanConfigs.hpp"


namespace jackal {


class VulkanGraphicsPipelineState : public GraphicsPipelineState {
public:




  VkPipeline mPipeline;
};
} // jackal