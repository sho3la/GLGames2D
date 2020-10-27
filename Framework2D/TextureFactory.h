#pragma once
#include <glm\glm.hpp>

class TextureFactory
{
public:
	static unsigned int GetTexture2D(const char* filename, glm::vec2& size);
	static void DeleteTexture2D(unsigned int ID);
};