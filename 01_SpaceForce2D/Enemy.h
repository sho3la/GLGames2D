#pragma once
#include "Texture2D.h"
#include "Rectangle.h"
#include "Gun.h"
#include "Fire.h"

#include <memory>
#include <vector>

class Enemy
{
public:
	Enemy(Texture2D* sprite);

	~Enemy();

	void update(float time);

	void draw();

private:
	void move(float time);

	float movement_speed;
	Texture2D* sprite_tex;
	std::shared_ptr<Gun> ship_gun;
	std::shared_ptr<Fire> ship_fire;
	std::shared_ptr<Rectangle> ship_rect;
};