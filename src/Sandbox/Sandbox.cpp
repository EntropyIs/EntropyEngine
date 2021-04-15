#include <EntropyCore.h>
#include <Entropy/Events/ApplicationEvents.h>

#include <exception>

class ExampleLayer : public Entropy::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		Entropy::log::message("ExampleLayer::Update");
	}

	void OnEvent(Entropy::Event& e) override
	{
		Entropy::log::trace(e);
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