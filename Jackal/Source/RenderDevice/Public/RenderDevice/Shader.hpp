// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

namespace jkl {


// Shader configuration. Abstract Shader.
class Shader {
public:
  enum Type {
    Vertex,
    Fragment,
    Geometry,
    Compute,
    TessEvaluation,
    TessControl,
  };

  virtual ~Shader();  

  Shader(Type shaderType);

protected:
  JString shaderName;
  Type    shaderType;
};
} // jkl