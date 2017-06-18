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


size_t JStringUtils::GetStringSize(const tchar *src)
{
#if defined(_WIN32)
  return wcslen(src);
#else
  return strlen(src);
#endif
}


tchar *JStringUtils::AllocateStringSize(size_t size)
{
  return new tchar[size];
}


void JStringUtils::StringCopy(tchar *dest, const tchar *src)
{
#if defined (_WIN32)
  wcscpy(dest, src);
#else
  strcpy(dest, src);
#endif
}



} // jackal