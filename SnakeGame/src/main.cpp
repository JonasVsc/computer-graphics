#include"snake_game.h"

const float SCREEN_WIDTH {1024};
const float SCREEN_HEIGHT {768};

int main()
{
	application snake_game;
	snake_game.init(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");

	shader my_shader("shaders/vertexShader.vs", "shaders/fragmentShader.fs");


	// objects
	entity player;
	entity object;

	glClearColor(0.1f, 0.2f, 0.6f, 1.0f);


	// camera init
	// -----------
	camera debug_camera(snake_game.window, my_shader.program);

	while(!glfwWindowShouldClose(snake_game.window))
	{
		// process inputs
		// --------------
		snake_game.input_listen();
		player.input_rgb_controller(snake_game.window);
		debug_camera.move();
		
		
		glClear(GL_COLOR_BUFFER_BIT);


		// view
		debug_camera.view();

		// projection
		// ----------
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);

		// projection-location
		// -------------------
		GLuint projection_location = glGetUniformLocation(my_shader.program, "projection");
		glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));


		// render player
		// ------
		player.set_color(my_shader.program);

		// model_player
		// -----
		glm::mat4 model_player = glm::mat4(1.0f);
		model_player = glm::rotate(model_player, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		model_player = glm::scale(model_player, glm::vec3(0.2, 0.2, 0.2));

		// model_player-location
		// --------------
		GLuint model_player_location = glGetUniformLocation(my_shader.program, "model");
		glUniformMatrix4fv(model_player_location, 1, GL_FALSE, glm::value_ptr(model_player));

		glUseProgram(my_shader.program);
		player.render();

		// render object
		// -------------
		object.set_color(my_shader.program);

		// model
		// -----
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.2, 0.2, 0.2));
		model = glm::translate(model, glm::vec3(2.0, -3.0, 5.0));

		// model-location
		// --------------
		GLuint model_location = glGetUniformLocation(my_shader.program, "model");
		glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

		glUseProgram(my_shader.program);
		object.render();





		glfwSwapBuffers(snake_game.window);
		glfwPollEvents();
	}

	return 0;
}

