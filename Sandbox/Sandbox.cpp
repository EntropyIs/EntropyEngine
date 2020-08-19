#include <EntropyCore.h>

int main(int argc, char* argv)
{
	Entropy::log::init(true);
	Entropy::log::message("hello_world");
	Entropy::log::shutdown();
}