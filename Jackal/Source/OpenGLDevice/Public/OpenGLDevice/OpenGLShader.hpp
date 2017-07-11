// Copyright (c) 2017 Jackal Engine. MIT License.
#pragma once

#include "RenderDevice/Shader.hpp"
#include "OpenGLConfigs.hpp"


namespace jackal {


// OpenGL Shader object.
class OpenGLShader : public Shader {
  static const tchar *shaderLanguage;
public:
  static GLenum GetNativeShaderType(ShaderType type);

  OpenGLShader()
    : mNativeShaderType(GL_NONE)
    , handle(0) { }
  
  // Get the UID of this opengl object.
  GLuint GetHandle() const { return handle; }

  GLenum GetNativeType() const { return mNativeShaderType; }

  // Shader language type of this object.
  const tchar *ShaderLanguage() const override { return shaderLanguage; }
    
  // Compile the shader script for GLSL.
  bool8 Compile(ShaderType type, const JString filepath,
    const std::vector<JString> includes = std::vector<JString>(),
    const std::vector<JString> defines = std::vector<JString>()
  ) override;

  void CleanUp() override;

private:
  // Parse the source code from the filepath.
  JString ParseSource(JString filepath, std::vector<JString> includes,
    std::vector<JString> defines);

  GLenum mNativeShaderType;
  GLuint handle;
};
} // jackal