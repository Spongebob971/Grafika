#include "AllLibs.h"
#include <math.h>
#include"sphere.h"
#define M_PI 3.14159265358979323846

void bind(Object* object, Shader* shader, Window* myWindow);
void processInput(GLFWwindow *window, Camera* cam);
float radius = 20.0f;
float cameraSpeedX = 0.00f;
float cameraSpeedY = 0.00f;
float cameraSpeedZ = 0.00f;
int main(void)
{
	glfwSetErrorCallback(Callbacks::error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}
	Window* myWindow = new Window();
	glfwMakeContextCurrent(myWindow->getWindow());
	glfwSwapInterval(1);
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	InfoVersion* infoVersion = new InfoVersion();
	infoVersion->getInfo();

	Shader* shader = new Shader();
	shader->createShader();
	Shader *lampShader = new Shader();

	Camera *cam = new Camera();

	Light* light = new Light();
	light->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	light->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	Object* object = new Object();
	object->setVertices(sphereVertices, sizeof(sphereVertices));
	object->setColor(glm::vec3(1.0, 1.0, 0.0));
	object->setM(glm::mat4(1.0f));
	object->setPosition(glm::vec3(4.0f, 0.0f, 0.0f));

	Object *object2 = new Object();
	object2->setVertices(squareVertices, sizeof(squareVertices));
	object2->setColor(glm::vec3(1.0, 0.0, 0.0));
	object2->setM(glm::mat4(1.0f));
	object2->setPosition(glm::vec3(-4.0f, -4.0f, 0.0f));

	Object *object3 = new Object();
	object3->setVertices(sphereVertices, sizeof(sphereVertices));
	object3->setColor(glm::vec3(0.0, 1.0, 0.0));
	object3->setM(glm::mat4(1.0f));
	object3->setPosition(glm::vec3(-4.0f, 0.0f, 4.0f));

	Object *object4 = new Object();
	object4->setVertices(sphereVertices, sizeof(sphereVertices));
	object4->setColor(glm::vec3(0.0, 0.0, 1.0));
	object4->setM(glm::mat4(1.0f));
	object4->setPosition(glm::vec3(4.0f, 0.0f, 4.0f));

	float radius = 50.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;

	cam->setEye(glm::vec3(camX, 0.0f, camZ));
	cam->setTargetPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	while (!glfwWindowShouldClose(myWindow->getWindow()))
	{
		glfwSwapBuffers((myWindow->getWindow()));
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(myWindow->getWindow(), cam);

		shader->sendUniform("viewMatrix", cam->getViewMatrix());
		shader->sendUniform("projectionMatrix", cam->getProjectionMatrix());
		shader->sendUniform("lightColor", light->getColor());
		shader->sendUniform("viewPos", cam->getEye());
		shader->sendUniform("lightPos", light->getPosition());

		shader->setTranslate(object->getTranslate());
		shader->sendUniform("objectColor", object->getColor());
		shader->setM(object->getM());
		bind(object, shader, myWindow);
		shader->rotate(0.00f);

		shader->setTranslate(object3->getTranslate());
		shader->sendUniform("objectColor", object3->getColor());
		shader->setM(object3->getM());
		bind(object, shader, myWindow);
		shader->rotate(0.00f);

		shader->setTranslate(object4->getTranslate());
		shader->sendUniform("objectColor", object4->getColor());
		shader->setM(object4->getM());
		bind(object, shader, myWindow);
		shader->rotate(0.00f);

		shader->setTranslate(object2->getTranslate());
		shader->sendUniform("objectColor", object2->getColor());
		shader->setM(object2->getM());
		bind(object2, shader, myWindow);
		shader->rotate(0.00f);
	}
}

void bind(Object* object, Shader* shader, Window* myWindow) {
	glUseProgram(shader->getProgram());
	glBindVertexArray(object->getVAO());
	glDrawArrays(GL_TRIANGLES, 0, 2900);
	glfwPollEvents();
}
float camY = 0.0f;

void processInput(GLFWwindow *window, Camera* cam)
{
	float camX = sin(glfwGetTime() *cameraSpeedX) * radius;
	float camZ = cos(glfwGetTime()* cameraSpeedZ) * radius ;
	float camY = sin(glfwGetTime()* cameraSpeedY) * radius;
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
		radius -= 0.1f;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		radius += 0.1f;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		cameraSpeedY -= 0.01f;
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cameraSpeedX -= 0.01f;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraSpeedZ += 0.01f;
	}
	cam->setEye(glm::vec3(camX, camY, camZ));
	cam->setTargetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
}