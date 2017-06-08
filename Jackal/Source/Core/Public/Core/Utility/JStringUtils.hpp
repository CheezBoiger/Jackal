// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

#include <string>
#include <type_traits>

namespace jkl {


class JStringUtils {
public:

  // TODO(): Remove heap allocation from these functions!
  static void UTF8To16(const uint8 *input, uint16 *output);
  static void UTF16To8(const uint16 *input, uint8 *output);
  static void UTF16To32(const uint16 *input, uint32 *output);
  static void UTF32To16(const uint32 *input, uint16 *output);

  // Get the string size of the tchar.
  static size_t GetStringSize(const tchar *src);
  static tchar *AllocateStringSize(size_t size);

  static void StringCopy(tchar *dest, const tchar *src);

  template<typename Type>
  static JString ToString(Type n) {
    //static_assert<std::is_same<decltype(Type), tchar>::value, "No need to convert tchar");
    JString str = TO_JSTRING(n);
    return str;
  }
};
} // jkl
