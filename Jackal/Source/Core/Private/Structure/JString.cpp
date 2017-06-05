// Copyright (c) 2017 Jackal Engine, MIT License.

#include "Core/Structure/JString.hpp"
#include "Core/Logging/Logger.hpp"

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
  std::wstring_convert<std::codecvt_utf8_utf16<int16>, int16> converter;
  auto p = reinterpret_cast<const int16 *>(utf16);
  ref = converter.to_bytes(p, p + std::char_traits<char16_t>::length(utf16));
}


void JString::StringUTF32ToUTF8(const char32_t *utf32)
{
  std::wstring_convert<std::codecvt_utf8<int32>, int32> converter;
  auto p = reinterpret_cast<const int32 *>(utf32);
  ref = converter.to_bytes(p, p + std::char_traits<char32_t>::length(utf32));
}


void JString::StringWideToUTF8(const wchar_t *wide)
{
  std::wstring temp(wide);
  ref = std::string(temp.begin(), temp.end());
}


std::wstring JString::WideCStr()
{
  size_t decodedSize = 1;
  switch (format) {
    case UTF8: decodedSize  = 1; break;
    case UTF16: decodedSize = 2; break;
    case UTF32: decodedSize = 4; break;
    default: decodedSize = 1; break;
  }
  std::wstring wstr;
  wstr.resize(ref.size() / decodedSize);
  mbstowcs(&wstr[0], ref.data(), ref.size() / decodedSize);
  return wstr;
}
} // jkl