//
// Copyright (c) Jackal Engine. MIT License.
// 
#pragma once

#include "Platform/Api.hpp"
#include "Platform/JTypes.hpp"
#include "Platform/Platform.hpp"
#include "TextBase.hpp"

// For now.
#include <string>


namespace jkl {


// Static Logger class. Organizes, manages, and displays messages
// to the standard output for use in runtime debugging, and bookkeeping
// for use in the near future. Use this logger to deal with runtime bugs,
// as well as notifying the user of any issues going on with the engine, that
// must be noted to the user or programmer.
class Log {
public:

  // Suppresses a specific message type in the logger. This will prevent
  // the logger from displaying the message to the standard output. This can
  // be handle if the programmer, or user, does not wish to see a certain type
  // of message on the console or screen.
  static void Suppress(LogType type);

  // Unsuppress message types, so that they may be seen on the standard
  // ouput again. This can be handy if certain modules need to notify
  // the programmer or user of anything, while other modules may not need it.
  static void Unsuppress(LogType type);

  // Display a message immediately to the standard output console.
  // This won't save the message to the standard output unless specified
  // with the "store" parameter.
  static void MessageToConsole(LogType type, std::string msg, bool8 store = false,
    std::string tag = "");
  
  // Stores a message into the Logger database. This allows the 
  // user to keep track of any logs needed, if required to look back
  // at anything during the status of the engine.
  static void StoreMessage(LogType type, std::string msg, std::string nameTag = "");

  // Dumps all messages and flushes them to the standard output.
  // This will ensure that the user needs to look at the entire history
  // of the engine status in runtime.
  static void DumpMessages();

  // Clear all logs in the log history, which is dependent on the 
  // LogValue type. If a log type is specified, then the logger will
  // remove logs that are specific that that parameter, otherwise 
  // specific LOG_ALL to remove all log history messages.
  static void ClearHistory(LogType type);

  // Get a stored message in history at the specified index. Returns the message 
  // string at the specified index, otherwise NULL will be returned.
  static const char *GetStoredMessage(LogType type, uint32 index);

  // Removes a stored message from the logger history. Returns true (1) 
  // on success, otherwise false (0) if no message was found in that index.
  static bool8 RemoveStoredMessage(LogType type, uint32 index);

  // Retrieves the last stored message from history. Returns NULL if no
  // message was last stored.
  static const char *GetLastStoredMessage();

  // Get the array list of messages with log type specification.
  // returns array, along with length of the list.
  static Message *GetMessages(LogType type, uint32 &length);


private:
  // Suppressed values in the logger database.
  static uint16 suppressed;
};
} // jkl