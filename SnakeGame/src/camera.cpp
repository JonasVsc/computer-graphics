#include"camera.h"



camera::camera(GLFWwindow* window, GLuint shader_program, glm::vec3 pos)
	:	m_shader_program{shader_program}
	,	m_window{window}
	,	m_cameraPos{pos}
{
}


void camera::view()
{
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(m_cameraPos));

	GLuint view_location = glGetUniformLocation(m_shader_program, "view");
	glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
}

void camera::move()
{
	if(glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_cameraPos.z += 0.1;
	}
}