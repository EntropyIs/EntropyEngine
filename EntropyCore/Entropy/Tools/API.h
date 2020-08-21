#pragma once

#ifdef ENTROPY_PLATFORM_WINDOWS
	#ifdef ENTROPY_BUILD_DLL
		#define ENTROPY_CORE_API __declspec(dllexport)
	#else
		#define ENTROPY_CORE_API __declspec(dllimport)
	#endif // ENTROPY_BUILD_DLL
#else
	#error definition of platform required
#endif // ENTROPY_PLATFORM_WINDOWS