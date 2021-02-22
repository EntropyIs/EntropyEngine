#include <EntropyCore.h>

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
	}

	virtual void Run() override
	{
		Entropy::log::header("Entropy Engine: Sandbox Run.");
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