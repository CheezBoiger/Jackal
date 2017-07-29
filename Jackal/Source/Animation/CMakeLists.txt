cmake_minimum_required(VERSION 2.8)
project("Jackal-Animation")


set(JACKAL_ANIMATION_NAME         "Animation")
set(JACKAL_ANIMATION_PUBLIC_DIR   Public/Animation)
set(JACKAL_ANIMATION_PRIVATE_DIR  Private)

set(ANIMATION_FILES
)


add_library(${JACKAL_ANIMATION_NAME} STATIC
  ${ANIMATION_FILES}
)