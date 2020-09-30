#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <memory>

class Camera2D
{
public:
	~Camera2D();

	static Camera2D getInstance();

	glm::mat4 Projection(int width, int height);
private:
	Camera2D();
};