#pragma once
#include "Texture2D.h"
#include "Rectangle.h"
#include "ShaderProgram.h"

#include <glm\glm.hpp>
#include <memory>

class SpriteRenderer
{
public:
	SpriteRenderer(int width, int height);

	~SpriteRenderer();

	void Draw(Texture2D *texture, Rectangle& rect);
	void Draw(Texture2D *texture, Rectangle& rect, glm::vec4 color);
	void Draw(Texture2D *texture, Rectangle& rect, glm::vec2 flip, glm::vec4 color);
	void Draw(Texture2D *texture, Rectangle& rect, float uv_x, float uv_y, glm::vec4 color);
	void Draw(Texture2D *texture, Rectangle& rect, Rectangle& uv_rect, glm::vec2 flip, glm::vec4 color);
	void Draw(Texture2D *texture, Rectangle& rect, Rectangle& uv_rect, glm::vec4 color);

private:
	int m_width , m_height;
	std::shared_ptr<ShaderProgram> shaderptr;
};

typedef std::shared_ptr<SpriteRenderer> SpriteRendererPtr;