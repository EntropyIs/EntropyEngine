#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Log.h>

Entropy::Window::Window(const char* title, unsigned int width, unsigned int height, unsigned int numSamples)
{
	initGLFW(numSamples)
}

void Entropy::Window::bind()
{
}

void Entropy::Window::clear()
{
}

void Entropy::Window::processEvents()
{
}

bool Entropy::Window::getShouldClose()
{
	return false;
}

bool Entropy::Window::initGLFW(unsigned int numSamples)
{
	if (!glfwInit()) {
		Entropy::log::error("Failed to inialize GLFW.");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ENTROPY_PLATFORM_APPLE
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_SAMPLES, numSamples);
}
