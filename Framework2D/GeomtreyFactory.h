#pragma once

struct GBuffer
{
	unsigned int VAO;  //vertex array object
	unsigned int VBO;  // vertex buffer object
	unsigned int CBO;  // color buffer object
	unsigned int UVBO; // uv buffer object
};

class GeomtreyFactory
{
public:
	static GBuffer GetRect();
};