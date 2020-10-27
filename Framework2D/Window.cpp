#include "Window.h"
#include <iostream>
using namespace std;

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

Window::Window(const char * title, int width, int height)
{
	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false);


	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!m_window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	m_width = width;
	m_height = height;

}

Window::~Window()
{
	glfwDestroyWindow(m_window);

	glfwTerminate();
}
