cmake_minimum_required(VERSION 2.8)
project("Canis-ShaderCompiler")


set(JACKAL_SHADER_COMPILER_NAME "Canis-Compiler")
set(JACKAL_CANIS_PUBLIC_DIR   Public/Canis)
set(JACKAL_CANIS_PRIVATE_DIR  Private)


set(CANIS_FILES
  ${JACKAL_CANIS_PUBLIC_DIR}/Compiler.hpp
  ${JACKAL_CANIS_PUBLIC_DIR}/Token.hpp

  ${JACKAL_CANIS_PRIVATE_DIR}/Compiler.cpp
  ${JACKAL_CANIS_PRIVATE_DIR}/Token.cpp
)



add_library(${JACKAL_SHADER_COMPILER_NAME} STATIC
  ${CANIS_FILES}
)


include_directories(
  ${JACKAL_INCLUDE_DIR}
  ${JACKAL_CANIS_PUBLIC_DIR}
)


if (MSVC)
  foreach(source IN LISTS CANIS_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
  endforeach()
endif()

include (Macros)
visual_studio_to_folder(${JACKAL_SHADER_COMPILER_NAME} ${JACKAL_ENGINE_DIRECTORY})
set_cxx_standard(${JACKAL_SHADER_COMPILER_NAME} 14)