#include <EntropyCore.h>
#include <Entropy/Events/ApplicationEvents.h>
#include <Entropy/Platform/OpenGl/GL_Shader.h>
#include <Entropy/Platform/OpenGL/TestRenderer.h>

#include "EPCH.h"

class ExampleLayer : public Entropy::Layer
{
public:
	ExampleLayer() : Layer("EXAMPLE_LAYER")
	{
		shader = Entropy::Graphics::GL_Shader("Assets/vTestShader.glsl", "Assets/fTestShader.glsl");
		shader.Use();

		float vertices[] = {
			-0.5f,  0.5f,
			 0.5f, -0.5f,
			 0.0f,  0.5f
		};
		renderer = Entropy::Graphics::TestRenderer(vertices, 3, "shader");
	}

	void OnUpdate() override
	{
		// Clear Layer
		renderer.OnRender();
	}

	void OnEvent(Entropy::Event& e) override
	{
		// TODO: Handle Layer Events, and Pass to Game Elements as applicable
		Entropy::LOG::Trace("EXAMPLE_LAYER", e);
	}

private:
	Entropy::Graphics::TestRenderer renderer;
	Entropy::Graphics::GL_Shader shader;
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