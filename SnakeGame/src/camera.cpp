#include"camera.h"



camera::camera(GLuint shader_program, glm::vec3 pos)
	:	m_shader_program{shader_program}
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

void camera::move_camera()
{
}