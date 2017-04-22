//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"

#include <string>
#include <fstream>
#include <ostream>


namespace jkl {



#if TARGET_PLATFORM == JACKAL_WINDOWS
typedef wchar_t jchar;
#else
typedef char jchar;
#endif

// JString is a useful alternative to std::string, since
// when working on applications on either linux or windows,
// we need to determine language encoding formats such as 
// UTF-8, UTF-16, UTF-32 and ASCI based binary formats. 
// Since wide strings and strings are separated from their 
// formats
class JString {
  static bool8 WideString;
public:

  JString(const char *src);
  JString(const wchar_t *src);
  JString(const JString &str);
  
  void operator=(const JString &str);
  void operator=(const JString &&str);

  void operator +=(const JString &other);

  bool8 operator!=(const JString &other);
  bool8 operator==(const JString &other);

  JString Substr(uint32 first, uint32 last) const;
  JString Append(const JString &str) const;
  JString Append(const char *src) const;
  JString Append(const wchar_t *src) const;

  JString Remove(uint32 first, uint32 last) const;

  static bool8 IsWideStringFormat() { return WideString; }
  
private:
  uint32 size;
  jchar *str;
};


#if TARGET_PLATFORM == JACKAL_WINDOWS
 #define JSTRING(text) L##text
#else
 #define JSTRING(text) text
#endif
} // jkl