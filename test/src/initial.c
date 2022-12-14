#include <SDL2/SDL.h>
#include "demo.h"

int initial(int argc, char *args[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("Unable to initialize SDL");
	
	/* Create a new Window instance */
	window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
	if (window == NULL)
		SDL_ExitWithError("Unable to create window");
	
	/* Create a new Renderer instance linked to the Window */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window); /* Destroy Window */
		SDL_ExitWithError("Unable to create renderer");
	}
	return (0);
}
