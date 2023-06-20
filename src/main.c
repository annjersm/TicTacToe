#include <SDL2/SDL.h>
#include <stdbool.h>

#include "application.h"

int tile_size = 200;
bool turn = true;
int map[9];
int playerX = 0;
int playerO = 0;
int tie = 0;

SDL_Window* window;
SDL_Surface* wSurface;
SDL_Surface* xBmp;
SDL_Surface* oBmp;

SDL_Point mouse;
SDL_Point window_size = {800, 800};
SDL_Rect t1, t2, t3, t4, t5, t6, t7, t8, t9;

int main () {
	Log();
	App();
	return 0;
}
