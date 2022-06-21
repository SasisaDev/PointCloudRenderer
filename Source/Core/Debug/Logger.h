#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stdarg.h>

#define STEXT(x) ( std::stringstream() << std::dec << x ) ).str().c_str()

class Logger
{
public:

	static void Log(std::string str);
};