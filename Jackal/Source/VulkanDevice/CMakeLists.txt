# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("VulkanRenderDevice")

set(JACKAL_VULKAN_RENDEV_NAME "VulkanDevice")
set(VULKAN_PUBLIC_DIR         Public/VulkanDevice)
set(VULKAN_PRIVATE_DIR        Private)


include_directories(
  ${JACKAL_INCLUDE_DIR}
  ${Vulkan_INCLUDE_DIRS}
  ${JACKAL_THIRD_PARTY_DIR}/glslang
)

set(VULKAN_FILES
  ${VULKAN_PUBLIC_DIR}/VulkanDevice.hpp
  ${VULKAN_PRIVATE_DIR}/VulkanDevice.cpp
)

# If vulkan is found, add to the build configurations. Else, just ignore
# Vulkan.
if (Vulkan_FOUND)
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
endif()