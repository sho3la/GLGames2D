#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <memory>

class Window
{
public:
	Window(const char* title, int width, int height);

	~Window();

	GLFWwindow* m_window;
	int m_width;
	int m_height;
};

typedef std::shared_ptr<Window> WindowPtr;