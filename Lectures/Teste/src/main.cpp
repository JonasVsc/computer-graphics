#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

#include<iostream>

int main()
{
	GLFWwindow* window;
	glfwInit();

	window = glfwCreateWindow(1024, 768, "Teste OpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);

	glClearColor(0.1f, 0.2f, 0.6f, 0.0f);

	glm::mat4 mat = glm::mat4(1.0f);

	std::cout << mat[0][0];

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}