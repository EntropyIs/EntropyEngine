#pragma once
#include "Tools/API.h"

namespace Entropy
{
	class ENTROPY_CORE_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run() = 0;
	};

	// To Be Defined In CLIENT
	Application* CreateApplication();
}