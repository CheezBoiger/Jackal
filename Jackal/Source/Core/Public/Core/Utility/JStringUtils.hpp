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
  static void WideToUTF8(const wchar_t *input, char *output);

  static void UTF8ToWide(const char *input, wchar_t *output);


  static size_t GetStringSize(const tchar *src);
  static tchar *AllocateStringSize(size_t size);

  static void StringCopy(tchar *dest, const tchar *src);

  template<typename Type>
  static JString ToString(Type n) {
    //static_assert<std::is_same<decltype(Type), tchar>::value, "No need to convert tchar");
#if defined(_WIN32)
    JString str = std::to_wstring(n);
#else
    JSTring str = std::to_string(n);
#endif
    return str;
  }
};
} // jkl