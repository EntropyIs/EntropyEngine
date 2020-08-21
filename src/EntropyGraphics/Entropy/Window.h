#pragma once

#include "Tools/API.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Entropy {
	class ENTROPY_GRAPHICS_API Window
	{
	private:
		struct ClearColor {
			float R, G, B, A;
		};

		ClearColor clearColor;
		bool depthTest,stencilTest,faceCulling;

		bool targetRatioSet;
		float targetRatio;

		unsigned int tWidth, tHeight;
		unsigned int vpWidth, vpHeight;
		unsigned int vpX, vpY;

	public:
		GLFWwindow* GLWindow;
		unsigned int Width, Height;

		Window(const char* title, unsigned int width = 800U, unsigned int height = 600U, unsigned int numSamples = 4U,
			bool depthTest = true, bool stencilTest = false, bool faceCulling = false);

		void bind();
		void clear();
		void processEvents();

		bool getShouldClose();

		void setShouldClose(bool value);
		void setClearColor(float red, float green, float blue, float alpha);
		void setResolution(unsigned int targetWidth, unsigned int targetHeight);

		void enableDepthTest(bool value = true);
		void enableStencilTest(bool value = true);
		void enableFaceCulling(bool value = true);

	private:
		bool initGLFW(unsigned int numSamples);
		bool initGLEW();

		void calulateViewport();

		static void framebuffer_size_callback(GLFWwindow* glWindow, int width, int height);
	};
}
