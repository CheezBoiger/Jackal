// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Structure/JString.hpp"
#include "Core/Logging/Logger.hpp"

#include <string.h>

namespace jkl {



JString::JString()
{
  
}


JString::JString(const char *src)
  : str(nullptr)
  , size(0)
  , format(StrFormat::UTF8)
{
  if (src) {
    size = strlen(src);
    Log::MessageToConsole(LogType::LOG_NORMAL, std::to_string(size));
    // For null terminated string.
    str = new char[size + 1];
    strcpy(str, src);
  }
}


JString::~JString()
{
  if (str) {
    delete[] str;
  }
}


void JString::operator=(const char *cstr)
{
  if (str) {
    delete[] str;
    size = 0;
  }

  if (cstr) {
    size = strlen(cstr);
    str = new char[size + 1];
    strcpy(str, cstr);
  } else {
    str = nullptr;
    size = 0;
  }
}
} // jkl