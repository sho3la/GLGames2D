#pragma once
#include "State.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Explosion.h"

class GameState : public State
{
public:
	GameState();

	~GameState();

	void update(Game* game, TimeStep time) override;

	void draw() override;

	std::shared_ptr<Enemy> m_enemy;
	std::shared_ptr<Player> m_player;
	std::shared_ptr<Background> m_bg;

	std::shared_ptr<Texture2D> spritesheet_tex;
};
