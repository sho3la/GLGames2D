#pragma once
#include "Application.h"
#include "State.h"

class Game : public Application
{
public:
	Game();

	~Game();

	void loadResources() override;

	void init() override;

	void update(TimeStep time) override;

	void render() override;

	State* current_state;
};
