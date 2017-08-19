// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/CommandBuffer.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"


#include "Core/Platform/JTypes.hpp"
#include "VulkanConfigs.hpp"


namespace jackal {


class VulkanCommandBuffer : public CommandBuffer {
public:


private:
  VkCommandBuffer mNativeBuffer;
};
} // jackal