#include "window.h"

Window::Window()
{
	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	this->width = 800;
	this->height = 600;
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
}

Window::Window(int width, int height, const char *title, GLFWmonitor* monitor, GLFWwindow* share)
{
	window = glfwCreateWindow(width, height, title, monitor, share);
}

GLFWwindow* Window::getWindow()
{
	return window;
}

int Window::getHeight() {
	return height;
}

int Window::getWidth() {
	return width;
}

Window::~Window()
{
}
