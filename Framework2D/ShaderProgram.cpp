#include "ShaderProgram.h"
#include <glad/gl.h>
#include <string>
#include <iostream>
using namespace std;

void checkerorr(unsigned int shader_id, string type)
{
	int success;
	char infolog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader_id, 1024, NULL, infolog);
			cout << "ERORR type : " << type << endl;
			cout << "ERORR : " << infolog << endl;
			cout << "==================================" << endl;
		}
	}
	else
	{
		glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader_id, 1024, NULL, infolog);
			cout << "ERORR type : " << type << endl;
			cout << "ERORR : " << infolog << endl;
			cout << "==================================" << endl;
		}
	}
}

ShaderProgram::ShaderProgram()
{
}

ShaderProgram::~ShaderProgram()
{
	shutdown();
}

void ShaderProgram::Compile(const char * vertex_shader, const char * fragment_shader)
{
	unsigned int program;

	// compile shader ..
	unsigned int vertex, fragment;

	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertex_shader, NULL);
	glCompileShader(vertex);
	checkerorr(vertex, "VERTEX");

	// fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragment_shader, NULL);
	glCompileShader(fragment);
	checkerorr(vertex, "FRAGMENT");

	// shader program
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glLinkProgram(program);
	checkerorr(program, "PROGRAM");


	glDeleteShader(vertex);
	glDeleteShader(fragment);

	programID = program;
}

void ShaderProgram::Send_Mat4(const char * name, glm::mat4& mat)
{
	auto location = glGetUniformLocation(programID, name);
	glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::Send_vec2(const char * name, glm::vec2 & val)
{
	auto location = glGetUniformLocation(programID, name);
	glUniform2fv(location, 1, &val[0]);
}

void ShaderProgram::Send_vec3(const char * name, glm::vec3 & val)
{
	auto location = glGetUniformLocation(programID, name);
	glUniform3fv(location, 1, &val[0]);
}

void ShaderProgram::Send_vec4(const char * name, glm::vec4 & val)
{
	auto location = glGetUniformLocation(programID, name);
	glUniform4fv(location, 1, &val[0]);
}

void ShaderProgram::Send_float(const char * name, float val)
{
	auto location = glGetUniformLocation(programID, name);
	glUniform1f(location, val);
}

void ShaderProgram::use()
{
	glUseProgram(programID);
}

void ShaderProgram::shutdown()
{
	glDeleteProgram(programID);
}
