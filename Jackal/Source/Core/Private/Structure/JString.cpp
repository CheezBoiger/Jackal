// Copyright (c) 2017 Jackal Engine, MIT License.
#include "Core/Structure/JString.hpp"


#if JACKAL_PLATFORM == JACKAL_WINDOWS
#include "Core/Win32/Win32Window.hpp"


namespace jackal {

void PrintToStdConsole(JString str)
{
  Win32Window::PrintToStdConsole(GetStdHandle(STD_OUTPUT_HANDLE), str);
}
} // jackal
#else

#include <iostream>


namespace jackal {

void PrintToStdConsole(JString str)
{
  std::cout << str;
}
} // jackal
#endif


