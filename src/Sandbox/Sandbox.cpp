#include <EntropyCore.h>
#include <Entropy/Events/ApplicationEvents.h>

#include <exception>

class ExampleLayer : public Entropy::Layer
{
public:
	ExampleLayer() : Layer("EXAMPLE_LAYER") {}

	void OnUpdate() override
	{
		Entropy::log::message("EXAMPLE_LAYER","Update");
	}

	void OnEvent(Entropy::Event& e) override
	{
		Entropy::log::trace("EXAMPLE_LAYER", e);
	}
};

class Sandbox : public Entropy::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Entropy::Application* Entropy::CreateApplication()
{
	return new Sandbox();
}