// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "VulkanConfigs.hpp"

#include "RenderDevice/RenderTarget.hpp"


namespace jackal {


class VulkanRenderTarget : public RenderTarget {
public:

private:
  VkImage mImage;
  VkImageView mImageView;
};
} // jackal