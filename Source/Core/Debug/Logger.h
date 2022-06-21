#pragma once

#include <string>
#include <iostream>
#include <stdarg.h>

#define STEXT(var) std::string(var)

class Logger
{
public:

	static void Log(std::string str);
};