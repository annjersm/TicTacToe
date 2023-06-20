#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

extern SDL_Window* window;
extern SDL_Surface* wSurface;
extern SDL_Surface* xBmp;
extern SDL_Surface* oBmp;

extern SDL_Point window_size;

bool LSD_Init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Could not initialize SDL! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		window = SDL_CreateWindow(
				"Tic Tac Toe",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				window_size.x, window_size.y,
				SDL_WINDOW_SHOWN
				);
		wSurface = SDL_GetWindowSurface(window);
		xBmp = SDL_LoadBMP("res/X-200px.bmp");
		oBmp = SDL_LoadBMP("res/O-200px.bmp");

		if (window < 0) {
			printf("Could not create window! SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else if (wSurface < 0) {
			printf("Could not get the surface from the window! SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else if (xBmp < 0) {
			printf("Could not load image: res/X-200px.bmp - SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else if (oBmp < 0) {
			printf("Could not load image: res/O-200px.bmp - SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
	}
	
	return success;
}
