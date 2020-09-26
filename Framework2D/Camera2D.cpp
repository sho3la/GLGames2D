#include "Camera2D.h"

Camera2D::Camera2D()
{
	
}

Camera2D::Camera2D(int width, int height)
{
	projection = glm::ortho(0, width, height, 0);
}

Camera2D::~Camera2D()
{
}

glm::mat4 Camera2D::Projection()
{
	return projection;
}
