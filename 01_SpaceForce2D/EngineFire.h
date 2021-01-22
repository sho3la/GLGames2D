#pragma once
#include "Texture2D.h"
#include "Rectangle.h"

#include <memory>
#include <vector>

class EngineFire
{
public:
	EngineFire(Texture2D* sprite);
	
	~EngineFire();

	void update(float time, Rectangle& parent);

	void draw();
private:
	void animate(float time);

	int current_frame;
	float frame_time;
	float time_counter;
	Texture2D* sprite_tex;
	std::shared_ptr<Rectangle> enginefire_rect;
	std::vector<Rectangle> enginefire_frames;
};