#pragma once
#include "Entropy/Tools/API.h"
#include "Entropy/Graphics/Renderer.h"

#include <string>

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

		protected:
			unsigned int _VAO;
			unsigned int _numVertices;
			std::string _shader;
		};
	}
}
