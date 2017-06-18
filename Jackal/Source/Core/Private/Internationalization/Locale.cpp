// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Internationalization/Locale.hpp"

#include <locale.h>
#include <locale>
#include <iostream>
#include <unordered_map>
#include <codecvt>

// Unfinished.
#if JACKAL_PLATFORM == JACKAL_WINDOWS
 #define LOCALE_ENGLISH_EN      "en-US"
 #define LOCALE_ENGLISH_US      "en-EN"
 #define LOCALE_SPANISH         "es-ES"
 #define LOCALE_GERMAN          "de-DE"
 #define LOCALE_RUSSIAN         "Russian"
 #define LOCALE_DUTCH           ""
 #define LOCALE_FRENCH          "fr-FR"
 #define LOCALE_CHINESE         ""
 #define LOCALE_KOREAN          ""
 #define LOCALE_JAPANESE        "ja-JP"
 #define LOCALE_VIETNAMESE      ""
 #define LOCALE_ENGLISH_CAN     ""
 #define LOCALE_ARABIC          ""
#elif JACKAL_PLATFORM == JACKAL_LINUX
 #define LOCALE_ENGLISH_EN      "en.UTF-8"
 #define LOCALE_ENGLISH_US      "en_US.UTF-8"
 #define LOCALE_SPANISH         ""
 #define LOCALE_GERMAN          "de_DE.UTF-8"
 #define LOCALE_RUSSIAN         ""
 #define LOCALE_DUTCH           ""
 #define LOCALE_FRENCH          "fr_FR.UTF-8"
 #define LOCALE_CHINESE         ""
 #define LOCALE_KOREAN          ""
 #define LOCALE_JAPANESE        "ja_JP.UTF-8"
 #define LOCALE_VIETNAMESE      ""
 #define LOCALE_ENGLISH_CAN     ""
 #define LOCALE_ARABIC          ""
#else
 
#endif

#define L_PAIR(lang, loc) { lang, loc }
namespace jackal {


class LanguageHash {
public:
  std::size_t operator()(const Language &l) const {
    return std::hash<int32> { } ((int32 )l);
  }
};

// Add languages to the locale look up table. This will allow the changing
// Of this Program's code pages. 
std::unordered_map<Language, const char *, LanguageHash> languageLookUp = {
  L_PAIR(Language::L_ENGLISH_US,  LOCALE_ENGLISH_US),
  L_PAIR(Language::L_JAPANESE,    LOCALE_JAPANESE),
  L_PAIR(Language::L_CHINESE,     LOCALE_CHINESE),
  L_PAIR(Language::L_GERMAN,      LOCALE_GERMAN),
  L_PAIR(Language::L_FRENCH,      LOCALE_FRENCH)
};


void Locale::SetLanguage(Language code)
{
  setlocale(LC_ALL, languageLookUp[code]);
  std::locale::global(std::locale(languageLookUp[code]));
  std::wcout.imbue(std::locale(languageLookUp[code]));
}
} // jackal