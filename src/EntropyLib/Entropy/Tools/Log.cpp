#include "ecpch.h"
#include "Log.h"

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
		std::cout << console_color::forground_cyan << "Logfile Generated" << console_color::reset << ": " << datetime() << std::endl;

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
			std::cout << console_color::forground_cyan << "Logfile Closed" << console_color::reset << ": " << datetime() << std::endl;;
	}
	return !initalized;
}

void log::header(const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << "#" << datetime() << ": " << _msg << "#" << std::endl;
		}
		logger.close();

		if (debug)
			std::cout << console_color::forground_bold_green << datetime() << console_color::reset << ": " << _msg << std::endl;
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
			std::cout << console_color::forground_green << datetime() << console_color::reset << ": " << _msg << std::endl;
	}
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
			std::cerr << console_color::forground_red << datetime() << " Error" << console_color::reset << ": " << _msg << std::endl;
	}
}

void Entropy::log::error(const char* _prefix, int _code, const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << datetime() << _prefix << " Error: " << _code << ", " << _msg << std::endl;
		}
		logger.close();

		if (debug)
			std::cerr << console_color::forground_red << datetime() << _prefix << " Error: " << _code << ", " << _msg << std::endl;
	}
}

void Entropy::log::trace(Entropy::Event& _event)
{
	message(_event.toString().c_str());
}

const char* log::datetime()
{
	//TODO Generate DateTime Stamp
	return "DATE_TIME";
}
