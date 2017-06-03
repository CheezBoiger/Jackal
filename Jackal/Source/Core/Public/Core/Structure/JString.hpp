//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"


namespace jkl {

// JString is a useful alternative to std::string, since
// when working on applications on either linux or windows,
// we need to determine language encoding formats such as 
// UTF-8, UTF-16, UTF-32 and ASCI based binary formats. 
// Since wide strings and strings are separated from their 
// formats, it's best to stick to one robust format, which we
// go with UTF-8.
class JString {
  enum StrFormat { UTF8, UTF16 };
public:
   // Produces a garbage string.
  JString();

  // String define.
  JString(const char *src);
  JString(const JString &str);
  JString(JString &&str);

  ~JString();
  
  void operator=(const char *str);
  void operator=(const JString &str);
  void operator=(const JString &&str);

  void operator+=(const JString &other);

  bool8 operator!=(const JString &other);
  bool8 operator==(const JString &other);

  JString SubStr(uint32 first, uint32 last) const;
  JString Append(const JString &str) const;
  JString Append(const char *src) const;

  JString Remove(uint32 first, uint32 last) const;

  bool8 Equals(const JString &string) const;

  bool8 IsEmpty() const {
    return (size == 0);
  }

  uint32 Size() const { return size; }
  uint32 Length() const { return size; }

  bool8 ContainsSubStr(const char *substr) const;
  bool8 ContainsSubStr(const JString &str) const;
  bool8 ContainsChar(const char ch) const;

  char &At(const uint32 index);

  char &operator[](const uint32 index);

  char *CStr() { return str; }

protected:
  // Conversion of our string from UTF8 format to UTF16 on Windows based systems.
  void StringUTF8ToUTF16();

  void StringUTF16ToUTF8();
  
private:
  StrFormat format;
  uint32 size;
  char *str;
};


#if TARGET_PLATFORM == JACKAL_WINDOWS
 #define JSTRING(text) L##text
#else
 #define JSTRING(text) text
#endif
} // jkl