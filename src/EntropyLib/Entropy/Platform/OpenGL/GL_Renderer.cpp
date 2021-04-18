#include "EPCH.h"
#include "GL_Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Entropy::Graphics::GL_Renderer::~GL_Renderer()
{
	glDeleteVertexArrays(1, &_VAO);
}
