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
		// TODO: Handle Layer Events, and Pass to Game Elements as applicable
		Entropy::LOG::Trace("EXAMPLE_LAYER", e);
	}
};

class Sandbox : public Entropy::Application
{
public:
	virtual void Init(bool debug = false) override
	{
		Entropy::LOG::Init(debug);
		Entropy::LOG::Header("APP", "Entropy Engine: Default Initalization.");

		_window = std::unique_ptr<Entropy::Window>(Entropy::Window::Create(Entropy::WindowProps("Sandbox")));
		_window->SetEventCallback(BIND_EVENT_FUNCTION(Entropy::Application::OnEvent));

		_running = true;

		PushLayer(new ExampleLayer());
	}
};

Entropy::Application* Entropy::CreateApplication()
{
	return new Sandbox();
}