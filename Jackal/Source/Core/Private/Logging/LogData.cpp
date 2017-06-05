// Copyright (c) 2017 Jackal Engine, MIT License.
#include "LogData.hpp"
#include "Core/Logging/TextBase.hpp"
#include "Core/Logging/Logger.hpp"
#include "Core/Memory/MemoryPool.hpp"
#include "Core/Memory/StackAlloc.hpp"

#include <vector>
#include <unordered_map>
#include <mutex>
#include <memory>

namespace std {
}


namespace jkl {

// Data base mutex used to handle multi threading for 
// this data base.
std::mutex databaseMutex;


struct VerboseHash {
  std::size_t operator()(const LogVerbosity &v) const {
    return std::hash<int32>{} ((int32 )v);
  }
};

  
  
// Map data structure.
// used as meant for temporary until JHTable and JVector 
// are finished.
  std::unordered_map<LogVerbosity, std::vector<Message>, VerboseHash> msgTable;


void MessageLogDatabase::StoreMessage(Message &mesg)
{
  auto iter = msgTable.find(mesg.verbose);
  if (iter != msgTable.end()) {
    std::vector<Message> msgs;
    msgTable[mesg.verbose] = std::move(msgs);
  }
  msgTable[mesg.verbose].push_back(std::move(mesg));
}


Message *MessageLogDatabase::GetMessage(LogVerbosity type, uint32 index)
{
  auto iter = msgTable.find(type);
  Message *message = nullptr;

  if (iter != msgTable.end()) {
    auto &table = iter->second;
    if (index < table.size()) {
      message = &table[index];
    } else {
      Log::MessageToConsole(LOG_ERROR, "Attempting to access out of bounds of database "
        " storage.", false, "Message Database");
    }
  } else {
    Log::MessageToConsole(LOG_NOTIFY, "Message was not found.",
      false, "Message Database");
  }

  return message;
}
} // jkl
