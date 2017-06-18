# Copyright (c) 2017 Jackal Engine, MIT License.
cmake_minimum_required(VERSION 2.8.11)
project("Jackal-Profiler")

set(JACKAL_PROFILER_PUBLIC_DIR    Public/Profiler)
set(JACKAL_PROFILER_PRIVATE_DIR   Private)
set(JACKAL_PROFILER               "JackalProfiler")



set(JACKAL_PROFILER_FILES

)

add_library(${JACKAL_PROFILER} STATIC
  ${JACKAL_PROFILER_FILES}
)