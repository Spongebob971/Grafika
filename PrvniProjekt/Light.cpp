#include "Light.h"

void Light::setColor(glm::vec3 color) {
	this->color = color;
}

void Light::setPosition(glm::vec3 position) {
	this->position = position;
}

glm::vec3 Light::getColor() {
	return this->color;
}

glm::vec3 Light::getPosition() {
	return this->position;
}

Light::Light()
{
}

void Light::setVertices(const struct Vertex* array, int sizeOfArray)
{

	GLuint VAO = 0;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	GLuint VBO = 0;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeOfArray, array, GL_STATIC_DRAW);
	//pos??
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	// normal??
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));

}

Light::~Light()
{
}
