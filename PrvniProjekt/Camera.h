#pragma once
#include "AllLibs.h"

class Camera
{
private:
	glm::vec3 eye= glm::vec3(0.0f , 0.0f, 2.0f);
	glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	void setViewMatrix();
public:
	void setTargetPosition(glm::vec3 targetPosition);
	void setEye(glm::vec3 eye);
	void setUpVector(glm::vec3 upVec);
	glm::vec3 getTarget();
	glm::vec3 getUp();
	glm::vec3 getEye();
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
	Camera();
	~Camera();
};

