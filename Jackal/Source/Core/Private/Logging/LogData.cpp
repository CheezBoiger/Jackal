//
// Copyright (c) Jackal Engine. MIT License.
//
#include "LogData.hpp"
#include "Logging/Logger.hpp"

#include <vector>
#include <map>
#include <mutex>
#include <memory>


namespace jkl {

// Data base mutex used to handle multi threading for 
// this data base.
std::mutex databaseMutex;

// Map data structure.
// used as meant for temporary until JHTable and JVector 
// are finished.
std::map<LogType, std::vector<std::unique_ptr<Message> > > msgTable;


void MessageLogDatabase::StoreMessage(Message &mesg)
{
  auto iter = msgTable.find(mesg.logType);
  if (iter != msgTable.end()) {
    std::vector<std::unique_ptr<Message> > msgs;
    msgTable[mesg.logType] = std::move(msgs);
  }
  msgTable[mesg.logType].push_back(std::make_unique<Message>(mesg));
}


Message *MessageLogDatabase::GetMessage(LogType type, uint32 index)
{
  auto iter = msgTable.find(type);
  LogMessage *message = nullptr;

  if (iter != msgTable.end()) {
  } else {
    Log::MessageToConsole(LOG_NOTIFY, "Message was not found.",
      false, "Message Database");
  }

  return message;
}
} // jkl