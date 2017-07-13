// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Win32/Win32Filesystem.hpp"

#include <fstream>
#include <sstream>
#include <string>


namespace jackal {


JString Win32Filesystem::CurrentDirectory()
{
  JString directoryPath;

  DWORD length = 0;
  length = GetCurrentDirectory(0, NULL) + 1;
  directoryPath.resize(length);

  GetCurrentDirectory(length, &directoryPath[0]);

  return directoryPath;
}


// We can use the standard library to read our files lulz.
JString Win32Filesystem::ReadFile(JString file)
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


JString Win32Filesystem::AsyncReadFile(JString file)
{
  // TODO():
  return "";
}
} // jackal