#pragma once
#include "Tools/API.h"
#include "Window.h"
#include "Layers/LayerStack.h"
#include "Events/ApplicationEvents.h"

namespace Entropy
{
	class ENTROPY_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Init(bool debug = false);
		virtual void Run();
		virtual void Shutdown();

		virtual void OnEvent(Event& e);

		virtual void PushLayer(Layer* layer);
		virtual void PushOverlay(Layer* overlay);

		virtual bool OnWindowClose(WindowCloseEvent& e);

	protected:
		std::unique_ptr<Window> _window;

		LayerStack _layerStack;

		bool _running;
	};

	// To Be Defined In CLIENT
	Application* CreateApplication();
}