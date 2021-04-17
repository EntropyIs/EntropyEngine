#include "ecpch.h"
#include "Application.h"

#include "Tools/Log.h"

#include "Events/Event.h"

#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

Entropy::Application::Application() : _running(false) {}

Entropy::Application::~Application() {}

void Entropy::Application::Init(bool _debug)
{
	Entropy::LOG::Init(_debug);
	Entropy::LOG::Header("APP", "Entropy Engine: Default Initalization.");

	_window = std::unique_ptr<Entropy::Window>(Entropy::Window::Create());
	_window->SetEventCallback(BIND_EVENT_FUNCTION(Application::OnEvent));

	_running = true;
}

void Entropy::Application::Run()
{
	Entropy::LOG::Header("APP", "Entropy Engine: Default Run.");

	while (_running)
	{
		for (Layer* layer : _layerStack)
			layer->OnUpdate();

		_window->OnUpdate();
	}
}

void Entropy::Application::Shutdown()
{
	Entropy::LOG::Header("APP", "Entropy Engine: Default Shutdown.");
	Entropy::LOG::Shutdown();
}

void Entropy::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowClose));

	for (auto it = _layerStack.end(); it != _layerStack.begin(); )
	{
		(*--it)->OnEvent(e);
		if (e.isHandled())
			break;
	}

	if(!e.isHandled())
		Entropy::LOG::UnhandledTrace("APP", e);
}

void Entropy::Application::PushLayer(Layer* layer)
{
	_layerStack.PushLayer(layer);
}

void Entropy::Application::PushOverlay(Layer* overlay)
{
	_layerStack.PushOverlay(overlay);
}

bool Entropy::Application::OnWindowClose(Entropy::WindowCloseEvent& e)
{
	Entropy::LOG::Trace("APP", e);
	_running = false;
	return true;
}
