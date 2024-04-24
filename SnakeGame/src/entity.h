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
	void set_color(GLuint &program, float r, float g, float b);
	float m_r, m_g, m_b;
private:
	GLuint m_vertex_array_object;
	GLuint m_vertex_buffer;
	float m_vertices[9];
};



#endif