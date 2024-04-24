#include"camera.h"



camera::camera(GLFWwindow* window, GLuint shader_program)
	:	m_shader_program{shader_program}
	,	m_window{window}
{
	m_camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
	m_camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
	m_camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
}


void camera::view()
{
	glm::mat4 view = glm::lookAt(m_camera_pos, m_camera_pos + m_camera_front, m_camera_up);

	GLuint view_location = glGetUniformLocation(m_shader_program, "view");
	glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
}

void camera::move()
{
	float current_frame = glfwGetTime();
	delta_time = current_frame - last_frame;
	last_frame = current_frame;  

	const float camera_speed {2.5f * delta_time};
	if(glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
		m_camera_pos += camera_speed * m_camera_front;
	if(glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
		m_camera_pos -= camera_speed * m_camera_front;
	if(glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
		m_camera_pos -= glm::normalize(glm::cross(m_camera_front, m_camera_up)) * camera_speed;
	if(glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
		m_camera_pos += glm::normalize(glm::cross(m_camera_front, m_camera_up)) * camera_speed;
	if(glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS)
		m_camera_pos += camera_speed * m_camera_up;
	if(glfwGetKey(m_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		m_camera_pos -= camera_speed * m_camera_up;


	std::cout << "(" << m_camera_pos.x << ", " << m_camera_pos.y << ", " << m_camera_pos.z << ")\n";
}