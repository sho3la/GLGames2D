#include "Enemy.h"
#include "Engine.h"

Enemy::Enemy(Texture2D* sprite, glm::vec2 position) :
	movement_speed(700.0f)
{

	sprite_tex = sprite;

	// enemy rectangle : 0,0,145,186
	// enemy rectangle flipped : 328,151,145,186
	ship_rect = std::make_shared<Rectangle>(position, glm::vec2(145, 186) / 2.5f);
	ship_rect->rotation = 180.0f;

	ship_gun = std::make_shared<Gun>(sprite_tex, glm::vec2(0, 1));

	ship_fire = std::make_shared<Fire>(sprite_tex);
}

Enemy::~Enemy()
{
}

void Enemy::update(float time)
{
	Rectangle relative_transform;
	relative_transform.m_position = ship_rect->Centre();
	relative_transform.m_position += glm::vec2{ -4 , (ship_rect->m_size.y / 4) };
	relative_transform.m_origin = ship_rect->m_origin;
	relative_transform.rotation = ship_rect->rotation;
	ship_fire->update(time, relative_transform);
}

void Enemy::draw()
{
	Engine::sp_renderer->Draw(sprite_tex, *ship_rect, Rectangle(0, 0, 145, 186), glm::vec4(1));
	ship_fire->draw();
	ship_gun->draw();
}

void Enemy::move_on_yaxis(float time, float direction, float end_y)
{
	if (ship_rect->m_position.y <= end_y * -direction)
		return;

	ship_rect->m_position.y += (time * movement_speed) * -direction;
}