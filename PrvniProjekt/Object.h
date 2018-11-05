#pragma once
#include "AllLibs.h"
class Object
{
private:
	GLuint VAO;
	GLuint VBO;
	glm::vec3 vecTranslate; // position
	glm::vec3 objColor;
	glm::mat4 M;
public:
	Object();
	~Object();
	void setPosition(glm::vec3 vec);
	void setColor(glm::vec3 vec);
	void setVertices(float pole[], int sizeOfArray);
	void setVertices( const struct Vertex* array, int sizeOfArray);
	void setM(glm::mat4 M);
	glm::mat4 getM();
	glm::vec3 getColor();
	glm::vec3 getTranslate();
	GLuint getVAO();
	GLuint getVBO();
};

