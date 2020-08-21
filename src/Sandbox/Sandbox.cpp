#include <EntropyCore.h>

#include <exception>

class Sandbox : public Entropy::Application
{
public:
	Sandbox() {};
	~Sandbox() {};

	// Inherited via Application
	virtual void Run() override
	{
		Entropy::log::init(true);
		Entropy::log::message("Entropy Engine");
		Entropy::log::shutdown();
	}

};

Entropy::Application* Entropy::CreateApplication()
{
	return new Sandbox();
}