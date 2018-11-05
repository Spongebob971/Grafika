#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	this->VBO = 0;
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);	
}


VertexBuffer::~VertexBuffer()
{
}

GLuint VertexBuffer::getVBO() {
	return this->VBO;
}
