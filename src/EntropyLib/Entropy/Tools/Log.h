#pragma once
#include "API.h"
#include "Entropy/Events/Event.h"

#include <string>

namespace Entropy {
	class ENTROPY_API LOG
	{
	public:
		static bool Init(const bool debug = false);
		static bool Shutdown();

		static void Header(const char* prefix, const char* msg);
		static void Message(const char* prefix, const char* msg);
		static void Error(const char* prefix, const char* msg);
		static void Error(const char* prefix, int code, const char* msg);
		static void Trace(const char* prefix, Event& event);
		static void UnhandledTrace(const char* prefix, Event& event);

	private:
		static std::string DateTime();

		static bool initalized;
		static bool debug;
		static const char* file_path;
	};

	namespace CONSOLE_COLOR {
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& RESET(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[0m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BLACK(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[30m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_RED(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[31m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_GREEN(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[32m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_YELLOW(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[33m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BLUE(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[34m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_MAGENTA(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[35m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_CYAN(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[36m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_WHITE(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[37m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_BLACK(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[30m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_RED(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[31m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_GREEN(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[32m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_YELLOW(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[33m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_BLUE(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[34m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_MAGENTA(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[35m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_CYAN(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[36m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& FORGROUND_BOLD_WHITE(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[37m";
		};
	}
}