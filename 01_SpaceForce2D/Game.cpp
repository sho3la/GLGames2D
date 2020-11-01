#include "Game.h"
#include "Keyboard.h"
#include "Engine.h"
#include "IntroState.h"

Game::Game()
{

}

Game::~Game()
{
	delete current_state;
}

void Game::loadResources()
{
	current_state = new IntroState();
}

void Game::init()
{
	Engine::set_limit(10);
}

void Game::update(TimeStep time)
{
	current_state->update(this, time);
}

void Game::render()
{
	current_state->draw();
}
