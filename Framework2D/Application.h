#pragma once
#include "Window.h"
#include "TimeStep.h"
#include <memory>

class Application
{
public:
	Application();

	~Application();

	virtual void loadResources();

	virtual void init();

	virtual void update(TimeStep time);

	virtual void render();

	WindowPtr m_window;
};

typedef std::shared_ptr<Application> ApplicationPtr;