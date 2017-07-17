// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Structure/JString.hpp"
#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"


namespace jackal {


struct ShaderInfoT {
  WrapModeT   WrapS;
  WrapModeT   WrapT;
  WrapModeT   WrapR;
  FilterModeT FilterMode;
};


// Sampler Object.
class Sampler : public RenderObject {
protected:
  WrapModeT WrapS;
  WrapModeT WrapT;
  FilterModeT FilterMode;

  Sampler() { }

public:
  virtual ~Sampler() { }
  virtual void Bake() = 0;
  virtual JString GetName() = 0;
};


// Texture object.
class Texture : public RenderObject {
protected:
  Texture() : mMipmapped(false) { }

public:

  virtual ~Texture() { }


  // Load a file with the valid format.
  virtual void LoadTextureFile(const JString filepath, FormatT format) = 0;

  void SetName(JString n) { name = n; }

  // Check if this texture is mipmapped.
  bool8 Mipmapped() { return mMipmapped; }

protected:
  JString name;
  bool8 mMipmapped;
};
} // jackal