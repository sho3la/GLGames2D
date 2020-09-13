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

void Game::update()
{
	if (Keyboard::getkey(Keyboard::SPACE) == Keyboard::State_Down)
	{
		printf("koko is down \n");
	}
	else
	{
		printf("koko is up \n");
	}
}

void Game::render()
{

}
