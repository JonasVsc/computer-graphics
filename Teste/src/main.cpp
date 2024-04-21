#include<GLFW/glfw3.h>


int main()
{

	GLFWwindow* window;

	glfwInit();

	window = glfwCreateWindow(1024, 768, "Teste OpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);


	while(!glfwWindowShouldClose(window))
	{


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}