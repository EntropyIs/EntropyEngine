#pragma once
#include "API.h"
#include "Entropy/Events/Event.h"

#include <string>

namespace Entropy {
	class ENTROPY_API log
	{
	public:
		static bool init(const bool debug = false);
		static bool shutdown();

		static void header(const char* _prefix, const char* _msg);
		static void message(const char* _prefix, const char* _msg);
		static void error(const char* _prefix, const char* _msg);
		static void error(const char* _prefix, int _code, const char* _msg);
		static void trace(const char* _prefix, Event& _event);

	private:
		static std::string datetime();

		static bool initalized;
		static bool debug;
		static const char* file_path;
	};

	namespace console_color {
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& reset(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[0m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_black(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[30m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_red(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[31m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_green(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[32m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_yellow(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[33m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_blue(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[34m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_magenta(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[35m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_cyan(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[36m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_white(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[37m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_black(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[30m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_red(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[31m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_green(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[32m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_yellow(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[33m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_blue(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[34m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_magenta(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[35m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_cyan(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[36m";
		};
		template<class CharT, class Traits> constexpr std::basic_ostream<CharT, Traits>& forground_bold_white(std::basic_ostream<CharT, Traits>& os) {
			return os << "\033[1m\033[37m";
		};
	}
}