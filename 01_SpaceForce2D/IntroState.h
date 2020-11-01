#pragma once
#include "State.h"
#include <memory>

class IntroState : public State
{
public:
	IntroState();

	~IntroState();

	void update(Game* game, TimeStep time) override;

	void draw() override;

private:
	std::shared_ptr<Texture2D> tex;
	std::shared_ptr<Rectangle> rect;
};