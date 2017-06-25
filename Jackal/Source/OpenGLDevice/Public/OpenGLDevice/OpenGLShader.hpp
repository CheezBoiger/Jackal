// Copyright (c) 2017 Jackal Engine. MIT License.
#pragma once

#include "RenderDevice/Shader.hpp"
#include "OpenGLConfigs.hpp"


namespace jackal {


// OpenGL Shader object.
class OpenGLShader : public Shader {
  static const tchar *shaderLanguage;
public:
  OpenGLShader(const JString name = JTEXT("Default-OpenGLShader"),
    const JString filepath = JTEXT(""));
  
  // Get the UID of this opengl object.
  GLuint GetUID() const { return id; }

  // Shader language type of this object.
  const tchar *ShaderLanguage() const override { return shaderLanguage; }
    
  // Compile the shader script for GLSL.
  bool8 Compile(const JString filepath,
    std::vector<JString> includes = std::vector<JString>(),
    std::vector<JString> defines = std::vector<JString>()
  ) override;

private:

  GLuint id;
};
} // jackal