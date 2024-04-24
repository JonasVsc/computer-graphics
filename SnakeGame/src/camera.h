#ifndef __CAMERA_H__
#define __CAMERA_H__

#include<GL\glew.h>
#include<GLFW\glfw3.h>

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>


class camera
{
public:
	camera(GLFWwindow* window, GLuint shader_program, glm::vec3 pos);
	void view();
	void move();

private:
	glm::vec3 m_cameraPos;
	GLuint m_shader_program;
	GLFWwindow* m_window;


};


#endif