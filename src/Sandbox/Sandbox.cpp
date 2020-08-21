#include <EntropyCore.h>
#include <EntropyGraphics.h>

#include <exception>

class Sandbox : public Entropy::Application
{
public:
	Sandbox() {};
	~Sandbox() {};

	// Inherited via Application
	virtual void Run() override
	{
		try {
			Entropy::log::init(true);
			Entropy::Window window("My GLWindow");

			window.setClearColor(0.2f, 0.3f, 0.3f, 1.0f);

			while (!window.getShouldClose())
			{
				window.bind();
				window.clear();

				window.processEvents();
			}

			Entropy::log::shutdown();
		}
		catch (std::exception& e) {
			Entropy::log::error(e.what());
			Entropy::log::shutdown();
		}
	}

};

Entropy::Application* Entropy::CreateApplication()
{
	return new Sandbox();
}