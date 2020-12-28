#include "Player.h"
#include "Engine.h"

Player::Player(Texture2D* sprite) :
	movement_speed(700.0f) ,
	current_frame(0),
	frame_time(0.2f),
	time_counter(0)
{
	sprite_tex = sprite;

	// player rectangle : 0,196,175,141
	ship_rect = std::make_shared<Rectangle>(glm::vec2(350, 750), glm::vec2(175, 141) / 2.5f);

	enginefire_rect = std::make_shared<Rectangle>(glm::vec2(0), glm::vec2(0));

	/*
	fireframe2 : 185,196,21,72
	fireframe1 : 185,278,21,56
	*/
	Rectangle frame1;
	frame1.m_position = glm::vec2(185, 278);
	frame1.m_size = glm::vec2(21, 56);

	Rectangle frame2;
	frame2.m_position = glm::vec2(185, 196);
	frame2.m_size = glm::vec2(21, 72);

	enginefire_frames.push_back(frame1);
	enginefire_frames.push_back(frame2);

	ship_gun = std::make_shared<Gun>(sprite_tex, glm::vec2(0,1));
}

Player::~Player()
{
}

void Player::update(float time)
{
	animate(time);
	move(time);

	if (Keyboard::getkey(Keyboard::SPACE) == Keyboard::State_Down)
	{
		ship_gun->shot(ship_rect->Centre());
	}
	ship_gun->update(time);
}

void Player::draw()
{
	Engine::sp_renderer->Draw(sprite_tex, *ship_rect, Rectangle(0, 196, 175, 141), glm::vec4(1));
	Engine::sp_renderer->Draw(sprite_tex, *enginefire_rect, enginefire_frames[current_frame], glm::vec4(1));
	ship_gun->draw();
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

	glm::vec2 enginefire_pos = ship_rect->Centre();
	enginefire_pos.x -= 4;
	enginefire_pos.y += (ship_rect->m_size.y / 2) - 5;
	enginefire_rect->m_position = enginefire_pos;
}

void Player::animate(float time)
{
	time_counter += time;

	if (time_counter > frame_time)
	{
		current_frame = (current_frame + 1) % (enginefire_frames.size());
		enginefire_rect->m_size = enginefire_frames[current_frame].m_size / 2.0f;
		time_counter = 0;
	}
}
