#pragma once
#include "AllLibs.h"

class VertexAttribute
{
	GLuint VAO = 0;
public:
	GLuint getVAO();
	VertexAttribute();
	~VertexAttribute();
};

