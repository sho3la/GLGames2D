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

	rect2 = std::make_shared<Rectangle>(glm::vec2(350, 50), glm::vec2(100, 100));

}

void Game::init()
{
	Engine::set_limit(10);
}

void Game::update(TimeStep time)
{
	if (Keyboard::getkey(Keyboard::SPACE) == Keyboard::State_Down)
	{
		tex.reset();
		rect2.reset();
	}
	else
	{
		printf("koko is up \n");
	}


	printf("delta time = %f \n", time.deltaTime);
	printf("elapsed time = %f \n", time.elapsedTime);
}

void Game::render()
{
	Engine::sp_renderer->Draw(tex.get(), *rect2, glm::vec4(1,1,1,1));
}
