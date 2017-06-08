// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

namespace jkl {


enum Language {
  L_ENGLISH_EN,
  L_SPANISH,
  L_GERMAN,
  L_RUSSIAN,
  L_DUTCH,
  L_ENGLISH_US,
  L_FRENCH,
  L_CHINESE,
  L_KOREAN,
  L_JAPANESE,
  L_VIETNAMESE,
  L_ENGLISH_CAN,
  L_ARABIC,
};


enum Currency {
  C_D_US,
  C_D_CAN,
  C_D_DONG,
  C_D_YEN,
  C_D_YUAN,
  C_D_F_FRANC,
  c_D_EURO,
  C_D_RUBLE,
};


class Locale {
public:

  static void SetLanguage(Language code);
  static void SetCurrency(Currency code);

  static Language GetLanguage();
  static Currency GetCurrency();
};
} // jkl