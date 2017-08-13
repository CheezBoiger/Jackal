// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"

#include "RenderDevice/MaterialLayout.hpp"

#include "VulkanConfigs.hpp"


namespace jackal {


class VulkanMaterialLayout : public MaterialLayout {
public:

  VkDescriptorSet* DescriptorSet() { return &mDescriptorSet; }
  VkDescriptorSetLayout* DescriptorSetLayout() { return &mDescripterLayout; }

  void CleanUp() override;
  void Initialize() override;
  void Update() override;
private:
  
  VkDescriptorPool      mDescriptorPool;
  VkDescriptorSetLayout mDescripterLayout;
  VkDescriptorSet       mDescriptorSet;
};
} // jackal