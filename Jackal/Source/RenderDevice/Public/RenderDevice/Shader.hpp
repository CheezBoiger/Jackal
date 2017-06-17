// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

namespace jkl {


// Shader configuration. Abstract Shader. Used overall throughout the
// implmentation of the Rendering Device.
class Shader {
public:
  enum Type {
    None,
    Vertex,
    Fragment,
    Geometry,
    Compute,
    TessEvaluation,
    TessControl,
    Pixel = Fragment,
    Hull = TessControl,
    Domain = TessEvaluation
  };

  virtual ~Shader() { }

  Shader(const JString name = JTEXT("Default"),
        const JString filepath = JTEXT(""));

  // Compiles the shader. This is dependent on the rendering api. 
  virtual bool8 Compile(const JString filepath) = 0;

  JString &SourceCode() const;

  Type ShaderType() const { return shaderType; }
  JString Name() const { return shaderName; }
  bool8 Compiled() const { return compiled; }

  
protected:
  JString shaderName;
  Type    shaderType;
  bool8   compiled;
};
} // jkl