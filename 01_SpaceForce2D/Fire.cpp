#include "Fire.h"
#include "Engine.h"

Fire::Fire(Texture2D* sprite) :
	current_frame(0),
	frame_time(0.2f),
	time_counter(0)
{
	sprite_tex = sprite;

	m_rect = std::make_shared<Rectangle>(glm::vec2(0), glm::vec2(0));

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

	m_frames.push_back(frame1);
	m_frames.push_back(frame2);
}

Fire::~Fire()
{
}

void Fire::update(float time, Rectangle& parent)
{
	// update fire transform related to parent
	m_rect->m_position = parent.m_position;
	m_rect->m_origin = parent.m_origin;
	m_rect->rotation = parent.rotation;

	animate(time);
}

void Fire::draw()
{
	Engine::sp_renderer->Draw(sprite_tex, *m_rect, m_frames[current_frame], glm::vec4(1));
}

void Fire::animate(float time)
{
	time_counter += time;

	if (time_counter > frame_time)
	{
		current_frame = (current_frame + 1) % (m_frames.size());
		m_rect->m_size = m_frames[current_frame].m_size / 2.0f;
		time_counter = 0;
	}
}
