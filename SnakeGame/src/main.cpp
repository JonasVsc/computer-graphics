#include"core.h"
#include<GL\glew.h>
#include<GLFW\glfw3.h>

int main()
{

	core game;

	game.init(1024, 768, "Snake Game");

	glClearColor(0.1f, 0.2f, 0.6f, 1.0f);

	while(!glfwWindowShouldClose(game.window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(game.window);
		glfwPollEvents();
	}

	return 0;
}