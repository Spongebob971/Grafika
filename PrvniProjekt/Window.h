#pragma once
#include "AllLibs.h"

class Window
{
private:
	int width;
	int height;
	GLFWwindow* window;
public:
	int getWidth();
	int getHeight();
	Window();
	Window(int width, int height, const char *title, GLFWmonitor* monitor, GLFWwindow* share);
	~Window();
	GLFWwindow* getWindow();
};


