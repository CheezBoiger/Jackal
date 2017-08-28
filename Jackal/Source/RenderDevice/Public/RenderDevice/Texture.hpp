// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Utility/TextureLoader.hpp"

#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"


namespace jackal {


// 1D Texture Object.
class Texture : public RenderObject {
protected:
  Texture() { }

public:

  virtual ~Texture() { }

  TextureT TextureType() { 
    static const TextureT type = TEXTURE_1D;
    return type;
  }

  // Load textures into this texture object, for use in the rendering
  // api.
  virtual void Load(TextureInfoT &info, TextureHandle *texture) = 0;
  
  virtual void CleanUp() = 0;
};
} // jackal