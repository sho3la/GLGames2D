#include "EngineFire.h"
#include "Engine.h"

EngineFire::EngineFire(Texture2D* sprite) :
	current_frame(0),
	frame_time(0.2f),
	time_counter(0)
{
	sprite_tex = sprite;

	enginefire_rect = std::make_shared<Rectangle>(glm::vec2(0), glm::vec2(0));

	/*
		fireframe2 : 185,196,21,72
		fireframe1 : 185,278,21,56
	*/
	Rectangle frame1;
	frame1.m_position = glm::vec2(185, 278);
	frame1.m_size = glm::vec2(21, 56);

	Rectangle frame2;
	frame2.m_position = glm::vec2(185, 196);
	frame2.m_size = glm::vec2(21, 72);

	enginefire_frames.push_back(frame1);
	enginefire_frames.push_back(frame2);
}

EngineFire::~EngineFire()
{
}

void EngineFire::update(float time, Rectangle* parent)
{
	// update position related to the parent
	glm::vec2 enginefire_pos = parent->Centre();
	enginefire_pos.x -= 4;
	enginefire_pos.y += (parent->m_size.y / 2) - 5;
	enginefire_rect->m_position = enginefire_pos;

	// update rotation related to the parent
	enginefire_rect->m_origin = parent->m_origin;
	enginefire_rect->rotation = parent->rotation;

	animate(time);
}

void EngineFire::draw()
{
	Engine::sp_renderer->Draw(sprite_tex, *enginefire_rect, enginefire_frames[current_frame], glm::vec4(1));
}

void EngineFire::animate(float time)
{
	time_counter += time;

	if (time_counter > frame_time)
	{
		current_frame = (current_frame + 1) % (enginefire_frames.size());
		enginefire_rect->m_size = enginefire_frames[current_frame].m_size / 2.0f;
		time_counter = 0;
	}
}
