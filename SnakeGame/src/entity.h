#ifndef __ENTITY_H__
#define __ENTITY_H__

#include"glm\glm.hpp"

#include<GL\glew.h>
#include<GLFW\glfw3.h>

class entity
{
public:
	entity();
	void render();
private:
	GLuint m_vertex_array_object;
	GLuint m_vertex_buffer;
	float m_vertices[9];
};



#endif