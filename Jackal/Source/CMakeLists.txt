# Copyright (c) 2017, Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalEngineModules")


# Setting the jackal overall name and the description.
# This is a modern implementation of our engine, going in the 
# way of overall power of the machine.
set(JACKAL_NAME        "Jackal" CACHE STRING "")
set(JACKAL_DESCRIPTION "Jackal Open Source Game Engine" CACHE STRING "")

# Jackal Folder modules.
set(JACKAL_DIR          ${CMAKE_CURRENT_SOURCE_DIR})
set(JACKAL_CORE_DIR     ${JACKAL_DIR}/Core)
set(JACKAL_RENDEV_DIR   ${JACKAL_DIR}/RenderDevice)
set(JACKAL_OGLDEV_DIR   ${JACKAL_DIR}/OpenGLDevice)
set(JACKAL_VKNDEV_DIR   ${JACKAL_DIR}/VulkanDevice)
set(JACKAL_D12DEV_DIR   ${JACKAL_DIR}/Dx3D12Device)
set(JACKAL_ENGINE_DIR   ${JACKAL_DIR}/Engine)
set(JACKAL_FILESYS_DIR  ${JACKAL_DIR}/Filesystem)
set(JACKAL_ANIM_DIR     ${JACKAL_DIR}/Animation)
set(JACKAL_AI_DIR       ${JACKAL_DIR}/AI)
set(JACKAL_AUDIO_DIR    ${JACKAL_DIR}/Audio)
set(JACKAL_MTLDEV_DIR   ${JACKAL_DIR}/MetalDevice)
set(JACKAL_MEDIA_DIR    ${JACKAL_DIR}/Media)
set(JACKAL_INPUT_DIR    ${JACKAL_DIR}/Input)
set(JACKAL_PROFILER_DIR ${JACKAL_DIR}/Profiler)
set(JACKAL_RENDERER_DIR ${JACKAL_DIR}/Renderer)
set(JACKAL_RESOURCE_DIR ${JACKAL_DIR}/Resource)
set(JACKAL_OBJCORE_DIR  ${JACKAL_DIR}/ObjectCore)
set(JACKAL_NETWORK_DIR  ${JACKAL_DIR}/Networking)


set(JACKAL_CORE_INC_DIR     ${JACKAL_DIR}/Core/Public)
set(JACKAL_RENDEV_INC_DIR   ${JACKAL_DIR}/RenderDevice/Public)
set(JACKAL_OGLDEV_INC_DIR   ${JACKAL_DIR}/OpenGLDevice/Public)
set(JACKAL_VKNDEV_INC_DIR   ${JACKAL_DIR}/VulkanDevice/Public)
set(JACKAL_D12DEV_INC_DIR   ${JACKAL_DIR}/Dx3D12Device/Public)
set(JACKAL_ENGINE_INC_DIR   ${JACKAL_DIR}/Engine/Public)
set(JACKAL_FILESYS_INC_DIR  ${JACKAL_DIR}/Filesystem/Public)
set(JACKAL_ANIM_INC_DIR     ${JACKAL_DIR}/Animation/Public)
set(JACKAL_AI_INC_DIR       ${JACKAL_DIR}/AI/Public)
set(JACKAL_AUDIO_INC_DIR    ${JACKAL_DIR}/Audio/Public)
set(JACKAL_MTLDEV_INC_DIR   ${JACKAL_DIR}/MetalDevice/Public)
set(JACKAL_MEDIA_INC_DIR    ${JACKAL_DIR}/Media/Public)
set(JACKAL_INPUT_INC_DIR    ${JACKAL_DIR}/Input/Public)
set(JACKAL_PROFILER_INC_DIR ${JACKAL_DIR}/Profiler/Public)
set(JACKAL_RENDERER_INC_DIR ${JACKAL_DIR}/Renderer/Public)
set(JACKAL_RESOURCE_INC_DIR ${JACKAL_DIR}/Resource/Public)
set(JACKAL_OBJCORE_INC_DIR  ${JACKAL_DIR}/ObjectCore/Public)
set(JACKAL_NETWORK_INC_DIR  ${JACKAL_DIR}/Networking/Public)

# Common Jackal Include Directory
set(JACKAL_INCLUDE_DIR
  ${JACKAL_THIRD_PARTY_DIR}
  ${JACKAL_CORE_INC_DIR}
  ${JACKAL_RENDEV_INC_DIR}
  ${JACKAL_OGLDEV_INC_DIR}
  ${JACKAL_VKNDEV_INC_DIR}
  ${JACKAL_D12DEV_INC_DIR}
  ${JACKAL_ENGINE_INC_DIR}
  ${JACKAL_FILESYS_INC_DIR}
  ${JACKAL_ANIM_INC_DIR}
  ${JACKAL_AI_INC_DIR}
  ${JACKAL_AUDIO_INC_DIR}
  ${JACKAL_MTLDEV_INC_DIR}
  ${JACKAL_MEDIA_INC_DIR}
  ${JACKAL_INPUT_INC_DIR}
  ${JACKAL_PROFILER_INC_DIR}
  ${JACKAL_RENDERER_INC_DIR}
  ${JACKAL_RESOURCE_INC_DIR}
  ${JACKAL_OBJCORE_INC_DIR}
  ${JACKAL_NETWORK_INC_DIR}
)


include(Packages)

# Find our packages We might include these in a separate cmake folder in the long run.
find_package(OpenAL)

if (NOT OPENAL_FOUND)
  message(WARNING "OpenAL not found!")
endif()

# Include the setup for our engine.
include (Setup)

