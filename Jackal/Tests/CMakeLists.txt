# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("JackalTests")


# Enable some testing and linking of the googletest framework.
enable_testing()
set(GOOGLE_TEST_DIR ${JACKAL_THIRD_PARTY_DIR}/googletest/googletest)


# Test Programs. Let this test module know the name of the 
# Subdirectory you are planning to link to.
set(JACKAL_TEST_MAIN "JackalTestingFramework")
set(JACKAL_CORE_TESTS "JackalCoreTests")
set(JACKAL_TESTING_DIRECTORY "JackalTestDirectory")

include_directories(SYSTEM
  ${GOOGLE_TEST_DIR}/include
  ${GOOGLE_TEST_DIR}
)

# add test programs.
add_subdirectory(Core)

# Add in our executable, the field in which we will be using for testing.
add_executable(${JACKAL_TEST_MAIN}
  Main.cpp
)


if (WIN32)
  set_property(TARGET ${JACKAL_TEST_MAIN} PROPERTY FOLDER ${JACKAL_TESTING_DIRECTORY})
  message("Set Runtime Library to static for GoogleTesting")
endif()


# Link up our testing libraries.
target_link_libraries(${JACKAL_TEST_MAIN} ${JACKAL_CORE_TESTS})
target_link_libraries(${JACKAL_TEST_MAIN} gtest)

set_property(TARGET ${JACKAL_TEST_MAIN} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${JACKAL_TEST_MAIN} PROPERTY CXX_STANDARD_REQUIRED 14)
