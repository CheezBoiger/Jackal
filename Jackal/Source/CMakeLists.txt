# Copyright (c) 2017, Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalEngineModules")


# Setting the jackal overall name and the description.
# This is a modern implementation of our engine, going in the 
# way of overall power of the machine.
set(JACKAL_NAME        "Jackal" CACHE STRING "")
set(JACKAL_DESCRIPTION "Jackal Open Source Game Engine" CACHE STRING "")

include(Packages)

# Find our packages We might include these in a separate cmake folder in the long run.
find_package(OpenAL)
find_package(Vulkan)
find_package(OpenGL)

if (NOT Vulkan_FOUND)
 # Fail safe for finding vulkan.
endif()

if (NOT OPENAL_FOUND)
  message(WARNING "OpenAL not found!")
endif()

# Include the setup for our engine.
include (Setup)

