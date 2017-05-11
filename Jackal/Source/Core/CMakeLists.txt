# Copyright (c) 2017 Jackal Engine, under the MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalCore")

# Set up the core versioning.
set(JACKAL_BUILD_CORE_VERSION     0)
set(JACKAL_CORE_NAME "Jackal-Core" CACHE STRING "Name of the Game Engine Core.")


set(JACKAL_CORE_DIR                  ${CMAKE_CURRENT_SOURCE_DIR})
set(CORE_PUBLIC_MATH_DIR             Public/Math)
set(CORE_PUBLIC_MEMORY_DIR           Public/Memory)
set(CORE_PUBLIC_PLATFORM_DIR         Public/Platform)
set(CORE_PUBLIC_TEMPLATES_DIR        Public/Templates)
set(CORE_PUBLIC_LOGGING_DIR          Public/Logging)
set(CORE_PUBLIC_WIN32_DIR            Public/Win32)
set(CORE_PUBLIC_LINUX_DIR            Public/Linux)
set(CORE_PUBLIC_APPLE_DIR            Public/Apple)
set(CORE_PUBLIC_STRUCTURE_DIR        Public/Structure)
set(CORE_PRIVATE_MATH_DIR            Private/Math)
set(CORE_PRIVATE_MEMORY_DIR          Private/Memory)
set(CORE_PRIVATE_PLATFORM_DIR        Private/Platform)
set(CORE_PRIVATE_LOGGING_DIR         Private/Logging)
set(CORE_PRIVATE_WIN32_DIR           Private/Win32)
set(CORE_PRIVATE_LINUX_DIR           Private/Linux)
set(CORE_PRIVATE_APPLE_DIR           Private/Apple)
set(CORE_PRIVATE_STRUCTURE_DIR       Private/Structure)


# Math Directories.
set(MATH_PUBLIC_INTERNAL_DIR       ${CORE_PUBLIC_MATH_DIR}/Internal)
set(MATH_PUBLIC_BOUNDING_DIR       ${CORE_PUBLIC_MATH_DIR}/Bounding)
set(MATH_PRIVATE_BOUNDING_DIR      ${CORE_PRIVATE_MATH_DIR}/Bounding)

set(CORE_MATH
  ${CORE_PUBLIC_MATH_DIR}/Common.hpp
  ${CORE_PUBLIC_MATH_DIR}/Matrix.hpp
  ${CORE_PUBLIC_MATH_DIR}/Quaternion.hpp
  ${CORE_PUBLIC_MATH_DIR}/Ray.hpp
  ${CORE_PUBLIC_MATH_DIR}/Vector.hpp
  ${CORE_PUBLIC_MATH_DIR}/MatrixMath.hpp
  ${CORE_PUBLIC_MATH_DIR}/VectorMath.hpp
  ${CORE_PUBLIC_MATH_DIR}/QuaternionMath.hpp
  ${MATH_PUBLIC_INTERNAL_DIR}/Matrix.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/MatrixMath.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/Vector.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/VectorMath.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/Quaternion.inl
  ${MATH_PUBLIC_INTERNAL_DIR}/QuaternionMath.inl
  ${MATH_PUBLIC_BOUNDING_DIR}/BoundBox2D.hpp
  ${MATH_PUBLIC_BOUNDING_DIR}/BoundBox3D.hpp
  ${MATH_PUBLIC_BOUNDING_DIR}/BoundCylinder.hpp
  ${MATH_PUBLIC_BOUNDING_DIR}/BoundSphere.hpp
  ${MATH_PUBLIC_BOUNDING_DIR}/BoundCapsule.hpp
  ${MATH_PUBLIC_BOUNDING_DIR}/BoundMesh.hpp
  ${MATH_PRIVATE_BOUNDING_DIR}/BoundBox2D.cpp
  ${MATH_PRIVATE_BOUNDING_DIR}/BoundBox3D.cpp
  ${MATH_PRIVATE_BOUNDING_DIR}/BoundSphere.cpp
  ${MATH_PRIVATE_BOUNDING_DIR}/BoundCylinder.cpp
  ${MATH_PRIVATE_BOUNDING_DIR}/BoundCapsule.cpp
  ${MATH_PRIVATE_BOUNDING_DIR}/BoundMesh.cpp
)

# Platform Work.
set(CORE_WIN32
  ${CORE_PUBLIC_WIN32_DIR}/Win32Clock.hpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32Config.hpp
  ${CORE_PRIVATE_WIN32_DIR}/Win32File.cpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32File.hpp
  ${CORE_PRIVATE_WIN32_DIR}/Win32Filesystem.cpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32Filesystem.hpp
  ${CORE_PRIVATE_WIN32_DIR}/Win32Network.cpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32Network.hpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32Platform.hpp
  ${CORE_PRIVATE_WIN32_DIR}/Win32Thread.cpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32Thread.hpp
  ${CORE_PRIVATE_WIN32_DIR}/Win32Window.cpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32Window.hpp
  ${CORE_PUBLIC_WIN32_DIR}/Win32Mouse.hpp
  ${CORE_PRIVATE_WIN32_DIR}/Win32Mouse.cpp
)

