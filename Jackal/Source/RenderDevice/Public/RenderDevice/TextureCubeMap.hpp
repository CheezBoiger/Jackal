// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Utility/TextureLoader.hpp"

#include "RenderDeviceTypes.hpp"
#include "RenderObject.hpp"


namespace jackal {


// CubeMap Texture object.
class CubeMap : public RenderObject {
protected:
  CubeMap()
    : mName("Default_Texture") { }

public:

  virtual ~CubeMap() { }


  TextureT TextureType() {
    static const TextureT type = TEXTURE_CUBE;
    return type;
  }


  // Load textures into this texture object, for use in the rendering
  // api. Must load 6 faces, or texture handles.
  // The order of the handles must be:
  //
  virtual void Load(TextureInfoT &info, TextureHandle *textures) = 0;
  virtual void CleanUp() = 0;

  void SetName(JString n) { mName = n; }
  TextureInfoT *GetInfomation() { return &mInformation; }

protected:
  JString      mName;
  TextureInfoT mInformation;
};
} // jackal