#
# Copyright (c) 2017 Jackal Engine, under the MIT License.
#
cmake_minimum_required(VERSION 2.8.11)
project("JackalCore")

set(JACKAL_CORE_VERSION     0)
set(JACKAL_CORE_NAME "Jackal-Core" CACHE STRING "Name of the Game Engine Core.")


set(JACKAL_CORE_DIR    ${CMAKE_SOURCE_DIR}/core/)
set(CORE_MATH_DIR      math)
set(CORE_MEMORY_DIR    memory)
set(CORE_PLATFORM_DIR  platform)
set(CORE_TEMPLATES_DIR templates)
set(CORE_LOGGING_DIR   logging)



# Math Directories.
set(MATH_INTERNAL_DIR       ${CORE_MATH_DIR}/internal)
set(MATH_BOUNDING_DIR       ${CORE_MATH_DIR}/bounding)
set(MATH_GEOMETRY_DIR       ${CORE_MATH_DIR}/geometry)

set(CORE_MATH
  ${CORE_MATH_DIR}/common.hpp
  ${CORE_MATH_DIR}/matrix.hpp
  ${CORE_MATH_DIR}/quaternion.hpp
  ${CORE_MATH_DIR}/ray.hpp
  ${CORE_MATH_DIR}/vector.hpp
  ${CORE_MATH_DIR}/matrix_math.hpp
  ${CORE_MATH_DIR}/vector_math.hpp
)

# Platform Work.
set(PLATFORM_PUBLIC_DIR      ${CORE_PLATFORM_DIR}/public)
set(PLATFORM_PRIVATE_DIR     ${CORE_PLATFORM_DIR}/private)
set(PLATFORM_WIN32_DIR       ${PLATFORM_PRIVATE_DIR}/win32)
set(PLATFORM_LINUX_DIR       ${PLATFORM_PRIVATE_DIR}/linux)
set(PLATFORM_APPLE_DIR       ${PLATFORM_PRIVATE_DIR}/apple)

set(CORE_WIN32
  ${PLATFORM_WIN32_DIR}/win32_clock.hpp
  ${PLATFORM_WIN32_DIR}/win32_config.hpp
  ${PLATFORM_WIN32_DIR}/win32_file.cpp
  ${PLATFORM_WIN32_DIR}/win32_file.hpp
  ${PLATFORM_WIN32_DIR}/win32_filesystem.cpp
  ${PLATFORM_WIN32_DIR}/win32_filesystem.hpp
  ${PLATFORM_WIN32_DIR}/win32_network.cpp
  ${PLATFORM_WIN32_DIR}/win32_network.hpp
  ${PLATFORM_WIN32_DIR}/win32_platform.hpp
  ${PLATFORM_WIN32_DIR}/win32_thread.cpp
  ${PLATFORM_WIN32_DIR}/win32_thread.hpp
  ${PLATFORM_WIN32_DIR}/win32_window.cpp
  ${PLATFORM_WIN32_DIR}/win32_window.hpp
)

set(CORE_LINUX
  ${PLATFORM_LINUX_DIR}/linux_clock.hpp
  ${PLATFORM_LINUX_DIR}/linux_config.hpp
  ${PLATFORM_LINUX_DIR}/linux_file.cpp
  ${PLATFORM_LINUX_DIR}/linux_file.hpp
  ${PLATFORM_LINUX_DIR}/linux_filesystem.cpp
  ${PLATFORM_LINUX_DIR}/linux_filesystem.hpp
  ${PLATFORM_LINUX_DIR}/linux_network.cpp
  ${PLATFORM_LINUX_DIR}/linux_network.hpp
  ${PLATFORM_LINUX_DIR}/linux_platform.hpp
  ${PLATFORM_LINUX_DIR}/linux_thread.cpp
  ${PLATFORM_LINUX_DIR}/linux_thread.hpp
  ${PLATFORM_LINUX_DIR}/linux_window.cpp
  ${PLATFORM_LINUX_DIR}/linux_window.hpp
)


