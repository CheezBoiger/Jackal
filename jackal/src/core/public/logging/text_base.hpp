//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once


#include "platform/jtypes.hpp"
#include "platform/platform.hpp"

#include <string>


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


// Message log data.
// logType : type of message this is.
// timeStamp : the time stamp from when the message was created.
// tag : the name of the module, or the tag of this message.
// msg : the actual message.
struct LogMessage {
  LogType       logType;
  std::string   timeStamp;
  std::string   tag;
  std::string   msg;
};
} // jkl