//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

#include <string>


namespace jkl {

// JString is a useful alternative to std::string, since
// when working on applications on either linux or windows,
// we need to determine language encoding formats such as 
// UTF-8, UTF-16, UTF-32 and ASCI based binary formats. 
// Since wide strings and strings are separated from their 
// formats, it's best to stick to one robust format, which we
// go with UTF-8.
class JString {
  enum StrFormat { UTF8, UTF16, UTF32 };
public:
   // Produces a garbage string.
  JString();

  // String define.
  JString(const char *src);
  JString(const JString &str);
  JString(const char16_t *src);
  JString(const char32_t *src);
  JString(const wchar_t *scr);
  JString(JString &&str);

  ~JString();
  
  JString &operator=(const char *str);
  JString &operator=(const char16_t *str);
  JString &operator=(const char32_t *str);
  JString &operator=(const wchar_t *str);
  JString &operator=(const JString &str);
  JString &operator=(JString &&str);

  void operator+=(const JString &other);

  bool8 operator!=(const JString &other);
  bool8 operator==(const JString &other);

  JString SubStr(uint32 first, uint32 last) const;
  JString Append(const JString &str) const;
  JString Append(const char *src) const;

  JString Remove(uint32 first, uint32 last) const;

  bool8 Equals(const JString &string) const;

  bool8 IsEmpty() const {
    return ref.empty();
  }

  size_t Size() const { return ref.size(); }
  size_t Length() const { return ref.length(); }

  bool8 ContainsSubStr(const char *substr) const;
  bool8 ContainsSubStr(const JString &str) const;
  bool8 ContainsChar(const char ch) const;

  char &At(const uint32 index) {
    return ref[index];
  }

  char &operator[](const uint32 index) {
    return ref[index];
  }

  const char *CStr() { return ref.c_str(); }

  std::wstring WideCStr();

  StrFormat GetFormat() const { return format; }
protected:

  void StringUTF16ToUTF8(const char16_t *utf16);
  void StringUTF32ToUTF8(const char32_t *utf32);
  void StringWideToUTF8(const wchar_t *wide);
  
private:
  StrFormat format;
  std::string ref;
};


#if TARGET_PLATFORM == JACKAL_WINDOWS
 #define JTEXT(text) L##text
#else
 #define JTEXT(text) text
#endif
} // jkl