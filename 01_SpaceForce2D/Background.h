#pragma once
#include "Texture2D.h"
#include "Rectangle.h"

#include <memory>

class Background
{
public:
	Background();

	~Background();

	void update(float time);

	void draw();

private:
	std::shared_ptr<Texture2D> tex;
	std::shared_ptr<Rectangle> rect;

	float current_uv;
	float speed;
};