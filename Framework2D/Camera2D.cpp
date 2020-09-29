#include "Camera2D.h"

Camera2D* Camera2D::m_instance = nullptr;

Camera2D* Camera2D::getInstance()
{
	if (!m_instance) m_instance = new Camera2D();

	return m_instance;
}

Camera2D::Camera2D()
{
	
}

Camera2D::~Camera2D()
{
	delete m_instance;
}


glm::mat4 Camera2D::Projection(int width, int height)
{
	projection = glm::ortho(0.0f,(float)width, (float) height , 0.0f);
	return projection;
}
