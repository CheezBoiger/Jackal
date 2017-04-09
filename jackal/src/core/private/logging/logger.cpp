//
// Copyright (c) Jackal Engine. MIT License.
//
#include "logging/logger.hpp"
#include "log_data.hpp"
#include <iostream>
#include <iomanip>
#include <cstdio>


namespace jkl {


uint16 Log::suppressed = 0x8;

void Log::Messsage(LogType type, const char *msg, TargetModule loc, const char *nameTag)
{
  if ((suppressed & type) != type) {
    switch (type) {
      case LOG_WARNING: std::cout << "Warning: "; break;
      case LOG_ERROR: std::cout << "Error: "; break;
      case LOG_RUNTIME_DEBUG: std::cout << "Debug: "; break;
      case LOG_NOTIFY: std::cout << "Notice: "; break;
      case LOG_HIDDEN: std::cout << "Hidden: "; break;
      default: break;
    }
    std::cout << msg << "\n";
    if (nameTag) {
      std::cout << "From " << nameTag << "\n\n";
    }
  }
}


void Log::Suppress(LogType type)
{
  if ((suppressed & type) != type) {
    suppressed ^= type;
  } 
}


void Log::Unsuppress(LogType type) 
{
  if ((suppressed & type) == type) {
    suppressed ^= type;
  }
}


void Log::StoreMessage(LogType type, const char *msg,
  TargetModule loc, const char *tag)
{
  LogMessage logMsg;
  logMsg.logType = type;
  logMsg.moduleLocation = loc;
  logMsg.msg = msg;
  logMsg.tag = tag;
  MessageLogDatabase::StoreMessage(logMsg);
}
} // jkl