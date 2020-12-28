#include "Gun.h"
#include "Engine.h"

Gun::Gun(Texture2D * sprite, glm::vec2 fire_direction)
{
	// bluebullet rectangle: 155,109,69,68
	m_bullet_tex = sprite;
	counter = 0;
	gunspeed = 7.0f;
	bullet_speed = 700.0f;
	m_fire_direction = fire_direction;
}

Gun::~Gun()
{
}

void Gun::shot(glm::vec2 position)
{
	if (counter > (1/gunspeed))
	{
		position.y -= 10;
		position.x -= 7;
		auto rect = std::make_shared<Rectangle>(position, glm::vec2(69, 68) / 5.0f);
		m_bullet_rects.push_back(rect);
		counter = 0;
	}
}

void Gun::update(float time)
{
	counter += time;
	for (int i = 0 ; i < m_bullet_rects.size(); ++i)
	{
		m_bullet_rects[i]->m_position -= (time * bullet_speed * m_fire_direction);

		if (m_bullet_rects[i]->m_position.y < 0)
		{
			m_bullet_rects.erase(m_bullet_rects.begin() + i);
		}
	}
}

void Gun::draw()
{
	for (auto rect : m_bullet_rects)
		Engine::sp_renderer->Draw(m_bullet_tex, *rect, Rectangle(155, 109, 69, 68), glm::vec4(1));
}

