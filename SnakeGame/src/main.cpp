#include"application.h"
#include"shader.h"

int main()
{
	application snake;
	snake.init(1024, 768, "Snake Game");

	shader my_shader("shaders/vertexShader.vs", "shaders/fragmentShader.fs");

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
	glBindBuffer(GL_ARRAY_BUFFER, player);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glClearColor(0.1f, 0.2f, 0.6f, 1.0f);

	while(!glfwWindowShouldClose(snake.window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(my_shader.program);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(snake.window);
		glfwPollEvents();
	}

	return 0;
}