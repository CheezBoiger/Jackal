// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Utility/TextureLoader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"


namespace jackal {


TextureHandle TextureLoader::LoadFile(const char *filepath)
{
  TextureHandle handle = { 0, 0, 0, nullptr };
  ubyte *dat = stbi_load(filepath, &handle.width, &handle.height, &handle.channels, 0);

  handle.data = dat;
  return handle;
}


void TextureLoader::DestroyHandle(TextureHandle &handle)
{
  stbi_image_free(handle.data);
  handle.width = 0;
  handle.height = 0;
  handle.channels = 0;
  handle.data = nullptr;
}
} // jackal