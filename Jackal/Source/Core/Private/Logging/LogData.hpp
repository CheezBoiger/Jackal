// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Platform/JTypes.hpp"
#include "Logging/TextBase.hpp"
#include "Platform/Platform.hpp"
#include "Structure/JVector.hpp"


namespace jkl {


// Message log database used for storing messaging packets
// into a history database. Messages can be retrieved, stored,
// removed, queried, as well as cleared if need be. Messages are 
// stored in structs for use universally.
class MessageLogDatabase {
public:
  // Moves a message over to the Database. Database stores 
  // the message over for future querying, or for needing
  // to keep track of runtime logs.
  static void StoreMessage(Message &mesg);

  // Get a message packet that was stored inside this database.
  static Message *GetMessage(LogType type, uint32 index);

  // Get the size of the list for a particular log type.
  static uint32 LogListSize(LogType type);

  // Grab any messages from a particular log type. This 
  // will return an array of log messages for the type.
  // Will also return the total size of the array.
  static Message *GetMessage(LogType type, uint32 &size);

  static bool8 ListEmpty(LogType type);

  // Clear all messages from a particular 
  static bool8 ClearMessageList(LogType type);

  // Clear all messages from this database.
  static bool8 ClearAll();

  // Get the Overall size of this database (or, the number of 
  // messages total, in this database).
  static uint32 OverallSize();
};
} // jkl