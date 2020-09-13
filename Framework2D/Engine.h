#pragma once
#include "Application.h"
#include "Keyboard.h"

class Engine
{
public:
	Engine();

	~Engine();

	void start(ApplicationPtr app, const char* window_title, int window_width, int window_height);

private:
	void init(const char* window_title, int window_width, int window_height);

	void gameloop();

	void update();

	void render();

	ApplicationPtr m_app;
	KeyboardPtr m_keyboard;
};