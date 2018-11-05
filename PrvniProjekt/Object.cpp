#pragma once
#include "Object.h"
//#include "sphere.h"

float body[] = {
	0.0f, 0.5f, 0.0f,
	0.5f, 0.0f, 0.0f,
	-0.5f, 0.0f, 0.0f
};

Object::Object()
{
}

GLuint Object::getVAO() {
	return VAO;
}

GLuint Object::getVBO() {
	return VBO;
}

void Object::setVertices(float pole[], int sizeOfArray) {

	VAO = 0;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	VBO = 0;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeOfArray, pole, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
}

void Object::setVertices( const struct Vertex* array, int sizeOfArray)
{	
	VAO = 0;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	VBO = 0;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeOfArray, array, GL_STATIC_DRAW);
	//pos??
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	// normal??
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	
}

void Object::setPosition(glm::vec3 vec3) {
	this->vecTranslate = vec3;
}


void Object::setColor(glm::vec3 vec) {
	this->objColor = vec;
}

void Object::setM(glm::mat4 M) {
	this->M = M;
}

glm::vec3 Object::getTranslate() {
	return this->vecTranslate;
}

glm::mat4 Object::getM() {
	return this->M;
}

glm::vec3 Object::getColor() {
	return this->objColor;
}

Object::~Object()
{
}
