// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Platform.hpp"
#include "Api.hpp"
#include "JTypes.hpp"


namespace jackal {


// Time class.
class Time {
public:

  // Get the Delta time in milliseconds.
  static real64 DeltaTime() { return deltaTime; }

  // Get the Scale time in milliseconds.
  static real64 ScaleTime() { return scaleTime; }

  // Set the scale time in milliseconds.
  static void SetScaleTime(real64 scale) { scaleTime = scale; }

  // Update the delta time by setting the latest time in milliseconds.
  // This will compute: 
  // delta = latestTime - oldtime;
  // oldTime = latestTime;
  static void UpdateDelta();

  // Get the current time.
  static real64 Current();

  static void StartTime();
private:
  static real64 oldTime;
  static real64 deltaTime;
  static real64 scaleTime;
};
} // jackal