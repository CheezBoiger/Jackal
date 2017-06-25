// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "../VulkanConfigs.hpp"

namespace jackal {


// Win32 Vulkan Surface KHR extension.
// Used for linking windows winding system to 
// Vulkan, in order to see any rendering.
class Win32VulkanKHR {
public:
  // Create a Surface for win32.
  static VkSurfaceKHR CreateSurface(VkInstance vkInstance, HWND hwnd, HINSTANCE hinstance);

  static const char **GetRequiredExtensions(uint32 *count);
};
} // jackal