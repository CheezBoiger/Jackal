// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

#include <vector>


namespace jackal {


// Shader configuration. Abstract Shader. Used overall throughout the
// implmentation of the Rendering Device.
class Shader {
protected:
  // Shader constructor.
  Shader(const JString name = JTEXT("Default"),
    const JString filepath = JTEXT(""));

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

  // Compiles the shader. This is dependent on the rendering api. 
  virtual bool8 Compile(const JString filepath, 
    const std::vector<JString> includes = std::vector<JString>(),
    const std::vector<JString> defines = std::vector<JString>()) = 0;

  // Get the shader language type of this shader object.
  virtual const tchar *ShaderLanguage() const = 0;

  Type ShaderType() const { return mShaderType; }
  JString &Name() { return mShaderName; }
  bool8 Compiled() const { return compiled; }

  
protected:
  JString mShaderName;
  Type    mShaderType;
  bool8   compiled;
};
} // jackal