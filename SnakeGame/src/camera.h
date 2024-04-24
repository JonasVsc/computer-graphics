#ifndef __CAMERA_H__
#define __CAMERA_H__

#include<GL\glew.h>
#include<GLFW\glfw3.h>

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

#include<iostream>

class camera
{
public:
	camera(GLFWwindow* window, GLuint shader_program);
	void view();
	void move();

	float delta_time = 0.0f;	// Time between current frame and last frame
	float last_frame = 0.0f; // Time of last frame

private:
	glm::vec3 m_camera_pos;
	glm::vec3 m_camera_front;
	glm::vec3 m_camera_up;
	GLuint m_shader_program;
	GLFWwindow* m_window;


};


#endif