#pragma once
#include "Application.h"
#include "Keyboard.h"
#include "TimeStep.h"
#include "Camera2D.h"

class Engine
{
public:
	Engine();

	~Engine();

	void start(ApplicationPtr app, const char* window_title, int window_width, int window_height);

	static Camera2DPtr camera2d;

private:
	void init(const char* window_title, int window_width, int window_height);

	void gameloop();

	void update();

	void render();

	ApplicationPtr m_app;
	KeyboardPtr m_keyboard;

	//timing
	float deltatime = 0.0f;
	float lastframe = 0.0f;
	TimeStep tstep;
};