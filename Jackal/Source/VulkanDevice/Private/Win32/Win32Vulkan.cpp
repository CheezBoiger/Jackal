// Copyright (c) 2017 Jackal Engine, MIT License.
#include "VulkanDevice/Win32/Win32Vulkan.hpp"

namespace jackal {


const size_t EXT_LENGTH = 2;

const char *win32Extensions[EXT_LENGTH] = {
  VK_KHR_SURFACE_EXTENSION_NAME,
  VK_KHR_WIN32_SURFACE_EXTENSION_NAME
};



VkSurfaceKHR Win32VulkanKHR::CreateSurface(VkInstance vkInstance, HWND hwnd, HINSTANCE hinstance)
{
  VkSurfaceKHR surface;
  VkWin32SurfaceCreateInfoKHR info;
  info.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
  info.hinstance = hinstance;
  info.hwnd = hwnd;
  info.pNext = nullptr;

  PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR )
    vkGetInstanceProcAddr(vkInstance, "vkCreateWin32SurfaceKHR");

  if (!vkCreateWin32SurfaceKHR || vkCreateWin32SurfaceKHR(vkInstance, &info, nullptr,
    &surface) != VK_SUCCESS)
  {
    return nullptr;
  }

  return surface;
}


const char **Win32VulkanKHR::GetRequiredExtensions(uint32 *count)
{
  *count = EXT_LENGTH;
  return win32Extensions;
}
} // jackal