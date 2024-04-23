#ifndef __APP_H__
#define __APP_H__

#include<GL\glew.h>
#include<GLFW\glfw3.h>

class application
{
public:
	application();
	void init(int width, int height, const char *title);
	GLFWwindow* window;
};


#endif