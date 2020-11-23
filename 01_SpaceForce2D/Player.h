#pragma once
#include "Texture2D.h"
#include "Rectangle.h"
#include "Gun.h"

#include <memory>
#include <vector>

class Player
{
public:
	Player();

	~Player();


	void update(float time);

	void draw();

	void move(float time);

	void animate(float time);

	std::shared_ptr<Texture2D> ship_texture;
	std::shared_ptr<Rectangle> ship_rect;

	std::shared_ptr<Texture2D> enginefire_texture;
	std::shared_ptr<Rectangle> enginefire_rect;
	std::vector<Rectangle> enginefire_frames;

	std::shared_ptr<Gun> ship_gun;
	std::shared_ptr<Texture2D> bullet_texture;

	int current_frame;
	float frame_time;
	float time_counter;
	float movement_speed;
};