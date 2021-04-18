#include "EPCH.h"
#include "Log.h"

using namespace Entropy;

bool LOG::initalized;
bool LOG::debug;
const char* LOG::file_path;

bool LOG::Init(const bool _debug)
{
	file_path = "logfile.log";
	initalized = false;
	std::ofstream logger;
	logger.open(file_path, std::ofstream::out);
	if (logger.is_open())
	{
		logger << "Logfile Generated: " << DateTime() << std::endl;
		initalized = true;
	}
	logger.close();

	debug = _debug;

	if (debug)
		std::cout << CONSOLE_COLOR::FORGROUND_CYAN << "Logfile Generated: " << DateTime() << CONSOLE_COLOR::RESET << std::endl;

	return initalized;
}

bool LOG::Shutdown()
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << "Logfile Closed: " << DateTime() << std::endl;
			initalized = false;
		}
		logger.close();

		if (debug)
			std::cout << CONSOLE_COLOR::FORGROUND_CYAN << "Logfile Closed: " << DateTime() << CONSOLE_COLOR::RESET << std::endl;
	}
	return !initalized;
}

void LOG::Header(const char* _prefix, const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << "#" << DateTime() << ": " << _msg << "#" << std::endl;
		}
		logger.close();

		if (debug)
			std::cout << CONSOLE_COLOR::FORGROUND_BOLD_GREEN << DateTime() << " " << _prefix << ": " << _msg << CONSOLE_COLOR::RESET << std::endl;
	}
}

void LOG::Message(const char* _prefix, const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << DateTime() << ": " << _msg << std::endl;
		}
		logger.close();

		if (debug)
			std::cout << CONSOLE_COLOR::FORGROUND_GREEN << DateTime() << " " << _prefix << ": " << CONSOLE_COLOR::RESET << ": " << _msg << CONSOLE_COLOR::RESET << std::endl;
	}
}

void Entropy::LOG::Error(const char* _prefix, const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << DateTime() << " " << _prefix << " Error: "<< _msg << std::endl;
		}
		logger.close();

		if (debug)
			std::cerr << CONSOLE_COLOR::FORGROUND_RED << DateTime() << _prefix << " Error: " << _msg << CONSOLE_COLOR::RESET << std::endl;
	}
}

void Entropy::LOG::Error(const char* _prefix, int _code, const char* _msg)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << DateTime() << " " << _prefix << " Error: " << _code << ", " << _msg << std::endl;
		}
		logger.close();

		if (debug)
			std::cerr << CONSOLE_COLOR::FORGROUND_RED << DateTime() << _prefix << " Error: " << _code << ", " << _msg << CONSOLE_COLOR::RESET << std::endl;
	}
}

void Entropy::LOG::Trace(const char* _prefix, Entropy::Event& _event)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << DateTime() << " " << _prefix << ": " << _event.toString() << std::endl;
		}
		logger.close();

		if (debug)
			std::cout << CONSOLE_COLOR::FORGROUND_WHITE << DateTime() << " " << _prefix << ": " << _event.toString() << CONSOLE_COLOR::RESET << std::endl;
	}
}

void Entropy::LOG::UnhandledTrace(const char* _prefix, Event& _event)
{
	if (initalized)
	{
		std::ofstream logger;
		logger.open(file_path, std::ofstream::app);
		if (logger.is_open())
		{
			logger << DateTime() << " " << _prefix << ": " << _event.toString() << std::endl;
		}
		logger.close();

		if (debug)
			std::cout << CONSOLE_COLOR::FORGROUND_CYAN << DateTime() << " " << _prefix << ": Unhandled Event - " << _event.toString() << CONSOLE_COLOR::RESET << std::endl;
	}
}

std::string LOG::DateTime()
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
