#include "Log.h"

#include <iostream>
#include <fstream>

using namespace Entropy;

bool log::initalized;
bool log::debug;
const char* log::file_path;

bool log::init(const bool _debug)
{
	file_path = "logfile.log";
	initalized = false;
	std::ofstream logger;
	logger.open(file_path, std::ofstream::out);
	if (logger.is_open())
	{
		logger << "Logfile Generated: " << datetime() << std::endl;
		initalized = true;
	}
	logger.close();

	debug = _debug;

	if (debug)
		std::cout << "Logfile Generated: " << datetime() << std::endl;

	return initalized;
}

bool log::shutdown()
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << "Logfile Closed: " << datetime() << std::endl;
			initalized = false;
		}
		logger.close();

		if (debug)
			std::cout << "Logfile Closed: " << datetime() << std::endl;;
	}
	return !initalized;
}

void log::error(const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << datetime() << " Error: " << _msg << std::endl;
		}
		logger.close();
		
		if (debug)
			std::cerr << datetime() << " Error: " << _msg << std::endl;
	}
}

void log::message(const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << datetime() << ": " << _msg << std::endl;
		}
		logger.close();

		if (debug)
			std::cout << datetime() << ": " << _msg << std::endl;
	}
}

const char* log::datetime()
{
	//TODO Generate DateTime Stamp
	return "DATE_TIME";
}
