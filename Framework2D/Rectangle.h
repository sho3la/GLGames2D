#pragma once
#include <glm\glm.hpp>
#include "GeomtreyFactory.h"

class Rectangle
{
public:
	Rectangle();

	Rectangle(float x, float y, float width, float height);

	Rectangle(glm::vec2 position, glm::vec2 size);

	~Rectangle();

	bool operator == (Rectangle& other)
	{
		return ((m_position.x == other.m_position.x) &&
			(m_position.y == other.m_position.y) &&
			(m_size.x == other.m_size.x) && (m_size.y == other.m_size.y));
	}

	bool operator != (Rectangle& other)
	{
		return !((m_position.x == other.m_position.x) &&
			(m_position.y == other.m_position.y) &&
			(m_size.x == other.m_size.x) && (m_size.y == other.m_size.y));
	}

	glm::vec2 Centre();

	bool Contain(glm::vec2 point);

	bool AABB_Intersection(Rectangle& other);

	bool CircleCircle_Intersection(Rectangle& other);


	glm::vec2 m_position;
	glm::vec2 m_size;
	GBuffer buffers;
};