#include "Engine.h"
#include <glad/gl.h>

SpriteRendererPtr Engine::sp_renderer;

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
	m_keyboard		= std::make_shared<Keyboard>();

	// init opengl
	gladLoadGL(glfwGetProcAddress);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	sp_renderer = std::make_shared<SpriteRenderer>(m_app->m_window->m_width, m_app->m_window->m_height);

	// start gameloop
	m_app->loadResources();

	m_app->init();

	glfwSetKeyCallback(m_app->m_window->m_window, &Keyboard::KeyboardFunc);

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
	//per frame time
	//---------------
	float currnetframe = (float)glfwGetTime();
	deltatime = currnetframe - lastframe;
	lastframe = currnetframe;
	tstep.deltaTime = deltatime;
	tstep.elapsedTime = currnetframe;

	update();

	render();
}


void Engine::update()
{
	m_app->update(tstep);
}


void Engine::render()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	m_app->render();
}