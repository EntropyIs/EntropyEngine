#include "EPCH.h"
#include "TestRenderer.h"

Entropy::Graphics::TestRenderer::TestRenderer(float vertices[], unsigned int numVertices, std::string shader)
{
	unsigned int VBO;

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(&vertices[0]), &vertices[0], GL_STATIC_DRAW);

	glBindVertexArray(_VAO);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0); // X, Y
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void Entropy::Graphics::TestRenderer::OnUpdate()
{
}

void Entropy::Graphics::TestRenderer::OnRender()
{
	// Render
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, _numVertices);
	glBindVertexArray(0);
}
