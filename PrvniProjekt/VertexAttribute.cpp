#include "VertexAttribute.h"



VertexAttribute::VertexAttribute()
{
	this->VAO = 0;
	glGenVertexArrays(1, &this->VAO); //generate the VAO
	glBindVertexArray(this->VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
}

GLuint VertexAttribute::getVAO() {
	return this->VAO;
}

VertexAttribute::~VertexAttribute()
{
}

