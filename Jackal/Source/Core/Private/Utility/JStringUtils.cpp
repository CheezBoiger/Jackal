// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Utility/JStringUtils.hpp"
#include <string.h>
#include <string>

#if defined(_WIN32)
 #include "Core/Win32/Win32Config.hpp"
#endif

namespace jackal {

void JStringUtils::UTF8To16(const uint8 *input, uint16 *output)
{
}


void JStringUtils::UTF16To8(const uint16 *input, uint8 *output)
{
}


tchar *JStringUtils::AllocateStringSize(size_t size)
{
  return new tchar[size];
}


#if JACKAL_PLATFORM == JACKAL_WINDOWS
JString ToString(char *n) {
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  std::wstring wide = converter.from_bytes(n);
  return wide;
}
#else
JString ToString(char* n) {
  return std::string(n);
}
#endif
} // jackal
