// Copyright (c) 2017 Jackal Engine. MIT License.
#pragma once

#include "RenderDevice/Shader.hpp"
#include "OpenGLConfigs.hpp"


namespace jackal {


// OpenGL Shader object.
class OpenGLShader : public Shader {
  static const char *shaderLanguage;
public:
  static GLenum GetNativeShaderType(ShaderType type);

  OpenGLShader()
    : mNativeShaderType(GL_NONE)
    , handle(0) { }
  
  // Get the UID of this opengl object.
  GLuint GetHandle() const { return handle; }

  GLenum GetNativeType() const { return mNativeShaderType; }

  // Shader language type of this object.
  const char *ShaderLanguage() const override { return shaderLanguage; }
    
  // Compile the shader script for GLSL.
  bool8 Compile(ShaderType type, const NativeString sourceCode,
    const std::vector<NativeString> includes = std::vector<NativeString>(),
    const std::vector<NativeString> defines = std::vector<NativeString>()
  ) override;

  void CleanUp() override;

private:
  // Parse the source code from the filepath.
  NativeString ParseSource(NativeString source, std::vector<NativeString> includes,
    std::vector<NativeString> defines);

  GLenum mNativeShaderType;
  GLuint handle;
};
} // jackal