// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Utility/JStringUtils.hpp"
#include <string.h>
#include <string>

#if defined(_WIN32)
 #include "Core/Win32/Win32Config.hpp"
#endif

namespace jkl {

void JStringUtils::WideToUTF8(const wchar_t *input, char *output)
{
#if JACKAL_PLATFORM == JACKAL_WINDOWS
  size_t wideSize = wcslen(input);
  int overallSize = WideCharToMultiByte(CP_UTF8, 0, &input[0], (int32)wideSize,
    NULL, 0, NULL, NULL);

  if (output) {
    delete[] output;
  }
  output = new char[overallSize];

  WideCharToMultiByte(CP_UTF8, 0, &input[0], (int32)wideSize,
   output, overallSize, NULL, NULL);
#endif
}


void JStringUtils::UTF8ToWide(const char *input, wchar_t *output)
{
#if defined(_WIN32)
  size_t siz = strlen(input);
  int overallSize = MultiByteToWideChar(CP_UTF8, 0, input, siz, NULL, 0);
  if (output) {
    delete[] output;
  }
  output = new wchar_t[overallSize];
  MultiByteToWideChar(CP_UTF8, 0, input, siz, output, overallSize);
#else
#endif
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



} // jkl