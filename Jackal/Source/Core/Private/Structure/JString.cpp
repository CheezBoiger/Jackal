// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Structure/JString.hpp"


#if JACKAL_PLATFORM == JACKAL_WINDOWS
#include "Core/Win32/Win32Window.hpp"


namespace jkl {

void PrintToStdConsole(JString str)
{
  PrintToWin32Console(GetStdHandle(STD_OUTPUT_HANDLE), str);
}
} // jkl
#else

#include <iostream>


namespace jkl {

void PrintToStdConsole(JString str)
{
  std::cout << str;
}
} // jkl
#endif


