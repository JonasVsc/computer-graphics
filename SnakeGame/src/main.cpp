#include"application.h"

int main()
{

	application snake;
	snake.init(1024, 768, "Snake Game");


	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	float vertices[] = {
		-0.5f, -0.5f, // bottom left
		 0.5f, -0.5f  // bottom right
		-0.5f, 	0.5f, // top left
		 0.5f,  0.5f, // top right
	};

	unsigned int indices[] = {
		0, 2, 1, // first triangle
		2, 3, 1  // second triangle
	};

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	GLuint player;
	glGenBuffers(1, &player);
	glBindBuffer(GL_VERTEX_ARRAY, player);
	glBufferData(GL_VERTEX_ARRAY, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
	glClearColor(0.1f, 0.2f, 0.6f, 1.0f);

	while(!glfwWindowShouldClose(snake.window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwSwapBuffers(snake.window);
		glfwPollEvents();
	}

	return 0;
}