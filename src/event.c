#include <SDL2/SDL.h>
#include <stdbool.h>

#include "brett.h"

extern SDL_Window* window;
extern SDL_Surface* wSurface;
extern SDL_Surface* xBmp;
extern SDL_Surface* oBmp;

extern SDL_Point mouse;
extern SDL_Rect t1, t2, t3, t4, t5, t6, t7, t8, t9;
extern bool turn;
extern int map[];
extern int playerX, playerO, tie;

bool event(bool t) {
	bool running = t;

	SDL_Rect tiles[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9};

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
			break;
		} else if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_m:
					printf("Map Array: ");
					for (int i = 0; i < 9; i++) {
						printf("%d", map[i]);
					}
					printf("\n");
					break;
				case SDLK_c:
					cleanBoard();
					break;
				case SDLK_s:
					printf("Player X: %d\n", playerX);
					printf("Player O: %d\n", playerO);
					printf("Tie:      %d\n", tie);
			}
		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			SDL_GetMouseState(&mouse.x, &mouse.y);
			for (int i = 0; i < 9; i++) {
				if (SDL_PointInRect(&mouse, &tiles[i])) {
					if (map[i] == 0) {
						if (turn) {
							map[i] = 1;
							//SDL_FillRect(wSurface, &tiles[i], SDL_MapRGB(wSurface->format, 20,200,20));
							SDL_BlitSurface(xBmp, NULL, wSurface, &tiles[i]);
							SDL_UpdateWindowSurface(window);
							turn = false;
							checkBrett();
							break;
						} else {
							map[i] = 2;
							//SDL_FillRect(wSurface, &tiles[i], SDL_MapRGB(wSurface->format, 200,20,20));
							SDL_BlitSurface(oBmp, NULL, wSurface, &tiles[i]);
							SDL_UpdateWindowSurface(window);
							turn = true;
							checkBrett();
							break;
						}
					}
				}
			}
		}
	}

	return running;
}
