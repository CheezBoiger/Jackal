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
public:
  enum ShaderType {
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

protected:
  // Shader constructor.
  Shader()
    : compiled(false)
    , mShaderType(None) { }

public:

  virtual ~Shader() { }

  // Compiles the shader. This is dependent on the rendering api. 
  virtual bool8 Compile(ShaderType type, const JString filepath, 
    const std::vector<JString> includes,
    const std::vector<JString> defines) = 0;

  // Get the shader language type of this shader object.
  virtual const tchar *ShaderLanguage() const = 0;

  // Clean up the shader object before destroying.
  virtual void CleanUp() = 0;

  ShaderType Type() const { return mShaderType; }
  bool8 Compiled() const { return compiled; }

  
protected:
  ShaderType    mShaderType;
  bool8         compiled;
};
} // jackal