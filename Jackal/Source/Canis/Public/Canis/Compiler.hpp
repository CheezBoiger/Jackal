// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Token.hpp"

namespace Canis {



// The compiler COM object. Must be instantiated and used to compile our
// homebrewed canis language into GLSL, HLSL, or Cg.
class Compiler {
public:
  Compiler();

  ~Compiler();

  void SetCompileTo(ShaderFileType type);

protected:
  ShaderFileType mCompileTo;
};
} // Canis