set(CORE_LINUX
  ${CORE_PUBLIC_LINUX_DIR}/LinuxClock.hpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxConfig.hpp
  ${CORE_PRIVATE_LINUX_DIR}/LinuxFile.cpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxFile.hpp
  ${CORE_PRIVATE_LINUX_DIR}/LinuxFilesystem.cpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxFilesystem.hpp
  ${CORE_PRIVATE_LINUX_DIR}/LinuxNetwork.cpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxNetwork.hpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxPlatform.hpp
  ${CORE_PRIVATE_LINUX_DIR}/LinuxThread.cpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxThread.hpp
  ${CORE_PRIVATE_LINUX_DIR}/LinuxWindow.cpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxWindow.hpp
  ${CORE_PUBLIC_LINUX_DIR}/LinuxMouse.hpp
  ${CORE_PRIVATE_LINUX_DIR}/LinuxMouse.cpp
)


# none for apple yet... :c
set(CORE_APPLE
)

set(CORE_PLATFORM
  ${CORE_PUBLIC_PLATFORM_DIR}/Clock.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/File.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Filesystem.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Hardware.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Network.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Platform.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Threading.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Timer.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Window.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/JTypes.hpp
  ${CORE_PUBLIC_PLATFORM_DIR}/Api.hpp
  ${CORE_PRIVATE_PLATFORM_DIR}/Window.cpp
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
  ${CORE_PUBLIC_LOGGING_DIR}/Assertions.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/Debugging.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/ErrorHandler.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/Logger.hpp
  ${CORE_PUBLIC_LOGGING_DIR}/TextBase.hpp
  ${CORE_PRIVATE_LOGGING_DIR}/Debugging.cpp
  ${CORE_PRIVATE_LOGGING_DIR}/ErrorHandler.cpp
  ${CORE_PRIVATE_LOGGING_DIR}/LogData.cpp
  ${CORE_PRIVATE_LOGGING_DIR}/LogData.hpp
  ${CORE_PRIVATE_LOGGING_DIR}/Logger.cpp
)

# Memory dir.

set(CORE_MEMORY
  ${CORE_PUBLIC_MEMORY_DIR}/Allocator.hpp  
  ${CORE_PUBLIC_MEMORY_DIR}/MemoryPool.hpp
  ${CORE_PUBLIC_MEMORY_DIR}/SPtr.hpp
  ${CORE_PUBLIC_MEMORY_DIR}/StackAlloc.hpp
  ${CORE_PUBLIC_MEMORY_DIR}/JMalloc.hpp
  ${CORE_PRIVATE_MEMORY_DIR}/MemoryPool.cpp
  ${CORE_PRIVATE_MEMORY_DIR}/MemLeakDetection.hpp
  ${CORE_PRIVATE_MEMORY_DIR}/MemLeakDetection.cpp
  ${CORE_PRIVATE_MEMORY_DIR}/MemoryAlloc.hpp
  ${CORE_PRIVATE_MEMORY_DIR}/MemoryAlloc.cpp
  ${CORE_PRIVATE_MEMORY_DIR}/JMalloc.cpp
)

# Structure dir
set(CORE_STRUCTURE
  ${CORE_PUBLIC_STRUCTURE_DIR}/JString.hpp
  ${CORE_PRIVATE_STRUCTURE_DIR}/JString.cpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/JVector.hpp
  ${CORE_PRIVATE_STRUCTURE_DIR}/JVector.inl
  ${CORE_PUBLIC_STRUCTURE_DIR}/HTable.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/Queue.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/Stack.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/DList.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/SList.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/PriorityQueue.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/JIterator.hpp
  ${CORE_PRIVATE_STRUCTURE_DIR}/HTable.inl
  ${CORE_PRIVATE_STRUCTURE_DIR}/Queue.inl
  ${CORE_PRIVATE_STRUCTURE_DIR}/Stack.inl
  ${CORE_PRIVATE_STRUCTURE_DIR}/DList.inl
  ${CORE_PRIVATE_STRUCTURE_DIR}/SList.inl
  ${CORE_PRIVATE_STRUCTURE_DIR}/PriorityQueue.inl
  ${CORE_PRIVATE_STRUCTURE_DIR}/JIterator.inl
)


set(FILE_GLOB
  ${CORE_MATH}
  ${CORE_PLATFORM}
  ${CORE_LOGGING}
  ${CORE_MEMORY}
  ${CORE_STRUCTURE}
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


# Actual library we are building.
add_library(${JACKAL_CORE_NAME} STATIC
  ${FILE_GLOB}
)

# Link glfw for testing and implementation. This is used temporarily.
target_link_libraries(${JACKAL_CORE_NAME} glfw)

# Set the preprocessor directives as well. Make them public to show onto other modules
# that link to our core.
target_compile_definitions(${JACKAL_CORE_NAME} PUBLIC JACKAL_CORE_VERSION=${JACKAL_BUILD_CORE_VERSION})

if (WIN32)
  set_target_properties(${JACKAL_CORE_NAME} PROPERTIES COMPILE_FLAGS ${MSVC_BUILD_FLAGS})
  set_property(TARGET   ${JACKAL_CORE_NAME} PROPERTY   FOLDER ${JACKAL_ENGINE_DIRECTORY})
endif()

include_directories(SYSTEM
  ${JACKAL_THIRD_PARTY_DIR}/glfw/include
  ${JACKAL_CORE_DIR}/Public
)

