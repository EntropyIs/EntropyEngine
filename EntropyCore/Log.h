#pragma once
#include "API.h"

class ENTROPY_API Log
{
public:
	static void Error(const char* _msg);
	static void Message(const char* _msg);
};
