#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "Window.h"

#include <iostream>



int main()
{

	Reworks::Window window(1280, 720, "Reworks");

	while (!glfwWindowShouldClose(window.getWindow()))
	{
		window.processInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	return 0;
}

