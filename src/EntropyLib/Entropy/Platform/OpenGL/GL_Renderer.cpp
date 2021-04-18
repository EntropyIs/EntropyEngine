#include "EPCH.h"
#include "GL_Renderer.h"



Entropy::Graphics::GL_Renderer::~GL_Renderer()
{
	glDeleteVertexArrays(1, &_VAO);
}
