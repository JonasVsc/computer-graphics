#ifndef __CAMERA_H__
#define __CAMERA_H__


#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

class camera
{
public:
	camera(glm::vec3 pos);

private:
	glm::vec3 m_cameraPos;

	void view();

};


#endif