#include"application.h"
#include<iostream>

application::application()
{
}

void application::init(int width, int height, const char *title)
{
	if(!glfwInit())
	{
		std::cerr << "ERROR glfwInit\n";
	}			

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);

	if(glewInit() != GLEW_OK)
	{
		std::cerr << "ERROR glewInit\n";
	}
}

void application::render()
{
	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}