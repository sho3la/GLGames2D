#include "GameState.h"
#include "Engine.h"
#include "Game.h"

GameState::GameState()
{
	spritesheet_tex = std::make_shared<Texture2D>("res/spritesheet.png");
	explosion_tex = std::make_shared<Texture2D>("res/explosion.png");

	m_player = std::make_shared<Player>(spritesheet_tex.get());
	m_bg = std::make_shared<Background>();
	m_enemy = std::make_shared<Enemy>(spritesheet_tex.get());

	exp = std::make_shared<Explosion>(explosion_tex.get());
	exp->explode(glm::vec2(250,250));
}

GameState::~GameState()
{
}

void GameState::update(Game* game, TimeStep time)
{
	m_player->update(time.deltaTime);
	m_bg->update(time.deltaTime);
	m_enemy->update(time.deltaTime);

	exp->update(time.deltaTime);
}

void GameState::draw()
{
	m_bg->draw();
	m_player->draw();
	m_enemy->draw();
	exp->draw();
}
