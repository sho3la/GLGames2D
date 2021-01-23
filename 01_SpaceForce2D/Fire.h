#pragma once
#include "Texture2D.h"
#include "Rectangle.h"

#include <memory>
#include <vector>


class Fire
{
public:
	Fire(Texture2D* sprite);

	~Fire();

	void update(float time, Rectangle& parent);

	void draw();

private:
	void animate(float time);

	Texture2D* sprite_tex;
	int current_frame;
	float frame_time;
	float time_counter;
	std::shared_ptr<Rectangle> m_rect;
	std::vector<Rectangle> m_frames;
};