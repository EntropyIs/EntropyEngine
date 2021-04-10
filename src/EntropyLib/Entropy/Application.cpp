#include "ecpch.h"
#include "Application.h"

#include "Entropy/Tools/Log.h"

Entropy::Application::Application()
{
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
