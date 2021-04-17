#include <EntropyCore.h>
#include <Entropy/Events/ApplicationEvents.h>

#include <GLFW/glfw3.h>

#include <exception>

class ExampleLayer : public Entropy::Layer
{
public:
	ExampleLayer() : Layer("EXAMPLE_LAYER") {}

	void OnUpdate() override
	{
		// Clear Layer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
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