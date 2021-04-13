#include <EntropyCore.h>
#include <Entropy/Events/ApplicationEvents.h>

#include <exception>

class Sandbox : public Entropy::Application
{
public:
	Sandbox() {};
	~Sandbox() {};
};

Entropy::Application* Entropy::CreateApplication()
{
	return new Sandbox();
}