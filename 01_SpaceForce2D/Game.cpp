#include "Game.h"
#include "Keyboard.h"
#include "Engine.h"

Game::Game()
{

}

Game::~Game()
{
}

void Game::loadResources()
{
	tex = std::make_shared<Texture2D>("E:/_Vedios/workspace/ship.png");


	rect = std::make_shared<Rectangle>(glm::vec2(50,50), glm::vec2(100,100));
	rect->m_position += 100;

	rect2 = std::make_shared<Rectangle>(glm::vec2(350, 50), glm::vec2(100, 100));
}

void Game::init()
{
}

void Game::update(TimeStep time)
{
	if (Keyboard::getkey(Keyboard::SPACE) == Keyboard::State_Down)
	{
		printf("koko is down \n");
	}
	else
	{
		printf("koko is up \n");
	}


	printf("delta time = %f \n", time.deltaTime);
	printf("elapsed time = %f \n", time.elapsedTime);

	rect->rotation += 0.01f;

}

void Game::render()
{
	Engine::sp_renderer->Draw(nullptr, *rect);

	Engine::sp_renderer->Draw(tex.get(), *rect2, glm::vec4(1,1,1,1));
}
