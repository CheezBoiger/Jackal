// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Platform/Network.hpp"

#define WIN32_NETWORKING
#include "Core/Win32/Win32Config.hpp"


namespace jackal {


// Win32 defined socket.
class Win32Socket {
public:

  bool Create(NetworkProtocol protocol);
  bool Connect(char* addr, uint32 milliseconds);
  bool ConnectAsync(char* addr, uint32 milliseconds);
  bool Listen(char* addr);

  bool Accept();
  bool AcceptAsync();

  bool Send(char* data, uint32 size);
  bool Recv(char* outputData, uint32* outputSize);

private:

  SOCKET mSocket;
};  
} // jackal