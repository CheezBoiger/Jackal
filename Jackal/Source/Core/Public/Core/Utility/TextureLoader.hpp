// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Api.hpp"


namespace jackal {


// Texture Handle object, used to get the texture handle of the 
// file that was loaded.
struct TextureHandle {
  // Width, height, and channels of the texture that was loaded.
  int32 width; 
  int32 height;
  int32 channels;
  
  // Data of the texture handle. This is allocated on the heap,
  // so be sure to destroy by calling the texture loader after use.
  ubyte *data;
};

// Texture Loader singleton responsible for loading any textures at handle.
class TextureLoader {
public:

  // Load a file with the texture handle. Returns empty data 
  // if file was not loaded successfully.
  static TextureHandle LoadFile(const char *filepath);

  // Destroy a texture handle of the file loader. Makes 
  // the texture data null and 0'd when successful.
  static void DestroyHandle(TextureHandle &handle);
};
} // jackal

