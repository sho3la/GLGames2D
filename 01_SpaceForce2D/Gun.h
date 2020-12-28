#pragma once
#include "Texture2D.h"
#include "Rectangle.h"

#include <memory>
#include <vector>

class Gun
{
public:
	Gun(Texture2D* sprite, glm::vec2 fire_direction);

	~Gun();

	void shot(glm::vec2 position);

	void update(float time);

	void draw();

	Texture2D* m_bullet_tex;
	std::vector<std::shared_ptr<Rectangle>> m_bullet_rects;
	float bullet_speed;
	glm::vec2 m_fire_direction;
	float gunspeed;
	float counter;
};