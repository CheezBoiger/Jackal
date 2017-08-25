# Copyright (c) 2017 Jackal Engine, under the MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("RenderCoreDevice")

set(JACKAL_RENDEV_NAME   "RenderDevice")
set(RENDEV_PUBLIC_DIR    Public/RenderDevice)
set(RENDEV_PRIVATE_DIR   Private)

# Include Libraries.
include_directories(
  ${JACKAL_INCLUDE_DIR}
)


set(RENDEV_FILES
  ${RENDEV_PUBLIC_DIR}/CommandBuffer.hpp
  ${RENDEV_PUBLIC_DIR}/GPUQuery.hpp
  ${RENDEV_PUBLIC_DIR}/RenderDevice.hpp
  ${RENDEV_PUBLIC_DIR}/RenderPass.hpp
  ${RENDEV_PUBLIC_DIR}/RenderTarget.hpp
  ${RENDEV_PUBLIC_DIR}/Shader.hpp
  ${RENDEV_PRIVATE_DIR}/Shader.cpp
  ${RENDEV_PUBLIC_DIR}/Texture.hpp
  ${RENDEV_PUBLIC_DIR}/TextureConfig.hpp
  ${RENDEV_PUBLIC_DIR}/UniformBuffer.hpp
  ${RENDEV_PUBLIC_DIR}/VertexBuffer.hpp
  ${RENDEV_PUBLIC_DIR}/MaterialLayout.hpp
  ${RENDEV_PRIVATE_DIR}/GPUQuery.cpp
  ${RENDEV_PUBLIC_DIR}/RenderDeviceTypes.hpp
  ${RENDEV_PUBLIC_DIR}/GraphicsPipelineState.hpp
  ${RENDEV_PUBLIC_DIR}/ComputePipelineState.hpp
  ${RENDEV_PUBLIC_DIR}/Vertex.hpp
  ${RENDEV_PUBLIC_DIR}/ViewPort.hpp
  ${RENDEV_PUBLIC_DIR}/RenderObject.hpp
  ${RENDEV_PRIVATE_DIR}/RenderObject.cpp
  ${RENDEV_PUBLIC_DIR}/TextureCubeMap.hpp
  ${RENDEV_PUBLIC_DIR}/Texture2D.hpp
  ${RENDEV_PUBLIC_DIR}/Texture3D.hpp
  ${RENDEV_PUBLIC_DIR}/Sampler.hpp
)

add_library(${JACKAL_RENDEV_NAME} STATIC
  ${RENDEV_FILES}
)

if (${CMAKE_CXX_COMPILER_ID})
  # Doing some stuff for organization.
  if (MSVC)
    foreach(source IN LISTS RENDEV_FILES)
      get_filename_component(source_path "${source}" PATH)
      string(REPLACE "/" "\\" source_path_msvc "${source_path}")
      source_group("${source_path_msvc}" FILES "${source}")
    endforeach()
  endif()
endif()


# Visual Studio organization. For Good purposes.
if (WIN32)
  set_property(TARGET ${JACKAL_RENDEV_NAME} PROPERTY FOLDER ${JACKAL_ENGINE_DIRECTORY})
endif()


include(Macros)

# Set the C++ standard for GCC compilers
set_cxx_standard(${JACKAL_RENDEV_NAME} 14)

