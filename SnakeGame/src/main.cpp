#include"application.h"

int main()
{

	application snake;
	snake.init(1024, 768, "Snake Game");

	glClearColor(0.1f, 0.2f, 0.6f, 1.0f);

	snake.render();

	return 0;
}