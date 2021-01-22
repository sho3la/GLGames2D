#include "GameState.h"
#include "Engine.h"
#include "Game.h"

GameState::GameState()
{
	spritesheet_tex = std::make_shared<Texture2D>("res/spritesheet.png");

	m_player = std::make_shared<Player>(spritesheet_tex.get());
	m_enemy = std::make_shared<Enemy>(spritesheet_tex.get());
	m_bg = std::make_shared<Background>();
}

GameState::~GameState()
{
}

void GameState::update(Game* game, TimeStep time)
{
	m_player->update(time.deltaTime);
	m_enemy->update(time.deltaTime);
	m_bg->update(time.deltaTime);
}

void GameState::draw()
{
	m_bg->draw();
	m_player->draw();
	m_enemy->draw();
}
