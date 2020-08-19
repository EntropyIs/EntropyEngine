#pragma once

#include "API.h"

namespace Entropy {
	class ENTROPY_GRAPHICS_API Window
	{
	public:
		Window(const char* title, unsigned int width = 800U, unsigned int height = 600U, unsigned int numSamples = 4U);

		void bind();
		void clear();
		void processEvents();

		bool getShouldClose();

	private:
		bool initGLFW(unsigned int numSamples);
	};
}
