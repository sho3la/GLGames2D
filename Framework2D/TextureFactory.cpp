#include "TextureFactory.h"
#include <glad/gl.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
using namespace std;

unsigned int TextureFactory::GetTexture2D(const char * filename, glm::vec2 & size)
{
	int width, height, numcomponents;
	unsigned char* data;
	unsigned int textureID;

	glGenTextures(1, &textureID);

	data = stbi_load(filename, &width, &height, &numcomponents, STBI_rgb_alpha);

	if (data)
	{
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// ********* texture minimize & maxmize operation
		// to solve pixlation problem
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_LINEAR_MIPMAP_NEAREST
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		size.x = (float)width;
		size.y = (float)height;
	}
	else
	{
		cout << "failed to load image : " << filename << endl;
		cout << "============================================" << endl;
		stbi_image_free(data);
		return -1;
	}

	stbi_image_free(data);

	return textureID;
}

void TextureFactory::DeleteTexture2D(unsigned int ID)
{
	glDeleteTextures(1, &ID);
}
