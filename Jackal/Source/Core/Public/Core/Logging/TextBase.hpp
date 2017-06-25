// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

#include <utility>


#define VT100_CMD_CLR "\33[2K\r"


namespace jackal {

// The Log type of the message to be worked with.
// Each message type verbose reserves one bit on a 
// 16 bit value.
enum LogVerbosity {
  LOG_NORMAL        = 0x1,
  LOG_WARNING       = 0x2,
  LOG_ERROR         = 0x4,
  LOG_RUNTIME_DEBUG = 0x8,
  LOG_NOTIFY        = 0x10,
  LOG_HIDDEN        = 0x20,
  LOG_ALL           = 0xFFFF
};


// Message log data.
// logType : type of message this is.
// timeStamp : the time stamp from when the message was created.
// tag : the name of the module, or the tag of this message.
// msg : the actual message.



// TODO(): Remove strings from this message and replace with JString.
struct Message {
  LogVerbosity  verbose;
  JString       timeStamp;
  JString       tag;
  JString       msg;

  Message(LogVerbosity verbosity = LogVerbosity::LOG_NORMAL,
    JString msg = JTEXT(""), JString tag = JTEXT(""), JString timestamp = JTEXT(""))
    : verbose(verbosity)
    , timeStamp(timestamp)
    , tag(tag)
    , msg(msg)
  {
  }

  Message(const Message &log)
    : tag(log.tag)
    , msg(log.msg)
    , verbose(log.verbose)
    , timeStamp(log.timeStamp)
  {
  }

  Message(Message &&log) {
    std::swap(tag, log.tag);
    std::swap(msg, log.msg);
    std::swap(verbose, log.verbose);
    std::swap(timeStamp, log.timeStamp);
  }

  Message &operator=(Message &&log) {
    std::swap(tag, log.tag);
    std::swap(msg, log.msg);
    std::swap(verbose, log.verbose);
    std::swap(timeStamp, log.timeStamp);
    return (*this);
  }

  Message &operator=(const Message &log) {
    tag = log.tag;
    msg = log.msg;
    verbose = log.verbose;
    timeStamp = log.timeStamp;
    return (*this);
  }
};
} // jackal