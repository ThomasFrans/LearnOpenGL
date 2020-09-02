#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "Window.h"

#include <iostream>

namespace Reworks {

	Window::Window(int width, int height, const char* title)
	{
		// Initialize and setup GLFW
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		// Create the GLFW window
		Window::window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);

		// Initialize glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}

		// Set the size of the OpenGL viewport inside the window
		glViewport(0, 0, 1280, 720);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	GLFWwindow* Window::getWindow()
	{
		return Window::window;
	}

	void Window::processInput()
	{
		if (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(Window::window, true);
	}

}
