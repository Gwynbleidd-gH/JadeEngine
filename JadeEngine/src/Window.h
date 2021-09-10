#pragma once
#include "includes.h"

class Window
{
private:
	const int SCREEN_WIDTH = 2560;
	const int SCREEN_HEIGHT = 1440;

private:
	const char* title = "Mario";
	GLFWwindow* glfwWindow;

	static Window* window;

public:
	static Window* get();

private:
	Window();
	~Window();

public:
	void run();

	void init();

	void loop();
};
