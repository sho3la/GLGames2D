#include "SpriteRenderer.h"
#include "Camera2D.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <glad\gl.h>
#include <vector>

SpriteRenderer::SpriteRenderer(int width, int height)
{
	const char* vs = R"CODE(
			#version 330 core
			layout(location = 0) in vec2 point;
			layout(location = 2) in vec2 uv;

			uniform mat4 projection;
			uniform mat4 model_matrx;

			out vec2 vertex_uv;

			void main()
			{
				gl_Position = projection * model_matrx * vec4(point.x, point.y, 0.0, 1.0);
				vertex_uv = uv;
			};
)CODE";

	const char* fs = R"CODE(
			#version 330 core
			out vec4 finalcolor;

			in vec2 vertex_uv;

			uniform sampler2D sprite;
			uniform vec4 hasTexture;
			uniform vec4 vertex_color;
			uniform vec2 tile_offset;
			
			void main()
			{
					if(hasTexture.x == 1)
						finalcolor = vertex_color * texture(sprite,vertex_uv + tile_offset);
					else
						finalcolor = vertex_color;
			};
)CODE";


	shaderptr = std::make_shared<ShaderProgram>();
	shaderptr->Compile(vs,fs);

	m_width = width;
	m_height = height;
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Draw(Texture2D * texture, Rectangle & rect)
{
	shaderptr->use();

	auto camera = Camera2D::getInstance();
	glm::mat4 proj = camera.Projection(m_width, m_height);

	shaderptr->Send_Mat4("projection", proj);

	glm::mat4 model_mat = glm::mat4(1.0f);
	model_mat = glm::translate(glm::mat4(1.0f) , glm::vec3(rect.m_position, 0.0f)) * 
		glm::rotate(glm::mat4(1.0f), rect.rotation , glm::vec3(0,0,1)) * 
		glm::scale(glm::mat4(1.0f), glm::vec3(rect.m_size,1));

	shaderptr->Send_Mat4("model_matrx", model_mat);
	shaderptr->Send_vec4("vertex_color", glm::vec4(1.0f));

	glBindVertexArray(rect.buffers.VAO);

	if (texture)
	{
		glBindTexture(GL_TEXTURE_2D, texture->ID);
		shaderptr->Send_vec4("hasTexture", glm::vec4(1.0f));
	}
	else
	{
		shaderptr->Send_vec4("hasTexture", glm::vec4(0.0f));
	}

	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void SpriteRenderer::Draw(Texture2D * texture, Rectangle & rect, glm::vec4 color)
{
	shaderptr->use();

	auto camera = Camera2D::getInstance();
	glm::mat4 proj = camera.Projection(m_width, m_height);

	shaderptr->Send_Mat4("projection", proj);

	glm::mat4 model_mat = glm::mat4(1.0f);
	model_mat = glm::translate(glm::mat4(1.0f), glm::vec3(rect.m_position, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), rect.rotation, glm::vec3(0, 0, 1)) *
		glm::scale(glm::mat4(1.0f), glm::vec3(rect.m_size, 1));

	shaderptr->Send_Mat4("model_matrx", model_mat);
	shaderptr->Send_vec4("vertex_color", color);

	glBindVertexArray(rect.buffers.VAO);

	if (texture)
	{
		glBindTexture(GL_TEXTURE_2D, texture->ID);
		shaderptr->Send_vec4("hasTexture", glm::vec4(1.0f));
		shaderptr->Send_vec2("tile_offset", glm::vec2(0.0f));
	}
	else
	{
		shaderptr->Send_vec4("hasTexture", glm::vec4(0.0f));
	}

	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void SpriteRenderer::Draw(Texture2D * texture, Rectangle & rect, float uv_x, float uv_y, glm::vec4 color)
{
	shaderptr->use();

	auto camera = Camera2D::getInstance();
	glm::mat4 proj = camera.Projection(m_width, m_height);

	shaderptr->Send_Mat4("projection", proj);

	glm::mat4 model_mat = glm::mat4(1.0f);
	model_mat = glm::translate(glm::mat4(1.0f), glm::vec3(rect.m_position, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), rect.rotation, glm::vec3(0, 0, 1)) *
		glm::scale(glm::mat4(1.0f), glm::vec3(rect.m_size, 1));

	shaderptr->Send_Mat4("model_matrx", model_mat);
	shaderptr->Send_vec4("vertex_color", color);

	glBindVertexArray(rect.buffers.VAO);

	if (texture)
	{
		glBindTexture(GL_TEXTURE_2D, texture->ID);
		shaderptr->Send_vec4("hasTexture", glm::vec4(1.0f));
		shaderptr->Send_vec2("tile_offset", glm::vec2(uv_x, uv_y));
	}
	else
	{
		shaderptr->Send_vec4("hasTexture", glm::vec4(0.0f));
	}

	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void SpriteRenderer::Draw(Texture2D * texture, Rectangle & rect, Rectangle & uv_rect, glm::vec4 color)
{
	shaderptr->use();

	auto camera = Camera2D::getInstance();
	glm::mat4 proj = camera.Projection(m_width, m_height);

	shaderptr->Send_Mat4("projection", proj);

	glm::mat4 model_mat = glm::mat4(1.0f);
	model_mat = glm::translate(glm::mat4(1.0f), glm::vec3(rect.m_position, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), rect.rotation, glm::vec3(0, 0, 1)) *
		glm::scale(glm::mat4(1.0f), glm::vec3(rect.m_size, 1));

	shaderptr->Send_Mat4("model_matrx", model_mat);
	shaderptr->Send_vec4("vertex_color", color);

	glBindVertexArray(rect.buffers.VAO);

	if (texture)
	{
		glBindTexture(GL_TEXTURE_2D, texture->ID);
		shaderptr->Send_vec4("hasTexture", glm::vec4(1.0f));
		shaderptr->Send_vec2("tile_offset", glm::vec2(0.0f));

		// update uv buffer

		std::vector<glm::vec2> uv;

		uv = {
			glm::vec2(uv_rect.m_position.x / texture->size.x,uv_rect.m_position.y / texture->size.y),
			glm::vec2(uv_rect.m_position.x / texture->size.x,(uv_rect.m_position.y + uv_rect.m_size.y) / texture->size.y),
			glm::vec2((uv_rect.m_position.x + uv_rect.m_size.x) / texture->size.x,uv_rect.m_position.y / texture->size.y),

			glm::vec2((uv_rect.m_position.x + uv_rect.m_size.x) / texture->size.x,uv_rect.m_position.y / texture->size.y),
			glm::vec2(uv_rect.m_position.x / texture->size.x,(uv_rect.m_position.y + uv_rect.m_size.y) / texture->size.y),
			glm::vec2((uv_rect.m_position.x + uv_rect.m_size.x) / texture->size.x,(uv_rect.m_position.y + uv_rect.m_size.y) / texture->size.y)
		};


		glBindVertexArray(rect.buffers.VAO);
		glBindBuffer(GL_ARRAY_BUFFER, rect.buffers.UVBO);
		void* gpubuffer = nullptr;
		gpubuffer = glMapBufferRange(GL_ARRAY_BUFFER, 0, 6 * sizeof(glm::vec2), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
		memcpy(gpubuffer, uv.data(), 6 * sizeof(glm::vec2));
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	else
	{
		shaderptr->Send_vec4("hasTexture", glm::vec4(0.0f));
	}

	glDrawArrays(GL_TRIANGLES, 0, 6);
}
