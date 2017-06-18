// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Logging/TextBase.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JVector.hpp"


#include <vector>


namespace jackal {


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
  static Message *GetMessage(LogVerbosity type, uint32 index);

  // Get the size of the list for a particular log type.
  static uint32 LogListSize(LogVerbosity type);

  // Grab any messages from a particular log type. This 
  // will return an array of log messages for the type.
  // Will also return the total size of the array.
  static std::vector<Message> &GetMessages(LogVerbosity type);

  static bool8 ListEmpty(LogVerbosity type);

  // Clear all messages from a particular 
  static bool8 ClearMessageList(LogVerbosity type);

  // Clear all messages from this database.
  static bool8 ClearAll();

  // Get the Overall size of this database (or, the number of 
  // messages total, in this database).
  static uint32 OverallSize();
};
} // jackal
