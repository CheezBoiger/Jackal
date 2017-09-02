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
  virtual bool8 Compile(ShaderType type, const NativeString sourceCode, 
    const std::vector<NativeString> includes,
    const std::vector<NativeString> defines) = 0;

  // Ingest binary, as opposed to compiling the shader source code.
  virtual bool8 IngestBinary(ShaderType type, const char* entryPoint, const NativeString byteCode) = 0;

  // Get the shader language type of this shader object.
  virtual const char *ShaderLanguage() const = 0;

  // Clean up the shader object before destroying.
  virtual void CleanUp() = 0;

  ShaderType Type() const { return mShaderType; }
  bool8 Compiled() const { return compiled; }

  static NativeString ParseFile(NativeString filepath);

  
protected:
  ShaderType    mShaderType;
  bool8         compiled;
};
} // jackal