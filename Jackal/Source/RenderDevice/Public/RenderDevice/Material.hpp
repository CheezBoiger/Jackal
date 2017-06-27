// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Math/Matrix4.hpp"
#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix2.hpp"
#include "Texture.hpp"


namespace jackal {


// Material Object, which specifies descriptor sets for 
// some given context on the rendering pipeline.
class Material {
public:
  virtual ~Material() { }
};
} // jackal