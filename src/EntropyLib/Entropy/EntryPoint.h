#pragma once

#ifdef ENTROPY_PLATFORM_WINDOWS

extern Entropy::Application* Entropy::CreateApplication();

#ifdef ENTROPY_DEBUG
int main(int argc, char** argv)
{
	auto app = Entropy::CreateApplication();
	app->Run();
	delete app;
}
#else
int WinMain()
{
	auto app = Entropy::CreateApplication();
	app->Run();
	delete app;
}
#endif // ENTROPY_DEBUG

	
#endif // ENTROPY_PLATFORM_WINDOWS