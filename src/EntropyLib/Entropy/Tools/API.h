#pragma once

#ifdef ENTROPY_PLATFORM_WINDOWS
	#ifdef ENTROPY_BUILD_DLL
		#define ENTROPY_API __declspec(dllexport)
	#else
		#define ENTROPY_API __declspec(dllimport)
	#endif // ENTROPY_BUILD_DLL
#else
	#error definition of platform required
#endif // ENTROPY_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)