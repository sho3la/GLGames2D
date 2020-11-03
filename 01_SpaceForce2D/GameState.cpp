#include "GameState.h"
#include "Engine.h"
#include "Game.h"

GameState::GameState()
{
	m_player = std::make_shared<Player>();
}

GameState::~GameState()
{
}

void GameState::update(Game* game, TimeStep time)
{
	m_player->update(time.deltaTime);
}

void GameState::draw()
{
	m_player->draw();
}
