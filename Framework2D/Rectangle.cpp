#include "Rectangle.h"

Rectangle::Rectangle() : 
	m_position(glm::vec2(0)),
	m_size(glm::vec2(0))
{
}

Rectangle::Rectangle(float x, float y, float width, float height)
{
	m_position.x = x;
	m_position.y = y;
	m_size.x = width;
	m_size.y = height;

	buffers = GeomtreyFactory::GetRect();
}

Rectangle::Rectangle(glm::vec2 position, glm::vec2 size)
{
	m_position = position;
	m_size = size;

	buffers = GeomtreyFactory::GetRect();
}

Rectangle::~Rectangle()
{
}

glm::vec2 Rectangle::Centre()
{
	return glm::vec2();
}

bool Rectangle::Contain(glm::vec2 point)
{
	return false;
}

bool Rectangle::AABB_Intersection(Rectangle & other)
{
	return false;
}

bool Rectangle::CircleCircle_Intersection(Rectangle & other)
{
	return false;
}
