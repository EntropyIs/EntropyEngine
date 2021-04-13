#include "ecpch.h"
#include "Application.h"

#include "Tools/Log.h"

#include "Events/Event.h"

#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

Entropy::Application::Application()
{
	window = std::unique_ptr<Entropy::Window>(Entropy::Window::Create());
	window->SetEventCallback(BIND_EVENT_FUNCTION(Application::OnEvent));
}

Entropy::Application::~Application()
{
}

void Entropy::Application::Init(bool _debug)
{
	Entropy::log::init(_debug);
	Entropy::log::header("Entropy Engine: Default Initalization.");

	running = true;
}

void Entropy::Application::Run()
{
	Entropy::log::header("Entropy Engine: Default Run.");

	while (running)
	{
		window->OnUpdate();
	}
}

void Entropy::Application::Shutdown()
{
	Entropy::log::header("Entropy Engine: Default Shutdown.");
	Entropy::log::shutdown();
}

void Entropy::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowClose));
}

bool Entropy::Application::OnWindowClose(Entropy::WindowCloseEvent& e)
{
	running = false;
	return true;
}
