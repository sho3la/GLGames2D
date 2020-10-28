#pragma once
#include "Application.h"
#include "Keyboard.h"
#include "TimeStep.h"
#include "Camera2D.h"
#include "SpriteRenderer.h"

class Engine
{
public:
	Engine();

	~Engine();

	void start(ApplicationPtr app, const char* window_title, int window_width, int window_height);

	static SpriteRendererPtr sp_renderer;

	static void set_limit(int frame_limit);
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
	float frame_limit_counter = 0.0f;
	TimeStep tstep;
	static float m_frame_limit;
};