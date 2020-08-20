#include "Window.h"

#include <Log.h>

Entropy::Window::Window(const char* title, unsigned int width, unsigned int height, unsigned int numSamples, 
	bool depthTest, bool stencilTest, bool faceCulling) :
	Width(width), Height(height), targetRatio((float) width / (float) height), vpX(0), vpY(0), vpWidth(width), vpHeight(height),
	depthTest(depthTest), stencilTest(stencilTest), faceCulling(faceCulling), targetRatioSet(false)
{
	if(!initGLFW(numSamples))
		throw std::exception("Failed to initalize GLFW");

	// Initalize OpenGL Window
	GLWindow = glfwCreateWindow(Width, Height, title, NULL, NULL);
	if (GLWindow == NULL)
		throw std::exception("Failed to create GL Window");
	glfwMakeContextCurrent(GLWindow);
	glfwSetWindowUserPointer(GLWindow, reinterpret_cast<void*>(this));
	glfwSetFramebufferSizeCallback(GLWindow, framebuffer_size_callback);

	if(!initGLEW())
		throw std::exception("Failed to initialize GLEW");

	bind();
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_FRAMEBUFFER_SRGB);
}

void Entropy::Window::bind()
{
	glViewport(vpX, vpY, vpWidth, vpHeight);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	if (depthTest)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);

	if (stencilTest)
		glEnable(GL_STENCIL_TEST);
	else
		glDisable(GL_STENCIL_TEST);

	if (faceCulling)
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);
}

void Entropy::Window::clear()
{
	glClearColor(clearColor.R, clearColor.G, clearColor.B, clearColor.A);
	if (depthTest == true && stencilTest == true)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	else if (depthTest == true && stencilTest == false)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else if (depthTest == false && stencilTest == true)
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
}

void Entropy::Window::processEvents()
{
}

bool Entropy::Window::getShouldClose()
{
	return glfwWindowShouldClose(GLWindow);
}

void Entropy::Window::setShouldClose(bool value)
{
	glfwSetWindowShouldClose(GLWindow, value);
}

void Entropy::Window::setClearColor(float red, float green, float blue, float alpha)
{
	clearColor.R = red;
	clearColor.G = green;
	clearColor.B = blue;
	clearColor.A = alpha;
}

void Entropy::Window::setResolution(unsigned int targetWidth, unsigned int targetHeight)
{
	targetRatio = (float)targetWidth / (float)targetHeight;
	tWidth = targetWidth;
	tHeight = targetHeight;
	targetRatioSet = true;
	calulateViewport();
}

void Entropy::Window::enableDepthTest(bool value)
{
	depthTest = value;
}

void Entropy::Window::enableStencilTest(bool value)
{
	stencilTest = value;
}

void Entropy::Window::enableFaceCulling(bool value)
{
	faceCulling = value;
}

bool Entropy::Window::initGLFW(unsigned int numSamples)
{
	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ENTROPY_PLATFORM_APPLE
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_SAMPLES, numSamples);

	return true;
}

bool Entropy::Window::initGLEW()
{
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		Entropy::log::error((const char*) glewGetErrorString(error));
		return false;
	}
	return true;
}

void Entropy::Window::calulateViewport()
{
	if (targetRatioSet)
	{
		// Determine if Pillarbox or Letterbox is needed.
		vpWidth = Width;
		vpHeight = (unsigned int)(vpWidth / targetRatio + 0.5f);

		if (vpHeight > Height)
		{
			vpHeight = Height;
			vpWidth = (unsigned int)(vpHeight * targetRatio + 0.5f);
		}

		// Set Viewport Position
		vpX = (Width / 2) - (vpWidth / 2);
		vpY = (Height / 2) - (vpHeight / 2);

		// SetScaling
		float scale_x = (float)((float)Width / (float)tWidth);
		float scale_y = (float)((float)Height / (float)tHeight);
		glScalef(scale_x, scale_y, 1.0f);
	}
	else
	{
		vpWidth = Width;
		vpHeight = Height;
		vpX = 0;
		vpY = 0;
	}
}

void Entropy::Window::framebuffer_size_callback(GLFWwindow* glWindow, int width, int height)
{
	Window* window = reinterpret_cast<Window*>(glfwGetWindowUserPointer(glWindow));
	window->Width = width;
	window->Height = height;
}
