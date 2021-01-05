#pragma once
#include "Texture2D.h"
#include "Rectangle.h"

#include <memory>
#include <vector>

class Explosion
{

public:
	Explosion(Texture2D* sprite);
	
	~Explosion();

	void update(float time);

	void draw();

	void explode(glm::vec2 position);

private:
	void animate(float time);


	Texture2D* m_texture;
	std::shared_ptr<Rectangle> m_rectangle;
	std::vector<Rectangle> m_frames;

	int current_frame;
	float frame_time;
	float counter;
};