//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "platform/jtypes.hpp"
#include "platform/platform.hpp"

#include <string>
#include <fstream>
#include <ostream>


namespace jkl {
class JString {
public:

  JString(const char *src);
  JString(const JString &str);
  
  void operator=(const JString &str);
  void operator=(const JString &&str);

  void operator +=(const JString &other);

  bool8 operator!=(const JString &other);
  bool8 operator==(const JString &other);
private:
  uint32 size;
  const uint8 *str;
};


typedef std::fstream JFStream;
} // jkl