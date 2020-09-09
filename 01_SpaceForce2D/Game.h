#pragma once
#include "Application.h"

class Game : public Application
{
public:
	Game();

	~Game();

	void loadResources() override;

	void init() override;

	void update() override;

	void render() override;
};
