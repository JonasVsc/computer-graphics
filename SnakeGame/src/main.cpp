#include"snake_game.h"

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
		player.input_rgb_controller(snake_game.window);
		
		
		glClear(GL_COLOR_BUFFER_BIT);

		// model-view-projection

		// model      -> entitys
		// view       -> *
		// projection -> *

		// model
		// -----
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(0.2, 0.2, 0.2));

		// model-location
		// --------------
		GLuint model_location = glGetUniformLocation(my_shader.program, "model");
		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

		// view
		// ----
		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		// view-location
		// -------------
		GLuint view_location = glGetUniformLocation(my_shader.program, "view");
		glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));

		// projection
		// ----------
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);

		// projection-location
		// -------------------
		GLuint projection_location = glGetUniformLocation(my_shader.program, "projection");
		glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));


		// render
		// ------
		player.set_color(my_shader.program, player.m_r, player.m_g, player.m_b);
		glUseProgram(my_shader.program);
		player.render();

		glBindVertexArray(0);

		glfwSwapBuffers(snake_game.window);
		glfwPollEvents();
	}

	return 0;
}

