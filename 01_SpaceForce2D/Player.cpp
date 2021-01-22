#include "Player.h"
#include "Engine.h"

Player::Player(Texture2D* sprite) :
	movement_speed(700.0f)
{
	sprite_tex = sprite;

	// player rectangle : 0,196,175,141
	ship_rect = std::make_shared<Rectangle>(glm::vec2(350, 750), glm::vec2(175, 141) / 2.5f);

	ship_gun = std::make_shared<Gun>(sprite_tex, glm::vec2(0,1));
	ship_fire = std::make_shared<EngineFire>(sprite_tex);
}

Player::~Player()
{
}

void Player::update(float time)
{
	move(time);

	if (Keyboard::getkey(Keyboard::SPACE) == Keyboard::State_Down)
	{
		ship_rect->rotation += time * 50;
	}

	//if (Keyboard::getkey(Keyboard::SPACE) == Keyboard::State_Down)
	//{
	//	ship_gun->shot(ship_rect->Centre());
	//}

	ship_gun->update(time);

	Rectangle realtive_rect;
	realtive_rect.m_position = ship_rect->Centre();
	realtive_rect.m_position += glm::vec2{ -4, (ship_rect->m_size.y / 2) };
	realtive_rect.rotation = ship_rect->rotation;
	realtive_rect.m_origin = ship_rect->m_origin;

	ship_fire->update(time, realtive_rect);
}

void Player::draw()
{
	Engine::sp_renderer->Draw(sprite_tex, *ship_rect, Rectangle(0, 196, 175, 141), glm::vec4(1));

	ship_gun->draw();
	ship_fire->draw();
}

void Player::move(float time)
{
	if(Keyboard::getkey(Keyboard::ARROW_LEFT) == Keyboard::State_Down)
	{
		ship_rect->m_position.x -= time * movement_speed;
	}
	if (Keyboard::getkey(Keyboard::ARROW_RIGHT) == Keyboard::State_Down)
	{
		ship_rect->m_position.x += time * movement_speed;
	}
	if (Keyboard::getkey(Keyboard::ARROW_UP) == Keyboard::State_Down)
	{
		ship_rect->m_position.y -= time * movement_speed;
	}
	if (Keyboard::getkey(Keyboard::ARROW_DOWN) == Keyboard::State_Down)
	{
		ship_rect->m_position.y += time * movement_speed;
	}
}

void Player::rotate(float angle)
{

}