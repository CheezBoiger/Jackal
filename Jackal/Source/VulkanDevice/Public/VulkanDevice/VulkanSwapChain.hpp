// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "VulkanConfigs.hpp"


namespace jackal {


class VulkanSwapChain {
public:
  VulkanSwapChain()
    : mSwapChain(VK_NULL_HANDLE)
    , mFramebuffer(VK_NULL_HANDLE)
    , mImageCount(0)
    , mImageViews(nullptr)
    , mSwapChainImages(nullptr) { }

  void Initialize(VkPhysicalDevice physicalDevice, VkDevice logicalDevice);
  void CleanUp();

  VkSwapchainKHR SwapChainKHR() { return mSwapChain; }  
  VkFramebuffer Framebuffer() { return mFramebuffer; }
  VkImage* SwapChainImages() { return mSwapChainImages; }
  VkImageView* ImageViews() { return mImageViews; }
  uint32 ImageCount() { return mImageCount; }

private:
  VkSwapchainKHR  mSwapChain;
  VkFramebuffer   mFramebuffer;
  VkImage*        mSwapChainImages;
  VkImageView*    mImageViews;
  uint32          mImageCount;
};
} // jackal