// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once

#include "Core/Platform/JTypes.hpp"
#include "Core/Platform/Platform.hpp"
#include "Core/Structure/JString.hpp"

#include "Win32Config.hpp"

#include <vector>


namespace jackal {


// Windows filesystem API handler. Used for handling win32 
// files and directories. We can set our current directory path,
// and search path, with this singleton class, in order to provide 
// proper asset loading, file reading and opening.
class Win32Filesystem {
public:

  static NativeString CurrentDirectory();

  static NativeString SetNewCurrentDirectory(NativeString path);

  static NativeString CreateADirectory(NativeString name);

  static NativeString CreateAFile(NativeString name);

  static bool8 DirectoryExists(NativeString path);

  static bool8 FileExists(NativeString file);

  static bool8 RemoveADirectory(NativeString path);

  static bool8 AddSearchPath(NativeString path);

  static std::vector<NativeString> GetSearchPaths() { return mSearchPath; }

  static bool8 RemoveSearchPath(NativeString path);

  static NativeString SetAbsolutePath(NativeString relative);

  static NativeString GetAbsolutePath(NativeString file);

  static NativeString ReadFile(NativeString file);

  static NativeString AsyncReadFile(NativeString file);

private:

  // Search path for this filesystem.
  static std::vector<NativeString>      mSearchPath;
};
} // jackal 