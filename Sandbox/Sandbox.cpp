#include <EntropyCore.h>

int main(int argc, char* argv)
{
	Entropy::log::init(true);
	Entropy::log::message("this is a message log");
	Entropy::log::error("this is an error");
	Entropy::log::shutdown();
}