# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("Renderer")

set(JACKAL_RENDERER_NAME "Renderer")
set(JACKAL_RENDERER_PUBLIC_DIR    Public/Renderer)
set(JACKAL_RENDERER_PRIVATE_DIR   Private)


include_directories(
  ${JACKAL_INCLUDE_DIR}
)


set(RENDERER_FILES
  ${JACKAL_RENDERER_PUBLIC_DIR}/IRenderer.hpp
  ${JACKAL_RENDERER_PUBLIC_DIR}/Renderer.hpp  

  ${JACKAL_RENDERER_PRIVATE_DIR}/Renderer.cpp
)



add_library(${JACKAL_RENDERER_NAME} STATIC
  ${RENDERER_FILES}
)


if (WIN32 AND ${CMAKE_CXX_COMPILER_ID})
  foreach(source IN LISTS FILE_GLOB)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
  endforeach()
  # Set this library into the jackal engine directory.
  set_property(TARGET ${JACKAL_RENDERER_NAME} PROPERTY FOLDER ${JACKAL_ENGINE_DIRECTORY})
endif()