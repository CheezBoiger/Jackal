cmake_minimum_required(VERSION 2.8)
project("Dx12RenderDevice")



set(JACKAL_DX12_RENDEV_NAME "Dx12Device")
set(DX12_PUBLIC_DIR         Public/Dx3D12Device)
set(DX12_PRIVATE_DIR        Private)


set(DX12_FILES
  ${DX12_PUBLIC_DIR}/Dx12Device.hpp





  ${DX12_PRIVATE_DIR}/Dx12Device.cpp
)


add_library(${JACKAL_DX12_RENDEV_NAME} STATIC
  ${DX12_FILES}
)


# NOTE(): Need to figure out how to find directX libraries for programmers not using visual studio
if (MSVC)
  foreach(source IN LISTS DX12_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
  endforeach()
endif()

include (Macros)
visual_studio_to_folder(${JACKAL_DX12_RENDEV_NAME} ${JACKAL_ENGINE_DIRECTORY})
set_cxx_standard(${JACKAL_DX12_RENDEV_NAME} 14)