// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Structure/JString.hpp"
#include "Core/Logging/Logger.hpp"

#if JACKAL_PLATFORM == JACKAL_WINDOWS
 #include "Core/Win32/Win32Config.hpp"
#endif 

#include <codecvt>
#include <locale>
#include <string>
#include <utility>

namespace jkl {


constexpr void SetLocale()
{
}



JString::JString()
{
  
}


JString::JString(const char *src)
  : ref(src)
  , format(StrFormat::UTF8)
{
}


JString::JString(const char16_t *src)
  : format(StrFormat::UTF16)
{
  StringUTF16ToUTF8(src);
}

JString::JString(const wchar_t *src)
  : format(StrFormat::UTF16)
{
  StringWideToUTF8(src);
}


JString::JString(const char32_t *src)
  : format(StrFormat::UTF32)
{
  StringUTF32ToUTF8(src);
}


JString::~JString()
{
}


JString &JString::operator=(const char *cstr)
{
  ref = std::string(cstr);
  return (*this);
}


JString &JString::operator=(const JString &str)
{
  ref = str.ref;
  format = str.format;
  return (*this);
}


JString &JString::operator=(JString &&str)
{
  std::swap(ref, str.ref);
  format = str.format;
  return (*this);
}


void JString::StringUTF16ToUTF8(const char16_t *utf16)
{
#if defined(_WIN32)
  std::wstring_convert<std::codecvt_utf8_utf16<int16>, int16> converter;
  auto p = reinterpret_cast<const int16 *>(utf16);
  ref = converter.to_bytes(p, p + std::char_traits<char16_t>::length(utf16));
#else
  std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
  auto p = reinterpret_cast<const int16 *>(utf16);
  ref = converter.to_bytes(utf16);
#endif
}


void JString::StringUTF32ToUTF8(const char32_t *utf32)
{
#if defined(_WIN32)
  std::wstring_convert<std::codecvt_utf8<int32>, int32> converter;
  auto p = reinterpret_cast<const int32 *>(utf32);
  ref = converter.to_bytes(p , p + std::char_traits<char32_t>::length(utf32));
#else
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
  auto p = reinterpret_cast<const int32 *>(utf32);
  ref = converter.to_bytes(utf32);
#endif
}


void JString::StringWideToUTF8(const wchar_t *wide)
{
#if defined(_WIN32)
  size_t wideSize = wcslen(wide);
  int overallSize = WideCharToMultiByte(CP_UTF8, 0, &wide[0], (int32 )wideSize,
    NULL, 0, NULL, NULL);
  
  ref = std::string(overallSize, 0);
  WideCharToMultiByte(CP_UTF8, 0, &wide[0], (int32 )wideSize, 
    &ref[0], overallSize, NULL, NULL);
#else
  
#endif
}


std::wstring JString::WideCStr()
{
#if defined(_WIN32)
  int overallSize = MultiByteToWideChar(CP_UTF8, 0, &ref[0], (int32 )ref.size(), NULL, 0);
  std::wstring wstr(overallSize, 0);
  MultiByteToWideChar(CP_UTF8, 0, &ref[0], (int32 )ref.size(), &wstr[0], overallSize);
  return wstr;
#else
#endif
}
} // jkl
