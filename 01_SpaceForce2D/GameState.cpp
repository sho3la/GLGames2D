#include "GameState.h"
#include "Engine.h"
#include "Game.h"

GameState::GameState()
{
	spritesheet_tex = std::make_shared<Texture2D>("res/spritesheet.png");

	m_player = std::make_shared<Player>(spritesheet_tex.get());
	m_enemymanager = std::make_shared<EnemyManager>(spritesheet_tex.get());
	m_bg = std::make_shared<Background>();
}

GameState::~GameState()
{
}

void GameState::update(Game* game, TimeStep time)
{
	m_player->update(time.deltaTime);
	m_enemymanager->update(time.deltaTime);
	m_bg->update(time.deltaTime);
}

void GameState::draw()
{
	m_bg->draw();
	m_player->draw();
	m_enemymanager->draw();
}
