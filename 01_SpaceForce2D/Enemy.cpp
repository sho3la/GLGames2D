#include "Enemy.h"
#include "Engine.h"

Enemy::Enemy(Texture2D* sprite) : 
	movement_speed(700.0f),
	current_frame(0),
	frame_time(0.2f),
	time_counter(0)
{

	sprite_tex = sprite;

	// enemy rectangle : 0,0,145,186
	// enemy rectangle flipped : 328,151,145,186
	ship_rect = std::make_shared<Rectangle>(glm::vec2(100, 100), glm::vec2(145, 186) / 2.5f);

	enginefire_rect = std::make_shared<Rectangle>(glm::vec2(0), glm::vec2(0));

	/*
	fireframe2 : 185,196,21,72
	fireframe1 : 185,278,21,56
	*/

	/*
	fireframe2 fliped: 267,69,21,72
	fireframe1 fliped: 267,3,21,56

	*/
	Rectangle frame1;
	frame1.m_position = glm::vec2(267, 69);
	frame1.m_size = glm::vec2(21, 56);

	Rectangle frame2;
	frame2.m_position = glm::vec2(267, 3);
	frame2.m_size = glm::vec2(21, 72);

	enginefire_frames.push_back(frame1);
	enginefire_frames.push_back(frame2);

	ship_gun = std::make_shared<Gun>(sprite_tex, glm::vec2(0, 1));
}

Enemy::~Enemy()
{
}

void Enemy::update(float time)
{

	animate(time);

	glm::vec2 enginefire_pos = ship_rect->Centre();
	enginefire_pos.x -= 4;
	enginefire_pos.y -= (ship_rect->m_size.y / 2) + 5;
	enginefire_rect->m_position = enginefire_pos;
}

void Enemy::draw()
{
	Engine::sp_renderer->Draw(sprite_tex, *ship_rect, Rectangle(328, 151, 145, 186), glm::vec2(-1), glm::vec4(1));
	Engine::sp_renderer->Draw(sprite_tex, *enginefire_rect, enginefire_frames[current_frame], glm::vec2(-1), glm::vec4(1));
	ship_gun->draw();
}

void Enemy::move(float time)
{
}

void Enemy::animate(float time)
{
	time_counter += time;

	if (time_counter > frame_time)
	{
		current_frame = (current_frame + 1) % (enginefire_frames.size());
		enginefire_rect->m_size = enginefire_frames[current_frame].m_size / 2.0f;
		time_counter = 0;
	}
}
