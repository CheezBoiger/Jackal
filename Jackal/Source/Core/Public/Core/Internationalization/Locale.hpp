// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"

namespace jkl {


enum Language {
  J_ENGLISH_EN,
  J_SPANISH,
  J_GERMAN,
  J_RUSSIAN,
  J_DUTCH,
  J_ENGLISH_US,
  J_FRENCH,
  J_CHINESE,
  J_KOREAN,
  J_JAPANESE,
  J_VIETNAMESE,
  J_ENGLISH_CAN,
  J_ARABIC,
};


enum Currency {
  J_D_US,
  J_D_CAN,
  J_D_DONG,
  J_D_YEN,
  J_D_YUAN,
  J_D_F_FRANC,
  J_D_EURO,
  J_D_RUBLE,
};


class Locale {
public:

  static void SetLanguage(Language code);
  static void SetCurrency(Currency code);

  static Language GetLanguage();
  static Currency GetCurrency();
};
} // jkl