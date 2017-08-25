// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/FrameBuffer.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"

#include "VulkanConfigs.hpp"


namespace jackal {


class VulkanFrameBuffer : public FrameBuffer {
public:

private:
  VkFramebuffer mNativeFrameBuffer;
};
} // jackal