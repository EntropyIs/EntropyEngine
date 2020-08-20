#include <EntropyCore.h>
#include <EntropyGraphics.h>

#include <exception>

int main(int argc, char* argv)
{
	Entropy::log::init(true);

	try {
		Entropy::Window window("My GLWindow");
	}
	catch (std::exception& e) {
		Entropy::log::error(e.what());
	}

	Entropy::log::shutdown();
}