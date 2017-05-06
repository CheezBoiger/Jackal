//
// Copyright (c) Jackal Engine. MIT License.
//
#pragma once


#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"

#include <string>


#define VT100_CMD_CLR "\33[2K\r"


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



// TODO(): Remove strings from this message and replace with JString.
struct Message {
  LogType       logType;
  std::string   timeStamp;
  bool8         isWideString;
};


struct LogMessage : public Message {
  std::string   tag;
  std::string   msg;
};

struct LogMessageW : public Message {
  std::wstring wtag;
  std::wstring wmsg;
};
} // jkl