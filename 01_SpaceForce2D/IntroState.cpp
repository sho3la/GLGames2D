#include "IntroState.h"
#include "Engine.h"
#include "GameState.h"
#include "Game.h"

IntroState::IntroState()
{
	tex = std::make_shared<Texture2D>("res/intro_screen.jpg");
	rect = std::make_shared<Rectangle>(glm::vec2(0,0), glm::vec2(900,900));
}

IntroState::~IntroState()
{
}

void IntroState::update(Game* game, TimeStep time)
{
	if (Keyboard::getkey(Keyboard::Keys::ENTER) == Keyboard::KeyState::State_Down)
	{
		delete game->current_state;
		game->current_state = new GameState();
	}
}

void IntroState::draw()
{
	Engine::sp_renderer->Draw(tex.get(), *rect, glm::vec4(1));
}
