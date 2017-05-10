cmake_minimum_required(VERSION 2.8.11)
project("JackalTests")


enable_testing()
set(GOOGLE_TEST_DIR ${JACKAL_THIRD_PARTY_DIR}/googletest/googletest)


# Test Programs. Let this test module know the name of the 
# Subdirectory you are planning to link to.
set(JACKAL_TEST_MAIN "JackalTestingFramework")
set(JACKAL_CORE_TESTS "JackalCoreTests")

include_directories(SYSTEM
  ${GOOGLE_TEST_DIR}/include
  ${GOOGLE_TEST_DIR}
)

# add test programs.
add_subdirectory(Core)





add_executable(${JACKAL_TEST_MAIN}
  Main.cpp
)


if (WIN32)
  set_target_properties(${JACKAL_TEST_MAIN} PROPERTIES COMPILE_FLAGS ${MSVC_BUILD_FLAGS})
  message("Set Runtime Library to static for GoogleTesting")
endif()


target_link_libraries(${JACKAL_TEST_MAIN} ${JACKAL_CORE_TESTS})
target_link_libraries(${JACKAL_TEST_MAIN} gtest)