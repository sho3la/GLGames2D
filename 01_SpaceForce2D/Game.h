#pragma once
#include "Application.h"
#include "Texture2D.h"
#include "Rectangle.h"

class Game : public Application
{
public:
	Game();

	~Game();

	void loadResources() override;

	void init() override;

	void update(TimeStep time) override;

	void render() override;

	std::shared_ptr<Texture2D> tex;
	std::shared_ptr<Rectangle> rect2;
};
