#include "demo.h"
#include <SDL2/SDL.h>

int init_instance(SDL_Instance *instance)
{
	/* Initialie SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("Unable to initialize SDL");
	
	/* Create a new Window instance */
	instance->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
	if (instance->window == NULL)
		SDL_ExitWithError("Unable to create window");
	
	/* Create a new Renderer instance linked to the Window */
	instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		SDL_ExitWithError("Unable to create renderer");
	}
	return (0);
}

/* A function to draw a line */
void draw_stuff(SDL_Instance instance)
{
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}

int poll_events()
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				/* if 'ESCAPE' is pressed */
				if (key.keysym.scancode == 0x29)
					return (1);
				break;
		}
	}
	return (0);
}

void SDL_ExitWithError(const char *message)
{
	SDL_Log("ERROR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
