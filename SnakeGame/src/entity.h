#ifndef __ENTITY_H__
#define __ENTITY_H__

#include<GL\glew.h>
#include<GLFW\glfw3.h>

class entity
{
public:
	entity();
	void render();
	void set_color(GLuint &program);
	void input_rgb_controller(GLFWwindow* window);
	float m_r {};
	float m_g {};
	float m_b {};
private:
	GLuint m_vertex_array_object;
	GLuint m_vertex_buffer;
	float m_vertices[9];
};



#endif