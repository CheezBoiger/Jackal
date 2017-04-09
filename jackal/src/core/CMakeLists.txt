#
# Copyright (c) 2017 Jackal Engine, under the MIT License.
#
cmake_minimum_required(VERSION 2.8.11)
project("JackalCore")

set(JACKAL_CORE_VERSION     0)
set(JACKAL_CORE_NAME "Jackal-Core" CACHE STRING "Name of the Game Engine Core.")


set(JACKAL_CORE_DIR                  ${CMAKE_CURRENT_SOURCE_DIR})
set(CORE_PUBLIC_MATH_DIR             public/math)
set(CORE_PUBLIC_MEMORY_DIR           public/memory)
set(CORE_PUBLIC_PLATFORM_DIR         public/platform)
set(CORE_PUBLIC_TEMPLATES_DIR        public/templates)
set(CORE_PUBLIC_LOGGING_DIR          public/logging)
set(CORE_PRIVATE_MATH_DIR            public/math)
set(CORE_PRIVATE_MEMORY_DIR          private/memory)
set(CORE_PRIVATE_PLATFORM_DIR        private/platform)
set(CORE_PRIVATE_LOGGING_DIR         private/logging)


# Math Directories.
set(MATH_PUBLIC_INTERNAL_DIR       ${CORE_PUBLIC_MATH_DIR}/internal)
set(MATH_PUBLIC_BOUNDING_DIR       ${CORE_PUBLIC_MATH_DIR}/bounding)

set(CORE_MATH
  ${CORE_PUBLIC_MATH_DIR}/common.hpp
  ${CORE_PUBLIC_MATH_DIR}/matrix.hpp
  ${CORE_PUBLIC_MATH_DIR}/quaternion.hpp
  ${CORE_PUBLIC_MATH_DIR}/ray.hpp
  ${CORE_PUBLIC_MATH_DIR}/vector.hpp
  ${CORE_PUBLIC_MATH_DIR}/matrix_math.hpp
  ${CORE_PUBLIC_MATH_DIR}/vector_math.hpp
  ${CORE_PUBLIC_MATH_DIR}/quaternion_math.hpp
  ${MATH_PUBLIC_INTERNAL_DIR}/matrix.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/matrix_math.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/vector.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/vector_math.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/quaternion.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/quaternion_math.inl
  ${MATH_PUBLIC_BOUNDING_DIR}/bound_box.hpp
  ${MATH_PUBLIC_BOUNDING_DIR}/bound_cylinder.hpp
  ${MATH_PUBLIC_BOUNDING_DIR}/bound_sphere.hpp
)

# Platform Work.
set(PLATFORM_WIN32_DIR       ${CORE_PRIVATE_PLATFORM_DIR}/win32)
set(PLATFORM_LINUX_DIR       ${CORE_PRIVATE_PLATFORM_DIR}/linux)
set(PLATFORM_APPLE_DIR       ${CORE_PRIVATE_PLATFORM_DIR}/apple)

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
  ${CORE_PUBLIC_PLATFORM_DIR}/clock.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/file.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/filesystem.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/hardware.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/network.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/platform.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/threading.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/timer.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/window.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/jtypes.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/api.hpp
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
set(CORE_LOGGING
  ${CORE_PUBLIC_LOGGING_DIR}/assertions.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/debugging.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/error_handler.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/logger.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/text_base.hpp
  ${CORE_PRIVATE_LOGGING_DIR}/debugging.cpp
  ${CORE_PRIVATE_LOGGING_DIR}/error_handler.cpp
  ${CORE_PRIVATE_LOGGING_DIR}/log_data.cpp
  ${CORE_PRIVATE_LOGGING_DIR}/log_data.hpp
  ${CORE_PRIVATE_LOGGING_DIR}/logger.cpp
)

# Memory dir.

set(CORE_MEMORY
  ${CORE_PUBLIC_MEMORY_DIR}/allocator.hpp  
  ${CORE_PUBLIC_MEMORY_DIR}/memory_pool.hpp
  ${CORE_PUBLIC_MEMORY_DIR}/sptr.hpp
  ${CORE_PUBLIC_MEMORY_DIR}/stack_alloc.hpp
  ${CORE_PRIVATE_MEMORY_DIR}/memory_pool.cpp
  ${CORE_PRIVATE_MEMORY_DIR}/mem_leak_detection.hpp
  ${CORE_PRIVATE_MEMORY_DIR}/mem_leak_detection.cpp
  ${CORE_PRIVATE_MEMORY_DIR}/memory_alloc.hpp
  ${CORE_PRIVATE_MEMORY_DIR}/memory_alloc.cpp
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

include_directories(SYSTEM
  ${JACKAL_CORE_DIR}/public
)

