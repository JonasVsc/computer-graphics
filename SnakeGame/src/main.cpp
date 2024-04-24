#include"application.h"
#include"shader.h"
#include"entity.h"

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>

const float SCREEN_WIDTH {1024};
const float SCREEN_HEIGHT {768};

int main()
{
	application snake_game;
	snake_game.init(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");

	shader my_shader("shaders/vertexShader.vs", "shaders/fragmentShader.fs");


	entity player;
	glClearColor(0.1f, 0.2f, 0.6f, 1.0f);

	while(!glfwWindowShouldClose(snake_game.window))
	{
		// process inputs
		// --------------
		snake_game.input_listen();

		
		glClear(GL_COLOR_BUFFER_BIT);


		// render
		// ------
		player.set_color(my_shader.program, 0.0f, 1.0f, 0.0f);
		glUseProgram(my_shader.program);
		player.render();

		glBindVertexArray(0);

		glfwSwapBuffers(snake_game.window);
		glfwPollEvents();
	}

	return 0;
}

