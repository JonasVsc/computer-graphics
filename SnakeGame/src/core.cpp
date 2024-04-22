#include"core.h"
#include<iostream>

core::core()
{
	std::cout << "Initializing one core\n";
}

void core::init(int width, int height, const char *title)
{
	std::cout << "STATUS Initializing Snake Game\n";

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