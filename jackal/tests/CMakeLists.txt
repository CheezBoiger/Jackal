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
)

# add test programs.
add_subdirectory(core)


add_executable(${JACKAL_TEST_MAIN}
  main.cpp
)

target_link_libraries(${JACKAL_TEST_MAIN} ${JACKAL_CORE_TESTS})
target_link_libraries(${JACKAL_TEST_MAIN} gtest)