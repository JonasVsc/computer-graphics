#include"entity.h"


entity::entity()
{
	glGenVertexArrays(1, &m_vertex_array_object);
	glBindVertexArray(m_vertex_array_object);

	glGenBuffers(1, &m_vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer);

	m_vertices[0] = -1.0f;
	m_vertices[1] = -1.0f;
	m_vertices[2] =  0.0f;
	m_vertices[3] =  0.0f;
	m_vertices[4] =  1.0f;
	m_vertices[5] =  0.0f;
	m_vertices[6] =  1.0f;
	m_vertices[7] = -1.0f;
	m_vertices[8] =  0.0f;
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, m_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void entity::render()
{
	glBindVertexArray(m_vertex_array_object);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void entity::set_color(GLuint &program, float r, float g, float b)
{
	m_r = r;
	m_g = g;
	m_b = b;

	GLuint color_location = glGetUniformLocation(program, "color");
	glUniform3f(color_location, m_r, m_g, m_b);
}

void entity::input_rgb_controller(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS &&
		m_r <= 1)
			m_r += 0.001;
		if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS &&
		m_r >= 0)
			m_r -= 0.001;
	}
	if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	{
		if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS &&
		m_g <= 1)
			m_g += 0.001;
		if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS &&
		m_g >= 0)
			m_g -= 0.001;
	}
	if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS &&
		m_b <= 1)
			m_b += 0.001;
		if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS &&
		m_b >= 0)
			m_b -= 0.001;
	}
}