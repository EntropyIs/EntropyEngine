#include <EntropyCore.h>
#include <Entropy/Events/ApplicationEvents.h>

#include <exception>

class Sandbox : public Entropy::Application
{
public:
	Sandbox() {};
	~Sandbox() {};

	// Inherited via Application
	virtual void Init(bool _debug) override
	{
		Entropy::log::init(_debug);
		Entropy::log::header("Entropy Engine: Sandbox Initalization.");

		window = std::unique_ptr<Entropy::Window>(Entropy::Window::Create());
		running = true;
	}

	virtual void Run() override
	{
		Entropy::log::header("Entropy Engine: Sandbox Run.");
		while(running)
		{
			window->OnUpdate();
		}
	}
	
	virtual void Shutdown() override
	{
		Entropy::log::header("Entropy Engine: Sandbox Shutdown.");
		Entropy::log::shutdown();
	}
	
};

Entropy::Application* Entropy::CreateApplication()
{
	return new Sandbox();
}