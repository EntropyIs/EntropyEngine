#pragma once
#include "Entropy/Tools/API.h"
#include "Entropy/Graphics/Renderer.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API GL_Renderer : public Renderer
		{
		public:
			GL_Renderer() : _VAO(0), _numVertices(0), _shader() {};
			GL_Renderer(unsigned int VAO, unsigned int numVertices, std::string shader) : _VAO(VAO), _numVertices(numVertices), _shader(shader) {};
			virtual ~GL_Renderer();

			// Inherited via Renderer
			virtual void OnUpdate() override = 0;
			virtual void OnRender() override = 0;

		protected:
			unsigned int _VAO;
			unsigned int _numVertices;
			std::string _shader;
		};
	}
}
