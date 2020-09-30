#include "Camera2D.h"

Camera2D Camera2D::getInstance()
{
	static Camera2D m_instance;

	return m_instance;
}

Camera2D::Camera2D()
{
	
}

Camera2D::~Camera2D()
{
}


glm::mat4 Camera2D::Projection(int width, int height)
{
	return glm::ortho(0.0f, (float)width, (float)height, 0.0f);
}
