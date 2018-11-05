#pragma once
#include "AllLibs.h"
/*
//GLM test
// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
static glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

// Camera matrix
static glm::mat4 View = glm::lookAt(
	glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
	glm::vec3(0, 0, 0), // and looks at the origin
	glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
);
// Model matrix : an identity matrix (model will be at the origin)
static glm::mat4 Model = glm::mat4(1.0f);
*/
/*
glm::mat4 M = glm::mat4(1.0f);

glm::mat4 M = glm::rotate(glm::mat4(1.0f), 10.0f, glm::vec3(0.0f, 1.0f, 0.0f));
glm::mat4 M = glm::rotate(M, 20.0f, glm::vec3(1.0f, 0.0f, 0.0f));
glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.1f));
glm::mat4 M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
*/

