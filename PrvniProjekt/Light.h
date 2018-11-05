#pragma once
#include"AllLibs.h"
class Light
{
private:
	glm::vec3 position;
	glm::vec3 color;
	glm::mat4 model;
public:
	Light();
	~Light();
	void setVertices(const struct Vertex* array, int sizeOfArray);
	void setPosition(glm::vec3 position);
	void setColor(glm::vec3 color);

	glm::vec3 getPosition();
	glm::vec3 getColor();
};

