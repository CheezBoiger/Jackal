cmake_minimum_required(VERSION 2.8)
project("Dx11Device")

set(JACKAL_DX11_RENDEV_NAME     "Dx3D11Device")
set(DX11_PUBLIC_DIR             Public/Dx3D11Device)
set(DX11_PRIVATE_DIR            Private)


include_directories(
  ${DX11_PUBLIC_DIR}
  ${JACKAL_INCLUDE_DIR}
)


set(DX11_FILES
  ${DX11_PUBLIC_DIR}/Dx3D11Config.hpp
  ${DX11_PUBLIC_DIR}/Dx3D11Device.hpp

  ${DX11_PRIVATE_DIR}/Dx3D11Device.cpp
)


add_library(${JACKAL_DX11_RENDEV_NAME} STATIC
  ${DX11_FILES}
)


if (MSVC)
  foreach(source IN LISTS DX11_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
  endforeach()
endif()

include (Macros)
visual_studio_to_folder(${JACKAL_DX11_RENDEV_NAME} ${JACKAL_ENGINE_DIRECTORY})
set_cxx_standard(${JACKAL_DX11_RENDEV_NAME} 14)