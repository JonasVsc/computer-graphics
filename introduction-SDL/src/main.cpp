#include<SDL3\SDL.h>
#include<stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
	SDL_Window* window = NULL;
	SDL_Surface* screen_surface = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		// Create Window
		window = SDL_CreateWindow("SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		getchar();
	}

	return 0;
}