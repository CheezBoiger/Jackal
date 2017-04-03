cmake_minimum_required(VERSION 2.8.11)
project("JackalTests")


#add_subdirectory(../thirdparty/googletest)
add_subdirectory(core)


add_executable(JackalTestingFramework
  main.cpp
)


target_link_libraries(JackalTestingFramework JackalCoreTests)