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
		std::cout << console_color::forground_cyan << "Logfile Generated: " << datetime() << console_color::reset << std::endl;

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
			std::cout << console_color::forground_cyan << "Logfile Closed: " << datetime() << console_color::reset << std::endl;
	}
	return !initalized;
}

void log::header(const char* _prefix, const char* _msg)
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
			std::cout << console_color::forground_bold_green << datetime() << " " << _prefix << ": " << _msg << console_color::reset << std::endl;
	}
}

void log::message(const char* _prefix, const char* _msg)
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
			std::cout << console_color::forground_green << datetime() << " " << _prefix << ": " << console_color::reset << ": " << _msg << console_color::reset << std::endl;
	}
}

void Entropy::log::error(const char* _prefix, const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << datetime() << " " << _prefix << " Error: "<< _msg << std::endl;
		}
		logger.close();

		if (debug)
			std::cerr << console_color::forground_red << datetime() << _prefix << " Error: " << _msg << console_color::reset << std::endl;
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
			logger << datetime() << " " << _prefix << " Error: " << _code << ", " << _msg << std::endl;
		}
		logger.close();

		if (debug)
			std::cerr << console_color::forground_red << datetime() << _prefix << " Error: " << _code << ", " << _msg << console_color::reset << std::endl;
	}
}

void Entropy::log::trace(const char* _prefix, Entropy::Event& _event)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << datetime() << " " << _prefix << ": " << _event.getName() << std::endl;
		}
		logger.close();

		if (debug)
			std::cout << console_color::forground_white << datetime() << " " << _prefix << ": " << _event.getName() << console_color::reset << std::endl;
	}
}

std::string log::datetime()
{
	//Generate DateTime Stamp
	auto now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	std::tm *tm_local = localtime(&time);

	std::stringstream formatted;
	formatted << "[" << tm_local->tm_year + 1900 << "-" << tm_local->tm_mon + 1 << "-" << tm_local->tm_mday << " " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << "]";
	std::string output = formatted.str();

	return output;
}
