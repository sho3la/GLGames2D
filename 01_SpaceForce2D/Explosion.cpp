#include "Explosion.h"
#include "Engine.h"

Explosion::Explosion(Texture2D * sprite)
{
	frame_time = 0.5f;
	counter = 0;
	m_texture = sprite;

	// frame rect
	m_rectangle = std::make_shared<Rectangle>(glm::vec2(0), glm::vec2(100,100));


	// frames list [animation]
	Rectangle frame1;
	frame1.m_position = glm::vec2(1, 1);
	frame1.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame1);

	Rectangle frame2;
	frame2.m_position = glm::vec2(223, 1);
	frame2.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame2);

	Rectangle frame3;
	frame3.m_position = glm::vec2(1, 213);
	frame3.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame3);

	Rectangle frame4;
	frame4.m_position = glm::vec2(223, 213);
	frame4.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame4);

	Rectangle frame5;
	frame5.m_position = glm::vec2(1, 425);
	frame5.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame5);

	Rectangle frame6;
	frame6.m_position = glm::vec2(223, 425);
	frame6.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame6);

	Rectangle frame7;
	frame7.m_position = glm::vec2(445, 1);
	frame7.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame7);

	Rectangle frame8;
	frame8.m_position = glm::vec2(445, 213);
	frame8.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame8);

	Rectangle frame9;
	frame9.m_position = glm::vec2(445, 425);
	frame9.m_size = glm::vec2(220, 210);
	m_frames.push_back(frame9);

}

Explosion::~Explosion()
{
}

void Explosion::update(float time)
{
	animate(time);
}

void Explosion::draw()
{
	Engine::sp_renderer->Draw(m_texture, *m_rectangle, m_frames[current_frame], glm::vec4(1));
}

void Explosion::explode(glm::vec2 position)
{
	m_rectangle->m_position = position;
	current_frame = 0;
}

void Explosion::animate(float time)
{
	counter += time;

	if (counter >= frame_time)
	{
		current_frame = (current_frame + 1) % (m_frames.size());
		m_rectangle->m_size = m_frames[current_frame].m_size;
		counter = 0;
	}
}
