#pragma once
#include "Texture2D.h"
#include "Rectangle.h"
#include "Gun.h"

#include <memory>
#include <vector>

class Player
{
public:
	Player(Texture2D* sprite);

	~Player();


	void update(float time);

	void draw();

	void move(float time);

	void animate(float time);

	Texture2D* sprite_tex;

	std::shared_ptr<Rectangle> ship_rect;
	std::shared_ptr<Rectangle> enginefire_rect;
	std::vector<Rectangle> enginefire_frames;

	std::shared_ptr<Gun> ship_gun;

	int current_frame;
	float frame_time;
	float time_counter;
	float movement_speed;
};