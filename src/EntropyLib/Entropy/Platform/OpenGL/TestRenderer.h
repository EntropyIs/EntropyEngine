#pragma once
#include "GL_Renderer.h"

#include "Entropy/Tools/Log.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API TestRenderer : public GL_Renderer
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
