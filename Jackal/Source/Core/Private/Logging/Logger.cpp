// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Logging/Logger.hpp"
#include "LogData.hpp"
#include <iostream>
#include <iomanip>
#include <cstdio>

#define CASE_MODULE_PRINT(modEnum, str) \
  case modEnum: std::cout << "Module location: " << str << "\n"; break


namespace jkl {


uint16 Log::suppressed = 0x8;

void Log::MessageToStdOutput(LogVerbosity type, JString msg, bool8 store,
  JString nameTag)
{
  if (!(suppressed & type)) {
    switch (type) {
      case LOG_WARNING: PrintToStdConsole(JTEXT("Warning: ")); break;
      case LOG_ERROR: PrintToStdConsole(JTEXT("Error: ")); break;
      case LOG_RUNTIME_DEBUG: PrintToStdConsole(JTEXT("Debug: ")); break;
      case LOG_NOTIFY: PrintToStdConsole(JTEXT("Notice: ")); break;
      case LOG_HIDDEN: PrintToStdConsole(JTEXT("Hidden: ")); break;
      default: break;
    }
    PrintToStdConsole(msg + JTEXT("\n"));
    if (!nameTag.empty()) {
      PrintToStdConsole(JTEXT("Tag: ") + nameTag + JTEXT("\n\n"));
    }
  }
  if (store) {
    StoreMessage(type, msg, nameTag);
  }
}


void Log::Suppress(LogVerbosity type)
{
  if (type == LOG_ALL) {
    suppressed = LOG_ALL;
    return;
  }
  if (type & LOG_NORMAL) {
    if (!(suppressed & LOG_NORMAL)) {
      suppressed ^= LOG_NORMAL;
    }
  }
  if (type & LOG_WARNING) {
    if (!(suppressed & LOG_WARNING)) {
      suppressed ^= LOG_WARNING;   
    }   
  }
  if (type & LOG_ERROR) {
    if (!(suppressed & LOG_ERROR)) {
      suppressed ^= LOG_ERROR;  
    }
  }
  if (type & LOG_RUNTIME_DEBUG) {
    if (!(suppressed & LOG_RUNTIME_DEBUG)) {
      suppressed ^= LOG_RUNTIME_DEBUG;
    }
  }
  if (type & LOG_NOTIFY) {
    if (!(suppressed & LOG_NOTIFY)) {
      suppressed ^= LOG_NOTIFY;
    }
  }
  if (type & LOG_HIDDEN) {
    if (!(suppressed & LOG_HIDDEN)) {
      suppressed ^= LOG_HIDDEN;
    }
  }
}


void Log::Unsuppress(LogVerbosity type) 
{
  if (type == LOG_ALL) {
    suppressed = 0x0;
    return;
  }

  if (type & LOG_NORMAL) {
    if (suppressed & LOG_NORMAL) {
      suppressed ^= LOG_NORMAL;
    }
  }
  if (type & LOG_WARNING) {
    if (suppressed & LOG_WARNING) {
      suppressed ^= LOG_WARNING;
    }
  }
  if (type & LOG_ERROR) {
    if (suppressed & LOG_ERROR) {
      suppressed ^= LOG_ERROR;
    }
  }
  if (type & LOG_RUNTIME_DEBUG) {
    if (suppressed & LOG_RUNTIME_DEBUG) {
      suppressed ^= LOG_RUNTIME_DEBUG;
    }
  }
  if (type & LOG_NOTIFY) {  
    if (suppressed & LOG_NOTIFY) {
      suppressed ^= LOG_NOTIFY;
    }
  }
  if (type & LOG_HIDDEN) {
    if (suppressed & LOG_HIDDEN) {
      suppressed ^= LOG_HIDDEN;
    }
  }
}


void Log::StoreMessage(LogVerbosity type, JString msg, JString tag)
{
  Message logMsg;
  logMsg.timeStamp = JTEXT(""); // for now.
  logMsg.verbose = type;
  logMsg.msg = std::move(msg);
  logMsg.tag = std::move(tag);
  MessageLogDatabase::StoreMessage(logMsg);
}


Message *Log::GetStoredMessage(LogVerbosity verbose, uint32 index)
{
  return MessageLogDatabase::GetMessage(verbose, index);
}
} // jkl
