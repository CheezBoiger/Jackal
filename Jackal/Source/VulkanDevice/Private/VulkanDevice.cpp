// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "VulkanDevice/VulkanDevice.hpp"

#include <vector>

#if JACKAL_PLATFORM == JACKAL_WINDOWS
  #include "VulkanDevice/Win32/Win32Vulkan.hpp"
#endif

namespace jackal {


void VulkanDevice::Initialize()
{
  VkApplicationInfo appInfo =  { };
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  // TODO(): Change this in the future to match the game's application name.
  appInfo.pApplicationName = "Vulkan Application";
  appInfo.pEngineName = "Jackal Engine";
  appInfo.apiVersion = VK_API_VERSION_1_0;
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);

  VkInstanceCreateInfo instanceInfo;
  instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instanceInfo.pApplicationInfo = &appInfo;
  const char **extensions;
  uint32 extCount = 0;
  
  // Platform specific needs for finding our Instance extensions.
#if JACKAL_PLATFORM == JACKAL_WINDOWS
  extensions = Win32VulkanKHR::GetRequiredExtensions(&extCount);
#endif

  instanceInfo.enabledExtensionCount = extCount;
  instanceInfo.ppEnabledExtensionNames = extensions;
  instanceInfo.enabledLayerCount = 0;

  VkResult result = vkCreateInstance(&instanceInfo, nullptr, &mInstance);
  if (result != VK_SUCCESS) {
    // Fail state.
  } 
}


void VulkanDevice::CheckExtensionSupport()
{
  uint32 extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
  std::vector<VkExtensionProperties> extensionProperties(extensionCount);
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensionProperties.data());
}
} // jackal