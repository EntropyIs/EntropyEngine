#include "ecpch.h"
#include "Application.h"

#include "Entropy/Tools/Log.h"

#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

Entropy::Application::Application()
{
	window = std::unique_ptr<Entropy::Window>(Entropy::Window::Create());
	window->SetEventCallback(BIND_EVENT_FUNCTION(Application::OnEvent));
}

Entropy::Application::~Application()
{
}

void Entropy::Application::Run()
{
	Entropy::log::header("Entropy Engine: Default Run.");

	while (running)
	{
		window->OnUpdate();
	}
}

void Entropy::Application::OnEvent(Event& e)
{
	Entropy::log::trace(e);
}
