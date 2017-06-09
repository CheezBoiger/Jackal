// Copyright (c) 2017 Jackal Engine, MIT License.
#include "JStringTest.hpp"
#include "Core/Internationalization/Locale.hpp"
#include "Core/Structure/JString.hpp"
#include "Core/Utility/JStringUtils.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Logging/TextBase.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(StructureTests, JStringTesting)
{
  jkl::Locale::SetLanguage(jkl::L_JAPANESE);
  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL, 
    JTEXT("If you can not see the below texts, change your terminal font!"), 
    false, JTEXT("String Testing"));

  jkl::JString str(JTEXT("The Quick Brown Fox jumps over a lazy dog."));
  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL, str, true, JTEXT("English"));

  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL, 
    JTEXT("クイックブラウンフォックスは、怠惰な犬の上を飛びます。"), 
    false, JTEXT("Japanese"));
  
  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL, 
    JTEXT("وسريعا، الثعلب البني يقفز أكثر من كلب كسول."), false, JTEXT("Arabic"));

  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL,
    JTEXT("快速布朗狐狸跳过一只懒惰的狗。"), false, JTEXT("Chinese Simplified"));

  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL,
    JTEXT("빠른 브라운 폭스는 게으른 개를 뛰어 넘습니다."), false, JTEXT("Korean"));

  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL,
    JTEXT("Быстрая коричневая лисица прыгает через ленивую собаку."), false, JTEXT("Russian"));

  jkl::Log::MessageToStdOutput(jkl::LOG_NORMAL,
    JTEXT("La rápida caja marrón salta sobre un perro perezoso."), false, JTEXT("Spanish"));
 
  jkl::Log::MessageToStdOutput(jkl::LogVerbosity::LOG_NORMAL, jkl::JStringUtils::ToString(str.empty())); 

  jkl::Message *message = jkl::Log::GetStoredMessage(jkl::LOG_NORMAL, 0);

  jkl::Log::MessageToStdOutput(message->verbose, message->msg, false, message->tag);
}


namespace coretest {


void JStringTesting()
{
  // do nothing.
}
} // jstringtest
