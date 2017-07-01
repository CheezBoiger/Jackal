// Copyright (c) 2017 Jackal Engine. MIT License.


#include "OpenGLDevice/OpenGLShader.hpp"


namespace jackal {


const tchar *OpenGLShader::shaderLanguage = JTEXT("glsl");


bool8 OpenGLShader::Compile(const JString filepath,
  std::vector<JString> includes,
  std::vector<JString> defines)
{

  return false;
}
} // jackal