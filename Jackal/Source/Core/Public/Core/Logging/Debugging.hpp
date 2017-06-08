// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Assertions.hpp"


// Conditions may not be required for use when on release, so 
// in order to improve on speed, it should be "ok" to remove any
// debugging conditions that would most likely slow down performance.
// Be sure you are absolutely positive you need to remove a condition
// from source code when on release, otherwise do not use this at all!
#if JACKAL_DEBUG
 #include <stdio.h>

 #define JACKAL_REMOVE_ON_RELEASE(cond) cond 
 #define JASSERT(cond) JKL_ASSERT(cond)
 #define JACKAL_ASSERT(cond) JASSERT(cond)
 #define JDEBUG(p, ...) printf(p, ## __VA_ARGS__)
#else
 #define JACKAL_REMOVE_ON_RELEASE(cond)
 #define JASSERT(cond)
 #define JACKAL_ASSERT(cond)
 #define JDEBUG(p, ...)
#endif 