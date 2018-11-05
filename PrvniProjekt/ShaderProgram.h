#pragma once
#include "AllLibs.h"
class ShaderProgram
{
	GLuint shaderProgram;
public:
	GLuint getShader();
	void attachShaders(GLuint vertexShader, GLuint fragmentShader);
	ShaderProgram();
	~ShaderProgram();
};

