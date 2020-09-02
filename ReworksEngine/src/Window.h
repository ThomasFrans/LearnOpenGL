#pragma once
#include <GLFW\glfw3.h>

namespace Reworks {

	class Window
	{
	public:
		Window(int width, int height, const char* title);
		~Window();
		GLFWwindow* getWindow();
		void processInput();
	private:
		GLFWwindow* window;
	};

}