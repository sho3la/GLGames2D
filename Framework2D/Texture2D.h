#pragma once 
#include <glm\glm.hpp>

class Texture2D
{
public:
	Texture2D(const char* filename);
	~Texture2D();

	glm::vec2 size;
	unsigned int ID;
};