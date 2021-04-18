#pragma once
#include "Entropy/Tools/API.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API GL_Shader
		{
		public:
			GL_Shader() : _ID(0) {};
			GL_Shader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometaryShaderPath = nullptr);

			void Use() const;

		private:
			unsigned int _ID;
			unsigned int Compile(const char* path, unsigned int type);
		};
	}
}