#include "Enemy.h"
#include "Engine.h"

Enemy::Enemy(Texture2D* sprite) :
	movement_speed(700.0f)
{
	sprite_tex = sprite;

	// enemy rectangle : 0,0,145,186
	// enemy rectangle flipped : 328,151,145,186
	ship_rect = std::make_shared<Rectangle>(glm::vec2(100, 100), glm::vec2(145, 186) / 2.5f);
	ship_rect->rotation = 180.0f;

	ship_gun = std::make_shared<Gun>(sprite_tex, glm::vec2(0, 1));
	ship_fire = std::make_shared<EngineFire>(sprite_tex);
}

Enemy::~Enemy()
{
}

void Enemy::update(float time)
{
	ship_rect->rotation += time * 50;

	Rectangle realtive_rect;
	realtive_rect.m_position = ship_rect->Centre();
	realtive_rect.m_position += glm::vec2{ -4, (ship_rect->m_size.y / 4) };
	realtive_rect.rotation = ship_rect->rotation;
	realtive_rect.m_origin = ship_rect->m_origin;

	ship_fire->update(time, realtive_rect);
}

void Enemy::draw()
{
	Engine::sp_renderer->Draw(sprite_tex, *ship_rect, Rectangle(0, 0, 145, 186), glm::vec4(1));

	ship_gun->draw();
	ship_fire->draw();
}

void Enemy::move(float time)
{
}
