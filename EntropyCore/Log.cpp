#include "Log.h"

#include <iostream>

void Log::Error(const char* _msg)
{
	std::cerr << _msg << std::endl;
}

void Log::Message(const char* _msg)
{
	std::cout << _msg << std::endl;
}
