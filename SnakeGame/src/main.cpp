#include"application.h"
#include"shader.h"

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

const float SCREEN_WIDTH {1024};
const float SCREEN_HEIGHT {768};

int main()
{
	application snake;
	snake.init(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");

	shader my_shader("shaders/vertexShader.vs", "shaders/fragmentShader.fs");

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	float vertices[] = {
		-0.5f, -0.5f, // bottom left
		 0.5f, -0.5f,  // bottom right
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

		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0, 0.0, -1.0));
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -30.0f));

		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);

		unsigned int projection_location = glGetUniformLocation(my_shader.program, "projection");
		glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));

		unsigned int view_location = glGetUniformLocation(my_shader.program, "view");
		glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));

		unsigned int model_location = glGetUniformLocation(my_shader.program, "model");
		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

		// render
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(snake.window);
		glfwPollEvents();
	}

	return 0;
}