//
// Copyright (c) Jackal Engine. MIT License.
//
#include "Platform/Api.hpp"
#include "Assertions.hpp"


// Conditions may not be required for use when on release, so 
// in order to improve on speed, it should be "ok" to remove any
// debugging conditions that would most likely slow down performance.
// Be sure you are absolutely positive you need to remove a condition
// from source code when on release, otherwise do not use this at all!
#if JACKAL_DEBUG
 #define JACKAL_REMOVE_ON_RELEASE(cond) cond 
 #define JASSERT(cond) JKL_ASSERT(cond)
#else
 #define JACKAL_REMOVE_ON_RELEASE(cond)
#endif 