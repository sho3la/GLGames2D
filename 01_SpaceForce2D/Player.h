#pragma once
#include "Texture2D.h"
#include "Rectangle.h"

#include <memory>

class Player
{
public:
	Player();

	~Player();


	void update(float time);

	void draw();

	void move(float time);

	std::shared_ptr<Texture2D> ship_texture;
	std::shared_ptr<Rectangle> ship_rect;
};