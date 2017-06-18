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
  jackal::Locale::SetLanguage(jackal::L_JAPANESE);
  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL, 
    JTEXT("If you can not see the below texts, change your terminal font!"), 
    false, JTEXT("String Testing"));

  jackal::JString str(JTEXT("The Quick Brown Fox jumps over a lazy dog."));
  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL, str, true, JTEXT("English"));

  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL, 
    JTEXT("クイックブラウンフォックスは、怠惰な犬の上を飛びます。"), 
    false, JTEXT("Japanese"));
  
  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL, 
    JTEXT("وسريعا، الثعلب البني يقفز أكثر من كلب كسول."), false, JTEXT("Arabic"));

  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL,
    JTEXT("快速布朗狐狸跳过一只懒惰的狗。"), false, JTEXT("Chinese Simplified"));

  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL,
    JTEXT("빠른 브라운 폭스는 게으른 개를 뛰어 넘습니다."), false, JTEXT("Korean"));

  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL,
    JTEXT("Быстрая коричневая лисица прыгает через ленивую собаку."), false, JTEXT("Russian"));

  jackal::Log::MessageToStdOutput(jackal::LOG_NORMAL,
    JTEXT("La rápida caja marrón salta sobre un perro perezoso."), false, JTEXT("Spanish"));
 
  jackal::Log::MessageToStdOutput(jackal::LogVerbosity::LOG_NORMAL, jackal::JStringUtils::ToString(str.empty())); 

  jackal::Message *message = jackal::Log::GetStoredMessage(jackal::LOG_NORMAL, 0);

  jackal::Log::MessageToStdOutput(message->verbose, message->msg, false, message->tag);
}


namespace coretest {


void JStringTesting()
{
  // do nothing.
}
} // jstringtest
