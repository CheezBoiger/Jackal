// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Win32/Win32Filesystem.hpp"

#include <fstream>
#include <sstream>
#include <string>


namespace jackal {


NativeString Win32Filesystem::CurrentDirectory()
{
  NativeString directoryPath;

  DWORD length = 0;
  length = GetCurrentDirectory(0, NULL) + 1;
  directoryPath.resize(length);

  GetCurrentDirectory(length, &directoryPath[0]);

  return directoryPath;
}


// We can use the standard library to read our files lulz.
NativeString Win32Filesystem::ReadFile(NativeString file)
{
  std::ifstream fil;
  fil.open(file);

  if (!fil.is_open()) {
    return "";
  }

  std::stringstream ss;
  ss << fil.rdbuf();
  std::string s = ss.str();
  return s;
}


NativeString Win32Filesystem::AsyncReadFile(NativeString file)
{
  // TODO():
  return "";
}
} // jackal