# none for apple yet... :c
set(CORE_APPLE
)

set(CORE_PLATFORM
  ${PLATFORM_PUBLIC_DIR}/clock.hpp
  ${PLATFORM_PUBLIC_DIR}/file.hpp
  ${PLATFORM_PUBLIC_DIR}/filesystem.hpp
  ${PLATFORM_PUBLIC_DIR}/hardware.hpp
  ${PLATFORM_PUBLIC_DIR}/network.hpp
  ${PLATFORM_PUBLIC_DIR}/platform.hpp
  ${PLATFORM_PUBLIC_DIR}/threading.hpp
  ${PLATFORM_PUBLIC_DIR}/timer.hpp
  ${PLATFORM_PUBLIC_DIR}/window.hpp
  ${PLATFORM_PUBLIC_DIR}/jtypes.hpp
  ${PLATFORM_PUBLIC_DIR}/api.hpp
)

# Operating System Dependent
if (WIN32)
  set(CORE_PLATFORM
    ${CORE_PLATFORM}
    ${CORE_WIN32}
  )
elseif(UNIX)
  set(CORE_PLATFORM
    ${CORE_PLATFORM}
    ${CORE_LINUX}
  )
else()
endif()


# logging stuff.
set(LOGGING_PUBLIC_DIR  ${CORE_LOGGING_DIR}/public)
set(LOGGING_PRIVATE_DIR ${CORE_LOGGING_DIR}/private)

set(CORE_LOGGING
  ${LOGGING_PUBLIC_DIR}/assertions.hpp
  ${LOGGING_PUBLIC_DIR}/debugging.hpp
  ${LOGGING_PUBLIC_DIR}/error_handler.hpp
  ${LOGGING_PUBLIC_DIR}/logger.hpp
  ${LOGGING_PUBLIC_DIR}/text_base.hpp
  ${LOGGING_PRIVATE_DIR}/debugging.cpp
  ${LOGGING_PRIVATE_DIR}/error_handler.cpp
  ${LOGGING_PRIVATE_DIR}/log_data.cpp
  ${LOGGING_PRIVATE_DIR}/log_data.hpp
  ${LOGGING_PRIVATE_DIR}/logger.cpp
)

# Memory dir.
set(MEMORY_PUBLIC_DIR   ${CORE_MEMORY_DIR}/public)
set(MEMORY_PRIVATE_DIR  ${CORE_MEMORY_DIR}/private)
set(MEMORY_ALLOCATORS_DIR ${MEMORY_PRIVATE_DIR}/allocators)

set(CORE_MEMORY
  ${MEMORY_PUBLIC_DIR}/allocator.hpp  
  ${MEMORY_PUBLIC_DIR}/memory_pool.hpp
  ${MEMORY_PUBLIC_DIR}/sptr.hpp
  ${MEMORY_PUBLIC_DIR}/stack_alloc.hpp
  ${MEMORY_PRIVATE_DIR}/memory_pool.cpp
  ${MEMORY_PRIVATE_DIR}/mem_leak_detection.hpp
  ${MEMORY_PRIVATE_DIR}/mem_leak_detection.cpp
  ${MEMORY_PRIVATE_DIR}/memory_alloc.hpp
  ${MEMORY_PRIVATE_DIR}/memory_alloc.cpp
)


set(FILE_GLOB
  ${CORE_MATH}
  ${CORE_PLATFORM}
  ${CORE_LOGGING}
  ${CORE_MEMORY}
)


if (${CMAKE_CXX_COMPILER_ID})
  # Doing some stuff for organization.
  if (MSVC)
    foreach(source IN LISTS FILE_GLOB)
      get_filename_component(source_path "${source}" PATH)
      string(REPLACE "/" "\\" source_path_msvc "${source_path}")
      source_group("${source_path_msvc}" FILES "${source}")
    endforeach()
  endif()
endif()

add_library(${JACKAL_CORE_NAME} STATIC
  ${FILE_GLOB}
)

