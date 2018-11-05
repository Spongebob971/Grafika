#include "ShaderProgram.h"



void ShaderProgram::attachShaders(GLuint vertexShader, GLuint fragmentShader)
{
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);
}

ShaderProgram::ShaderProgram()
{
	this->shaderProgram = glCreateProgram();
}

GLuint ShaderProgram::getShader() {
	return shaderProgram;
}

ShaderProgram::~ShaderProgram()
{
}


