#include "Engine.h"
#include <glad/gl.h>

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::start(ApplicationPtr app, const char* window_title, int window_width, int window_height)
{
	m_app = app;
	init(window_title,window_width,window_height);
}

void Engine::init(const char* window_title, int window_width, int window_height)
{
	// create window
	m_app->m_window = std::make_shared<Window>(window_title, window_width, window_height);

	// init opengl
	gladLoadGL(glfwGetProcAddress);

	// start gameloop
	m_app->loadResources();

	m_app->init();

	// mainloop
	while (!glfwWindowShouldClose(m_app->m_window->m_window))
	{
		gameloop();

		glfwSwapBuffers(m_app->m_window->m_window);
		glfwPollEvents();
	}
}

void Engine::gameloop()
{
	update();

	render();
}


void Engine::update()
{
	m_app->update();
}


void Engine::render()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	m_app->render();
}