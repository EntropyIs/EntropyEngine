#pragma once
#include "Tools/API.h"
#include "Window.h"

namespace Entropy
{
	class ENTROPY_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Init(bool _debug = false) = 0;
		virtual void Run() = 0;
		virtual void Shutdown() = 0;

	protected:
		std::unique_ptr<Window> window;

		bool running;
	};

	// To Be Defined In CLIENT
	Application* CreateApplication();
}