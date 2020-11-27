#include "GameState.h"
#include "Engine.h"
#include "Game.h"

GameState::GameState()
{
	m_player = std::make_shared<Player>();
	m_bg = std::make_shared<Background>();
	m_enemy = std::make_shared<Enemy>();
}

GameState::~GameState()
{
}

void GameState::update(Game* game, TimeStep time)
{
	m_player->update(time.deltaTime);
	m_bg->update(time.deltaTime);
	m_enemy->update(time.deltaTime);
}

void GameState::draw()
{
	m_bg->draw();
	m_player->draw();
	m_enemy->draw();
}
