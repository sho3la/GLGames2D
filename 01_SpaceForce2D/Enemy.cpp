#include "Enemy.h"
#include "Engine.h"

Enemy::Enemy() : movement_speed(700.0f), current_frame(0), frame_time(0.2f), time_counter(0)
{
	ship_texture = std::make_shared<Texture2D>("res/enemy.png");
	ship_rect = std::make_shared<Rectangle>(glm::vec2(100, 100), ship_texture->size / 2.5f);

	enginefire_texture = std::make_shared<Texture2D>("res/enginefire_animation.png");
	enginefire_rect = std::make_shared<Rectangle>(glm::vec2(0), glm::vec2(0));

	Rectangle frame1;
	frame1.m_position = glm::vec2(15, 10);
	frame1.m_size = glm::vec2(25, 60);

	Rectangle frame2;
	frame2.m_position = glm::vec2(80, 5);
	frame2.m_size = glm::vec2(22, 75);

	enginefire_frames.push_back(frame1);
	enginefire_frames.push_back(frame2);

	bullet_texture = std::make_shared<Texture2D>("res/ship_bullet.png");
	ship_gun = std::make_shared<Gun>(bullet_texture.get(), glm::vec2(0, 1));
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
	Engine::sp_renderer->Draw(ship_texture.get(), *ship_rect, glm::vec2(-1), glm::vec4(1));
	Engine::sp_renderer->Draw(enginefire_texture.get(), *enginefire_rect, enginefire_frames[current_frame], glm::vec2(-1), glm::vec4(1));
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
