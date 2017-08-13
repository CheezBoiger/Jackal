// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Win32/Win32Time.hpp"

#include "Platform/Time.hpp"


namespace jackal {

real64 Time::deltaTime = 0.0;
real64 Time::scaleTime = 1.0;
real64 Time::oldTime = 0.0;
static real64 Frequency = 0.0;
static int64 CStart = 0;

void Time::UpdateDelta()
{
  real64 latestTime = Current();
  deltaTime = latestTime - oldTime;
  oldTime = latestTime;
}


real64 Time::Current()
{
  LARGE_INTEGER li;
  QueryPerformanceCounter(&li);
  return double(li.QuadPart - CStart) / Frequency;
}


void Time::StartTime()
{
  LARGE_INTEGER li;
  QueryPerformanceCounter(&li);
  Frequency = real64(li.QuadPart) / 1000.0;
  QueryPerformanceCounter(&li);
  CStart = li.QuadPart;
}
} // jackal