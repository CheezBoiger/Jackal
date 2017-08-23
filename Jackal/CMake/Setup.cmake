# Copyright (c) Jackal Engine. MIT License.
# Setup file.

set(JACKAL_ENGINE_DIRECTORY "JackalEngine")

add_subdirectory(Core)
add_subdirectory(RenderDevice)
add_subdirectory(OpenGLDevice)
add_subdirectory(VulkanDevice)
add_subdirectory(Input)
add_subdirectory(Canis)

if (WIN32)
  add_subdirectory(Dx3D12Device)
  add_subdirectory(Dx3D11Device)
else()

endif()

add_subdirectory(Renderer)