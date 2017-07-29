cmake_minimum_required(VERSION 2.8)
project("Canis-ShaderCompiler")


set(JACKAL_SHADER_COMPILER_NAME "Canis-Compiler")
set(JACKAL_CANIS_PUBLIC_DIR   Public/Canis)
set(JACKAL_CANIS_PRIVATE_DIR  Private)


set(CANIS_FILES
)



add_library(${JACKAL_SHADER_COMPILER_NAME} STATIC
  ${CANIS_FILES}
)


