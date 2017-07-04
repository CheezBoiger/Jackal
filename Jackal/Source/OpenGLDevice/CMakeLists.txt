# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("OpenGLRenderDevice")

find_package(OpenGL)

set(JACKAL_OPENGL_RENDEV_NAME "OpenGLDevice")
set(OPENGL_PUBLIC_DIR            Public/OpenGLDevice)
set(OPENGL_PRIVATE_DIR           Private)
set(OPENGL_WIN32_PUBLIC_DIR      ${OPENGL_PUBLIC_DIR}/Win32)
set(OPENGL_WIN32_PRIVATE_DIR     ${OPENGL_PRIVATE_DIR}/Win32)

set(OPENGL_FILES
  ${OPENGL_PUBLIC_DIR}/OpenGLDevice.hpp
  ${OPENGL_PRIVATE_DIR}/OpenGLDevice.cpp
  ${OPENGL_PUBLIC_DIR}/OpenGLConfigs.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLCommandBuffer.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLComputePipelineState.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLGraphicsPipelineState.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLCubemap.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLFrameBuffer.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLGPUQuery.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLMaterial.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLRenderPass.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLRenderTarget.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLShader.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLTexture.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLUniformBuffer.hpp
  ${OPENGL_PUBLIC_DIR}/OpenGLVertexBuffer.hpp

  ${OPENGL_PRIVATE_DIR}/OpenGLComputePipelineState.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLGraphicsPipelineState.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLGPUQuery.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLMaterial.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLRenderPass.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLRenderTarget.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLCommandBuffer.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLShader.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLTexture.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLUniformBuffer.cpp
  ${OPENGL_PRIVATE_DIR}/OpenGLVertexBuffer.cpp

  ${JACKAL_THIRD_PARTY_DIR}/opengl/glad/glad.c
)

if (WIN32)
  set(OPENGL_FILES
    ${OPENGL_FILES}
    ${OPENGL_WIN32_PUBLIC_DIR}/Win32OpenGL.hpp
    ${OPENGL_WIN32_PRIVATE_DIR}/Win32OpenGL.cpp
  )
endif()


if (OPENGL_FOUND)
  include_directories(
    ${JACKAL_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
  )

  # Add up the files of opengl.
  add_library(${JACKAL_OPENGL_RENDEV_NAME} STATIC
    ${OPENGL_FILES}
  )

  target_link_libraries(${JACKAL_OPENGL_RENDEV_NAME} ${OPENGL_LIBRARIES})
  if (${CMAKE_CXX_COMPILER_ID})
    # Doing some stuff for organization.
    if (MSVC)
      foreach(source IN LISTS OPENGL_FILES)
        get_filename_component(source_path "${source}" PATH)
        string(REPLACE "/" "\\" source_path_msvc "${source_path}")
        source_group("${source_path_msvc}" FILES "${source}")
      endforeach()
    endif()

  # Visual Studio organization. For Good purposes.
  if (WIN32)
    set_property(TARGET ${JACKAL_OPENGL_RENDEV_NAME} 
      PROPERTY 
      FOLDER ${JACKAL_ENGINE_DIRECTORY})
    endif()
  endif()
  include (Macros)

  set_cxx_standard(${JACKAL_OPENGL_RENDEV_NAME} 14)
else()
  message(WARNING "OpenGL not found!")  
endif()



