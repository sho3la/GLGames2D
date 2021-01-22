#include "Rectangle.h"

Rectangle::Rectangle() : 
	m_position(glm::vec2(0)),
	m_size(glm::vec2(0)),
	rotation(0),
	m_origin(glm::vec2(0))
{
	int x = 0;
}

Rectangle::Rectangle(float x, float y, float width, float height)
{
	m_position.x = x;
	m_position.y = y;
	m_size.x = width;
	m_size.y = height;
	rotation = 0;
	m_origin = Centre();

	buffers = GeomtreyFactory::GetRect();
}

Rectangle::Rectangle(glm::vec2 position, glm::vec2 size)
{
	m_position = position;
	m_size = size;
	rotation = 0;
	m_origin = Centre();

	buffers = GeomtreyFactory::GetRect();
}

Rectangle::~Rectangle()
{
	GeomtreyFactory::DeleteRect(buffers);
}

glm::vec2 Rectangle::Centre()
{
	return glm::vec2(m_position.x + (m_size.x / 2), m_position.y + (m_size.y / 2));
}

bool Rectangle::Contain(glm::vec2 point)
{
	return ((((m_position.x >= point.x) && (point.x < (m_position.x + m_size.x))) &&
		(m_position.y >= point.y)) && (point.y < (m_position.y + m_size.y)));
}

bool Rectangle::AABB_Intersection(Rectangle & other)
{
	return (other.m_position.x < (m_position.x + m_size.x) &&
		m_position.x < (other.m_position.x + other.m_size.x) &&
		other.m_position.y < (m_position.y + m_size.y) &&
		m_position.y < (other.m_position.y + other.m_size.y));
}

bool Rectangle::CircleCircle_Intersection(Rectangle & other)
{
	auto c1 = Centre();
	auto c2 = other.Centre();

	auto dest = glm::distance(c1, c2);

	if (dest < 50) return true;

	return false;
}
