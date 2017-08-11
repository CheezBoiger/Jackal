// Copyright (c) 2017 Jackal Engine, MIT License.
#include "RenderDevice/Shader.hpp"

#include <sstream>
#include <fstream>


namespace jackal {


NativeString Shader::ParseFile(NativeString filepath)
{
  std::ifstream fil;
  fil.open(filepath);

  if (!fil.is_open()) {
    return "";
  }

  std::stringstream ss;
  ss << fil.rdbuf();
  std::string s = ss.str();
  return s;
}
} // jackal