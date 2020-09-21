#include "Texture2D.h"
#include "TextureFactory.h"

Texture2D::Texture2D(const char * filename)
{
	ID = TextureFactory::GetTexture2D(filename, size);
}

Texture2D::~Texture2D()
{
}
