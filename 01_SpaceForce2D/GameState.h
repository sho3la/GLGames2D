#pragma once
#include "State.h"
#include "Player.h"
#include "Background.h"

class GameState : public State
{
public:
	GameState();

	~GameState();

	void update(Game* game, TimeStep time) override;

	void draw() override;

	std::shared_ptr<Player> m_player;
	std::shared_ptr<Background> m_bg;
};
