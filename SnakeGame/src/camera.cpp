#include"camera.h"



camera::camera(glm::vec3 pos)
	:	m_cameraPos(pos)
{
}


void camera::view()
{
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(m_cameraPos));

	
}