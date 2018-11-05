#include "Camera.h"


void Camera::setEye(glm::vec3 eye) {
	this->eye = eye;
	setViewMatrix();
}

void Camera::setTargetPosition(glm::vec3 targetPosition) {
	this->target = targetPosition;
	setViewMatrix();
}

void Camera::setUpVector(glm::vec3 upVec) {
	this->up = upVec;
	setViewMatrix();
}

Camera::Camera()
{
	float var = 800 / 600;
	//projectionMatrix = glm::perspective(35.0f, var, 0.1f, 10.0f);
	projectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	viewMatrix = glm::lookAt(eye, target, up);
	//viewMatrix = glm::rotate();
}

void Camera::setViewMatrix() {
	viewMatrix = glm::lookAt(eye, target, up);
}

glm::mat4 Camera::getViewMatrix()
{
	return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() {
	return projectionMatrix;
}

glm::vec3 Camera::getEye() {
	return this->eye;
}

glm::vec3 Camera::getUp() {
	return this->up;
}

glm::vec3 Camera::getTarget() {
	return this->target;
}

Camera::~Camera()
{
}

 