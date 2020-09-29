#pragma once
#include <glm/glm.hpp>

class ShaderProgram
{
public:
	ShaderProgram();

	~ShaderProgram();

	void Compile(const char* vertex_shader, const char* fragment_shader);

	void Send_Mat4(const char* name, glm::mat4& mat);
	void Send_vec2(const char* name, glm::vec2& val);
	void Send_vec3(const char* name, glm::vec3& val);
	void Send_vec4(const char* name, glm::vec4& val);
	void Send_float(const char* name, float val);

	void use();

private:
	void shutdown();

	unsigned int programID;
};