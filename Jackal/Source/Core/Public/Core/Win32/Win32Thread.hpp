// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Win32/Win32Config.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Platform/JTypes.hpp"

namespace jkl {


// Win32 Thread handler object. This thread object is intended to 
// hold onto windows specific threads that are created by the game
// engine.
class Win32Thread {
public:

  // The current thread being executed in the application
  // context.
  class ThisThread {
  public:
    static DWORD GetId();

    // TODO(): Still needs work.
    static void SleepFor();

    // TODO(): Still needs work.
    static void SleepUntil();
  };

  Win32Thread() { }

  // Standard setting of this Thread.
  Win32Thread(LPSECURITY_ATTRIBUTES threadAttribs,
    SIZE_T stackSize, LPTHREAD_START_ROUTINE start,
    LPVOID lpParam, DWORD dwCreationFlags);

  Win32Thread(Win32Thread &thr);
  Win32Thread(Win32Thread &&thr);

  // Check if this thread is joinable to the current thread.
  bool8 IsJoinable();

  // Have the current thread wait for this thread to finish.
  void Join();

  // Detach this thread, allowing it to run as a daemon.
  void Detach();
  
  // Get the handle to this thread object.
  HANDLE GetHandle() const { return handle; }

  // Get the unique id of this thread, assigned by the operating system.
  DWORD GetUID() const { return uid; }

  // Retrieve the UID if none was already specified.
  void RetrieveUID();

  // Terminate this thread early.
  void EarlyTerminate(DWORD exitCode);
  
private:
  // Unique ID of this thread on the Operating System.
  DWORD                 uid;

  // The starting address, or the application defined function call, for which this
  // thread enters. This is where the thread function main begins.
  LPTHREAD_START_ROUTINE  startAddress;

  // Handle to the Win32 thread object.
  HANDLE handle;
};
} // jkl