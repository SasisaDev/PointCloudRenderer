#pragma once

#include <iostream>
#include <string>

#define LTEXT(text) std::string(text)

class Logger
{
public:

	static void Log(std::string string);
};