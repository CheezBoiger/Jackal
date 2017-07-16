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

  static JString CurrentDirectory();

  static JString SetNewCurrentDirectory(JString path);

  static JString CreateADirectory(JString name);

  static JString CreateAFile(JString name);

  static bool8 DirectoryExists(JString path);

  static bool8 FileExists(JString file);

  static bool8 RemoveADirectory(JString path);

  static bool8 AddSearchPath(JString path);

  static std::vector<JString> GetSearchPaths() { return mSearchPath; }

  static bool8 RemoveSearchPath(JString path);

  static JString SetAbsolutePath(JString relative);

  static JString GetAbsolutePath(JString file);

  static JString ReadFile(JString file);

  static JString AsyncReadFile(JString file);

private:

  // Search path for this filesystem.
  static std::vector<JString>      mSearchPath;
};
} // jackal 