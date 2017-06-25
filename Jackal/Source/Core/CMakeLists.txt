# Copyright (c) 2017 Jackal Engine, under the MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalCore")

# Set up the core versioning.
set(JACKAL_BUILD_CORE_VERSION     0)
set(JACKAL_CORE_NAME "Jackal-Core" CACHE STRING "Name of the Game Engine Core.")

set(CORE_PUBLIC_MATH_DIR             Public/Core/Math)
set(CORE_PUBLIC_MEMORY_DIR           Public/Core/Memory)
set(CORE_PUBLIC_PLATFORM_DIR         Public/Core/Platform)
set(CORE_PUBLIC_TEMPLATES_DIR        Public/Core/Templates)
set(CORE_PUBLIC_LOGGING_DIR          Public/Core/Logging)
set(CORE_PUBLIC_WIN32_DIR            Public/Core/Win32)
set(CORE_PUBLIC_LINUX_DIR            Public/Core/Linux)
set(CORE_PUBLIC_APPLE_DIR            Public/Core/Apple)
set(CORE_PUBLIC_STRUCTURE_DIR        Public/Core/Structure)
set(CORE_PUBLIC_UTILITY_DIR          Public/Core/Utility)
set(CORE_PUBLIC_INTRN_DIR            Public/Core/Internationalization)
set(CORE_PRIVATE_INTRN_DIR           Private/Internationalization)
set(CORE_PRIVATE_MATH_DIR            Private/Math)
set(CORE_PRIVATE_MEMORY_DIR          Private/Memory)
set(CORE_PRIVATE_PLATFORM_DIR        Private/Platform)
set(CORE_PRIVATE_LOGGING_DIR         Private/Logging)
set(CORE_PRIVATE_WIN32_DIR           Private/Win32)
set(CORE_PRIVATE_LINUX_DIR           Private/Linux)
set(CORE_PRIVATE_APPLE_DIR           Private/Apple)
set(CORE_PRIVATE_STRUCTURE_DIR       Private/Structure)
set(CORE_PRIVATE_UTILITY_DIR         Private/Utility)

# Math Directories.
set(MATH_PUBLIC_INTERNAL_DIR       ${CORE_PUBLIC_MATH_DIR}/Internal)
set(MATH_PUBLIC_BOUNDING_DIR       ${CORE_PUBLIC_MATH_DIR}/Bounding)
set(MATH_PRIVATE_BOUNDING_DIR      ${CORE_PRIVATE_MATH_DIR}/Bounding)

set(CORE_MATH
  ${CORE_PUBLIC_MATH_DIR}/Common.hpp
  ${CORE_PUBLIC_MATH_DIR}/Matrix4.hpp
  ${CORE_PUBLIC_MATH_DIR}/Matrix3.hpp
  ${CORE_PUBLIC_MATH_DIR}/Matrix2.hpp
  ${CORE_PUBLIC_MATH_DIR}/Quaternion.hpp
  ${CORE_PUBLIC_MATH_DIR}/Ray.hpp
  ${CORE_PUBLIC_MATH_DIR}/Color4.hpp
  ${CORE_PUBLIC_MATH_DIR}/Vector4.hpp
  ${CORE_PUBLIC_MATH_DIR}/Vector3.hpp
  ${CORE_PUBLIC_MATH_DIR}/Vector2.hpp
  ${CORE_PUBLIC_MATH_DIR}/MatrixMath.hpp
  ${CORE_PUBLIC_MATH_DIR}/VectorMath.hpp
  ${CORE_PUBLIC_MATH_DIR}/QuaternionMath.hpp
  ${CORE_PRIVATE_MATH_DIR}/Color4.cpp
  ${CORE_PRIVATE_MATH_DIR}/Matrix4.cpp
  ${CORE_PRIVATE_MATH_DIR}/Matrix3.cpp
  ${CORE_PRIVATE_MATH_DIR}/Matrix2.cpp
  ${CORE_PRIVATE_MATH_DIR}/MatrixMath.cpp
  ${CORE_PRIVATE_MATH_DIR}/Vector4.cpp
  ${CORE_PRIVATE_MATH_DIR}/Vector3.cpp
  ${CORE_PRIVATE_MATH_DIR}/Vector2.cpp
  ${CORE_PRIVATE_MATH_DIR}/VectorMath.cpp
  ${CORE_PRIVATE_MATH_DIR}/Quaternion.cpp
  ${CORE_PRIVATE_MATH_DIR}/QuaternionMath.cpp
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
  ${CORE_PRIVATE_WIN32_DIR}/Win32Clock.cpp
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
  ${CORE_PUBLIC_STRUCTURE_DIR}/HTable.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/Queue.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/Stack.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/DList.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/SList.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/PriorityQueue.hpp
  ${CORE_PUBLIC_STRUCTURE_DIR}/JIterator.hpp
)


set(CORE_UTILITY
  ${CORE_PUBLIC_UTILITY_DIR}/JStringUtils.hpp
  ${CORE_PRIVATE_UTILITY_DIR}/JStringUtils.cpp
)


set(CORE_INTERNATIONALIZATION
  ${CORE_PUBLIC_INTRN_DIR}/Locale.hpp
  ${CORE_PRIVATE_INTRN_DIR}/Locale.cpp
)


set(FILE_GLOB
  ${CORE_MATH}
  ${CORE_PLATFORM}
  ${CORE_LOGGING}
  ${CORE_MEMORY}
  ${CORE_STRUCTURE}
  ${CORE_UTILITY}
  ${CORE_INTERNATIONALIZATION}
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


# Need to link our Core with xlib libraries.
if (UNIX)
 # X11 is required in order to run windows on Linux
 # We will be linking xcb to use as well, yet this may not be required since
 # xlib may already have linked it.
 find_package(X11 REQUIRED)
 find_package(XCB REQUIRED)
 find_package(X11_XCB REQUIRED)
 
 target_link_libraries(${JACKAL_CORE_NAME} ${X11_LIBRARIES} ${XCB_LIBRARIES} ${X11_XCB_LIBRARIES})
 include_directories(${X11_INCLUDE_DIR} ${XCB_INCLUDE_DIRS} ${X11_XCB_INCLUDE_DIR})
endif()
# Link glfw for testing and implementation. This is used temporarily.
target_link_libraries(${JACKAL_CORE_NAME} glfw)

# Set the preprocessor directives as well. Make them public to show onto other modules
# that link to our core.
target_compile_definitions(${JACKAL_CORE_NAME} PUBLIC JACKAL_CORE_VERSION=${JACKAL_BUILD_CORE_VERSION})

if (WIN32)
  set_property(TARGET   ${JACKAL_CORE_NAME} PROPERTY   FOLDER ${JACKAL_ENGINE_DIRECTORY})
endif()

include_directories(SYSTEM
  ${JACKAL_THIRD_PARTY_DIR}/glfw/include
  ${JACKAL_INCLUDE_DIR}
)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# Utility for setting our standard.
include(Macros)

# Set the C++ standard for GCC compilers
set_cxx_standard(${JACKAL_CORE_NAME} 14)
