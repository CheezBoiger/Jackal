cmake_minimum_required(VERSION 2.8.11)
project("JackalEngineModules")

set(JACKAL_NAME        "Jackal" CACHE STRING "")
set(JACKAL_DESCRIPTION "Jackal Open Source Game Engine" CACHE STRING "")



if (NOT vulkan_FOUND)
endif()

if (NOT OPENAL_FOUND)
  message(WARNING "OpenAL not found!")
endif()

include (cmake/setup.cmake)

