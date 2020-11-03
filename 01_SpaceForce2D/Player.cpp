#include "Player.h"
#include "Engine.h"

Player::Player()
{
	ship_texture = std::make_shared<Texture2D>("res/ship.png");
	ship_rect = std::make_shared<Rectangle>(glm::vec2(100, 100), glm::vec2(100, 100));
}

Player::~Player()
{
}

void Player::update(float time)
{
	move(time);
}

void Player::draw()
{
	Engine::sp_renderer->Draw(ship_texture.get(), *ship_rect, glm::vec4(1));
}

void Player::move(float time)
{
	if(Keyboard::getkey(Keyboard::ARROW_LEFT) == Keyboard::State_Down)
	{
		ship_rect->m_position.x -= time * 1000;
	}
	if (Keyboard::getkey(Keyboard::ARROW_RIGHT) == Keyboard::State_Down)
	{
		ship_rect->m_position.x += time * 1000;
	}
	if (Keyboard::getkey(Keyboard::ARROW_UP) == Keyboard::State_Down)
	{
		ship_rect->m_position.y -= time * 1000;
	}
	if (Keyboard::getkey(Keyboard::ARROW_DOWN) == Keyboard::State_Down)
	{
		ship_rect->m_position.y += time * 1000;
	}

	printf("ship_rect->m_position.x = %f \n", ship_rect->m_position.x);
}
