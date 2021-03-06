# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("VulkanRenderDevice")


# Find our precious Vulkan Rendering API
find_package(Vulkan)

set(JACKAL_VULKAN_RENDEV_NAME "VulkanDevice")
set(VULKAN_PUBLIC_DIR         Public/VulkanDevice)
set(VULKAN_PRIVATE_DIR        Private)
set(VULKAN_WIN32_PUBLIC_DIR   ${VULKAN_PUBLIC_DIR}/Win32)
set(VULKAN_WIN32_PRIVATE_DIR  ${VULKAN_PRIVATE_DIR}/Win32)

set(VULKAN_FILES
  ${VULKAN_PUBLIC_DIR}/VulkanDevice.hpp
  ${VULKAN_PRIVATE_DIR}/VulkanDevice.cpp
  ${VULKAN_PUBLIC_DIR}/VulkanConfigs.hpp

  ${VULKAN_PUBLIC_DIR}/Vulkan.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanCommandBuffer.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanComputePipelineState.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanCubemap.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanGraphicsPipelineState.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanBuffer.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanMaterialLayout.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanPhysicalDevice.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanRenderPass.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanRenderTarget.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanShader.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanTexture.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanUniformBuffer.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanVertexBuffer.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanSampler.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanTexture2D.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanTexture3D.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanTextureCubeMap.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanSwapChain.hpp
  ${VULKAN_PUBLIC_DIR}/VulkanOcclusionQuery.hpp

  ${VULKAN_PRIVATE_DIR}/Vulkan.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanCommandBuffer.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanComputePipelineState.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanCubemap.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanBuffer.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanFrameBuffer.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanFrameBuffer.hpp
  ${VULKAN_PRIVATE_DIR}/VulkanGraphicsPipelineState.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanMaterialLayout.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanSwapChain.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanPhysicalDevice.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanRenderPass.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanRenderTarget.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanShader.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanSurface.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanTexture.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanUniformBuffer.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanVertexBuffer.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanSampler.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanTexture2D.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanTexture3D.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanTextureCubeMap.cpp
  ${VULKAN_PRIVATE_DIR}/VulkanOcclusionQuery.cpp
)

if (WIN32)
  set(VULKAN_FILES 
    ${VULKAN_FILES}
    ${VULKAN_WIN32_PUBLIC_DIR}/Win32Vulkan.hpp
    ${VULKAN_WIN32_PRIVATE_DIR}/Win32Vulkan.cpp
  )
elseif(UNIX)

endif()

# If vulkan is found, add to the build configurations. Else, just ignore
# Vulkan.
if (Vulkan_FOUND)
  message("Vulkan Found...")
  include_directories(
    ${VULKAN_PUBLIC_DIR}
    ${JACKAL_INCLUDE_DIR}
    ${Vulkan_INCLUDE_DIRS}
    ${JACKAL_THIRD_PARTY_DIR}/glslang 
  )


  add_library(${JACKAL_VULKAN_RENDEV_NAME} STATIC
    ${VULKAN_FILES}
  )


  target_link_libraries(${JACKAL_VULKAN_RENDEV_NAME} ${Vulkan_LIBRARIES})
  target_link_libraries(${JACKAL_VULKAN_RENDEV_NAME} glslang)

  if (${CMAKE_CXX_COMPILER_ID})
    # Doing some stuff for organization.
    if (MSVC)
      foreach(source IN LISTS VULKAN_FILES)
        get_filename_component(source_path "${source}" PATH)
        string(REPLACE "/" "\\" source_path_msvc "${source_path}")
        source_group("${source_path_msvc}" FILES "${source}")
      endforeach()
    endif()

  # Visual Studio organization. For Good purposes.
    if (WIN32)
      set_property(TARGET ${JACKAL_VULKAN_RENDEV_NAME} 
        PROPERTY 
        FOLDER ${JACKAL_ENGINE_DIRECTORY})
    endif()
  endif()


  include (Macros)

  set_cxx_standard(${JACKAL_VULKAN_RENDEV_NAME} 14)


else()
  message(WARNING "Vulkan not found, ignoring Vulkan Device build...")
endif()
