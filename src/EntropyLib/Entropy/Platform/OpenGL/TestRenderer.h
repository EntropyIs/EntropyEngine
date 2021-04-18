#pragma once

#include "GL_Renderer.h"

namespace Entropy
{
	namespace Graphics
	{
		class TestRenderer : public GL_Renderer
		{
		public:
			TestRenderer() : GL_Renderer() {};
			TestRenderer(float vertices[], unsigned int numVertices, std::string shader);


			// Inherited via GL_Renderer
			virtual void OnUpdate() override;
			virtual void OnRender() override;
		};
	}
}

