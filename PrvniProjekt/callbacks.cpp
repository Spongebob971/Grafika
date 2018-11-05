#include "callbacks.h"
#pragma once

void Callbacks::error_callback(int error, const char * description)
{
	fputs(description, stderr);
}

unsigned int Callbacks::btnCharTouch = 0;

void Callbacks::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
	if (key == 265 && scancode == 328 && action == 1 && mods == 0) {
		Callbacks::btnCharTouch = 1;
	}
	else if(key == 265 && scancode == 328 && action == 0 && mods == 0) {
		Callbacks::btnCharTouch = 2;
	}

}

void Callbacks::window_focus_callback(GLFWwindow * window, int focused)
{
	printf("window_focus_callback \n");
}

void Callbacks::window_iconify_callback(GLFWwindow * window, int iconified)
{
	printf("window_iconify_callback \n");
}

void Callbacks::window_size_callback(GLFWwindow * window, int width, int height)
{
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

unsigned int Callbacks::posX = 0;
unsigned int Callbacks::posY = 0;
void Callbacks::cursor_callback(GLFWwindow * window, double x, double y)
{
	Callbacks::posX = x;
	Callbacks::posY = y;
}

unsigned int Callbacks::click = 0;

void Callbacks::button_callback(GLFWwindow * window, int button, int action, int mode)
{
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}