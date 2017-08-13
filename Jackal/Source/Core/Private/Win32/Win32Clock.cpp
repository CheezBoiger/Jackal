// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Win32/Win32Clock.hpp"

#include "Platform/Time.hpp"


namespace jackal {


void Time::UpdateDelta()
{
  real64 latestTime = Current();
  deltaTime = latestTime - oldTime;
  oldTime = latestTime;
}


real64 Time::Current()
{
  LARGE_INTEGER num;
  QueryPerformanceCounter(&num);
  
  return 0.0;
}
} // jackal