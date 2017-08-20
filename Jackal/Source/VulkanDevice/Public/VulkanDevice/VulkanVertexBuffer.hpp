// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "RenderDevice/VertexBuffer.hpp"
#include "RenderDevice/RenderDeviceTypes.hpp"

#include "VulkanConfigs.hpp"

namespace jackal {


// Depending on the user's wants, a vulkan buffer can be either on gpu
// or cpu memory. gpu memory requires staging a buffer and submitting 
// to the queue to transfer data to that buffer on the gpu. cpu memory
// is slower, but more proficient with dynamic meshes, however gpu memory 
// is probably better.
class VulkanVertexBuffer : public VertexBuffer {
public:

private:
  VkBuffer mNativeBuffer;
  VkDeviceMemory mNativeBufferMemory;
};
} // jackal