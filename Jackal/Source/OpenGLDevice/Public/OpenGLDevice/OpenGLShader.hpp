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
  
  GLuint GetUID() const { return id; }

  const tchar *ShaderLanguage() const override { return shaderLanguage; }
  bool8 Compile(const JString filepath) override;

private:

  GLuint id;
};
} // jackal