#include "Window.h"

Window* Window::window = NULL;

Window::Window()
{
	glfwWindow = NULL;
}

Window::~Window()
{
	delete Window::window;
}

Window* Window::get()
{
	if (Window::window == NULL)
	{
		Window::window = new Window();
	}

	return Window::window;
}

void Window::run()
{
	std::cout << "Hello GLFW\n";

	init();
	loop();

	// Free the memory
	glfwTerminate();
}

void Window::init()
{
	// Initialize GLFW
	if (!glfwInit()) {
		std::cout << "Erro ao inicializar o GLFW\n";
	}
	
	// Configure GLFW
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);

	// Create the Window
	glfwWindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title, NULL, NULL);
	if (glfwWindow == NULL) {
		std::cout << "Erro ao criar a janela\n";
	}

	// Make OpenGL context current
	glfwMakeContextCurrent(glfwWindow);

	// Glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Erro ao inicializar o GLAD\n";
	}

	// Enable v-sync
	glfwSwapInterval(1);

	// Make the window visible
	glfwShowWindow(glfwWindow);
}

void Window::loop()
{
	while (!glfwWindowShouldClose(glfwWindow)) {
		// Poll events
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(glfwWindow);
	}
}