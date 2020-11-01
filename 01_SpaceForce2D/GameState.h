#pragma once
#include "State.h"
#include <memory>

class GameState : public State
{
public:
	GameState();

	~GameState();

	void update(Game* game, TimeStep time) override;

	void draw() override;


private:
	std::shared_ptr<Texture2D> tex2;
	std::shared_ptr<Rectangle> rect;
};
