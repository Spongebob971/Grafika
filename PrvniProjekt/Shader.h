#pragma once
#include "AllLibs.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class Shader
{
private:
	glm::mat4 M = glm::mat4(1.0f);
	std::string wtf;
	GLuint shaderProgram;
	GLuint vertexShader;
	GLuint fragmentShader;
	glm::vec3 lightPos;
	GLint modelMatrixID;
	glm::vec3 translate;
	glm::vec4 color;
	GLint uniformID;
	void shaderChecker();
public:
	void setLampShader();
	void setM(glm::mat4 M);
	void setTranslate(glm::vec3 translate);
	void createShader();
	void sendUniform(const GLchar *name, glm::vec3 data);
	void sendUniform(const GLchar *name, glm::vec4 data);
	void sendUniform(const GLchar *name, glm::mat4 data);
	void rotate(float rotation);
	GLuint getProgram();
	Shader();
	~Shader();
};

