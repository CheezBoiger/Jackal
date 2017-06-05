// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/Api.hpp"
#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"
#include "TextBase.hpp"


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
  static void Suppress(LogVerbosity type);

  // Unsuppress message types, so that they may be seen on the standard
  // ouput again. This can be handy if certain modules need to notify
  // the programmer or user of anything, while other modules may not need it.
  static void Unsuppress(LogVerbosity type);

  // Display a message immediately to the standard output console.
  // This won't save the message to the standard output unless specified
  // with the "store" parameter.
  static void MessageToConsole(LogVerbosity type, JString msg, bool8 store = false,
    JString tag = JTEXT(""));
  
  // Stores a message into the Logger database. This allows the 
  // user to keep track of any logs needed, if required to look back
  // at anything during the status of the engine.
  static void StoreMessage(LogVerbosity type, JString msg, 
    JString nameTag = JTEXT(""));

  // Dumps all messages and flushes them to the standard output.
  // This will ensure that the user needs to look at the entire history
  // of the engine status in runtime.
  static void DumpMessages();

  // Clear all logs in the log history, which is dependent on the 
  // LogValue type. If a log type is specified, then the logger will
  // remove logs that are specific that that parameter, otherwise 
  // specific LOG_ALL to remove all log history messages.
  static void ClearHistory(LogVerbosity type);

  // Get a stored message in history at the specified index. Returns the message 
  // string at the specified index, otherwise NULL will be returned.
  static Message *GetStoredMessage(LogVerbosity type, uint32 index);

  // Removes a stored message from the logger history. Returns true (1) 
  // on success, otherwise false (0) if no message was found in that index.
  static bool8 RemoveStoredMessage(LogVerbosity type, uint32 index);

  // Retrieves the last stored message from history. Returns NULL if no
  // message was last stored.
  static Message *GetLastStoredMessage();

  // Get the array list of messages with log type specification.
  // returns array, along with length of the list.
  static Message *GetMessages(LogVerbosity type, uint32 &length);


private:
  // Suppressed values in the logger database.
  static uint16 suppressed;
};
} // jkl