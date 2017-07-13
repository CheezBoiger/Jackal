// Copyright (c) 2017 Jackal Engine. MIT License.


#include "OpenGLDevice/OpenGLShader.hpp"
#include "Core/Logging/Logger.hpp"

#include <array>

namespace jackal {


const tchar *OpenGLShader::shaderLanguage = JTEXT("glsl");


GLenum OpenGLShader::GetNativeShaderType(ShaderType type)
{
  switch (type) {
    case Vertex: return GL_VERTEX_SHADER;
    case Fragment: return GL_FRAGMENT_SHADER;
    case TessControl: return GL_TESS_CONTROL_SHADER;
    case TessEvaluation: return GL_TESS_EVALUATION_SHADER;
    case Geometry: return GL_GEOMETRY_SHADER;
    case Compute: return GL_COMPUTE_SHADER;
    default: return GL_VERTEX_SHADER;
  };
}


bool8 OpenGLShader::Compile(ShaderType type, 
  const JString sourceCode,
  std::vector<JString> includes,
  std::vector<JString> defines)
{
  mShaderType = type;
  mNativeShaderType = GetNativeShaderType(type);

  // Clean up the shader if is already compiled.
  CleanUp();

  handle = glCreateShader(mNativeShaderType);
  
  GLint length = 0;
  JString Source = ParseSource(sourceCode, includes, defines);

  // Document this error, empty source code.
  if (Source.empty()) {
    CleanUp();
    return false;
  }

  const GLchar *src = Source.c_str();
  glShaderSource(handle, 1, &src, NULL);
  glCompileShader(handle);
  
  
  std::array<GLchar, 1024> log;
  GLint success = false;
  glGetShaderiv(handle, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(handle, (GLsizei )log.size(), nullptr, log.data());
    Log::MessageToStdOutput(LOG_ERROR, JString(log.data()));
    CleanUp();
    compiled = false;
    return false;
  }

  compiled = true;
  return true;
}


void OpenGLShader::CleanUp()
{
  if (handle) {
    glDeleteShader(handle);
    handle = 0;
  }
}


JString OpenGLShader::ParseSource(JString source, std::vector<JString> includes,
  std::vector<JString> defines)
{
  // TODO(): Add preprocessor into here, to parse include files, and 
  // defines.
  return source;
}
} // jackal