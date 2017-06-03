// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Thread.hpp"

namespace jkl {


void Win32Thread::ThisThread::SleepFor()
{
}


void Win32Thread::ThisThread::SleepUntil()
{
}



DWORD Win32Thread::ThisThread::GetId()
{
  return GetCurrentThreadId();
}



void Win32Thread::Join()
{
  if (!IsJoinable()) {
    return;
  }

  LPDWORD exitCode = nullptr;
  do {
    GetExitCodeThread(handle, exitCode);
  } while (*exitCode != STILL_ACTIVE);
}


bool8 Win32Thread::IsJoinable()
{
  return !(uid == 0);
}




} // jkl