#pragma once
#include "Tools/API.h"
#include "Window.h"

#include "Events/ApplicationEvents.h"

namespace Entropy
{
	class ENTROPY_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Init(bool _debug = false);
		virtual void Run();
		virtual void Shutdown();

		virtual void OnEvent(Event& e);

		virtual bool OnWindowClose(WindowCloseEvent& e);

	protected:
		std::unique_ptr<Window> window;

		bool running;
	};

	// To Be Defined In CLIENT
	Application* CreateApplication();
}