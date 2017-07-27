# Copyright (c) 2017 Jackal Engine, under the MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalInput")


set(JACKAL_INPUT_NAME           "Jackal-Input")
set(JACKAL_INPUT_PUBLIC_DIR     Public/Input)
set(JACKAL_INPUT_PRIVATE_DIR    Private)

include_directories(
  ${JACKAL_INCLUDE_DIR}
)


set(INPUT_FILES
  ${JACKAL_INPUT_PUBLIC_DIR}/Keyboard.hpp
  ${JACKAL_INPUT_PUBLIC_DIR}/Mouse.hpp

  ${JACKAL_INPUT_PRIVATE_DIR}/Keyboard.cpp
  ${JACKAL_INPUT_PRIVATE_DIR}/Mouse.cpp
)


add_library(${JACKAL_INPUT_NAME} STATIC
  ${INPUT_FILES}
)

if (MSVC)
  foreach(source IN LISTS INPUT_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
  endforeach()
endif()


include(Macros)
# visual_studio_organize_project(INPUT_FILES)
visual_studio_to_folder(${JACKAL_INPUT_NAME} ${JACKAL_ENGINE_DIRECTORY})
set_cxx_standard(${JACKAL_INPUT_NAME} 14)
