#include "Game.h"
#include "Keyboard.h"

Game::Game()
{

}

Game::~Game()
{
}

void Game::loadResources()
{
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

}

void Game::render()
{

}
