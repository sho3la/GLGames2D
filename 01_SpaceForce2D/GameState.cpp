#include "GameState.h"
#include "Engine.h"
#include "Game.h"

GameState::GameState()
{
	tex2 = std::make_shared<Texture2D>("E:\\_Vedios\\workspace\\ship.png");
	rect = std::make_shared<Rectangle>(glm::vec2(100, 100), glm::vec2(100, 100));
}

GameState::~GameState()
{
}

void GameState::update(Game* game, TimeStep time)
{

}

void GameState::draw()
{
	Engine::sp_renderer->Draw(tex2.get(), *rect, glm::vec4(1));
}
