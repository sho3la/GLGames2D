#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <memory>

class Camera2D
{
public:
	Camera2D();

	Camera2D(int width, int height);

	~Camera2D();

	glm::mat4 Projection();

private:
	glm::mat4 projection;
};

typedef std::shared_ptr<Camera2D> Camera2DPtr;