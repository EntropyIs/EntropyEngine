#include "ecpch.h"
#include "Application.h"

#include "Tools/Log.h"

#include "Events/Event.h"

#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

Entropy::Application::Application()
{
	_window = std::unique_ptr<Entropy::Window>(Entropy::Window::Create());
	_window->SetEventCallback(BIND_EVENT_FUNCTION(Application::OnEvent));
}

Entropy::Application::~Application()
{
}

void Entropy::Application::Init(bool _debug)
{
	Entropy::log::init(_debug);
	Entropy::log::header("APP", "Entropy Engine: Default Initalization.");

	_running = true;
}

void Entropy::Application::Run()
{
	Entropy::log::header("APP", "Entropy Engine: Default Run.");

	while (_running)
	{
		for (Layer* layer : _layerStack)
			layer->OnUpdate();

		_window->OnUpdate();
	}
}

void Entropy::Application::Shutdown()
{
	Entropy::log::header("APP", "Entropy Engine: Default Shutdown.");
	Entropy::log::shutdown();
}

void Entropy::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowClose));

	Entropy::log::trace("APP", e);

	for (auto it = _layerStack.end(); it != _layerStack.begin(); )
	{
		(*--it)->OnEvent(e);
		if (e.isHandled())
			break;
	}
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
	_running = false;
	return true;
}
