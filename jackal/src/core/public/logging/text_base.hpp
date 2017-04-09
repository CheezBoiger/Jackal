//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once


#include "platform/jtypes.hpp"
#include "platform/platform.hpp"


namespace jkl {

// The Log type of the message to be worked with.
enum LogType {
  LOG_NORMAL = 0x1,
  LOG_WARNING = 0x2,
  LOG_ERROR = 0x4,
  LOG_RUNTIME_DEBUG = 0x8,
  LOG_NOTIFY = 0x10,
  LOG_HIDDEN = 0x20,
  LOG_ALL = 0xFFFF
};

// Specifies a certain module to which the message came from.
// Messages don't need to have a location, it only helps specify
// where any situations come from.
enum TargetModule {
  MODULE_NONE,
  MODULE_EXTERNAL,
  MODULE_ENGINE,
  MODULE_CORE,
  MODULE_CORE_MEMORY,
  MODULE_CORE_MATH,
  MODULE_CORE_PLATFORM,
  MODULE_AUDIO,
  MODULE_ANIMATION,
  MODULE_LOG,
  MODULE_UNKNOWN
};


// Message log data.
// moduleLocation : location module.
// logType : type of message this is.
// tag : the name of the module, or the tag of this message.
// msg : the actual message.
struct LogMessage {
  TargetModule  moduleLocation;
  LogType       logType;
  const char    *tag;
  const char    *msg;
};
} // jkl