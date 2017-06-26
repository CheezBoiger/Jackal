// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Structure/JString.hpp"
#include "RenderDeviceTypes.hpp"


namespace jackal {


// Sampler Object.
class Sampler {
protected:
  WrapModeT WrapS;
  WrapModeT WrapT;
  FilterModeT FilterMode;

  Sampler() { }

public:
  virtual ~Sampler() { }
  virtual void Init() = 0;
};


// Texture object.
class Texture {
protected:
  Texture() : mMipmapped(false) { }

public:

  virtual ~Texture() { }


  // Load a file with the valid format.
  virtual void LoadTextureFile(const JString filepath, FormatT format) = 0;

  // Check if this texture is mipmapped.
  bool8 Mipmapped() { return mMipmapped; }

protected:
  bool8 mMipmapped;
};
} // jackal